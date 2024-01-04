#include "project.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int compare_times (const void * a, const void * b) {
    Driver *driver_a = (Driver*) a;
    Driver *driver_b = (Driver*) b;

    int driver_a_time_sec = driver_a->hrs*60*60+driver_a->min*60+driver_a->sec;
    int driver_b_time_sec = driver_b->hrs*60*60+driver_b->min*60+driver_b->sec;

    if (driver_a_time_sec < driver_b_time_sec) {
        return -1;
    } else if (driver_a_time_sec == driver_b_time_sec) {
        return 0;
    } else {
        return 1;
    }
}

int compare_names (const void* key, const void* elem) {
    Driver* driver_a = (Driver*) key;
    Driver* driver_b = (Driver*) elem;
    return strcmp (driver_a->lastname, driver_b->lastname);
}

Driver* search_driver (Database* db, char* name) {
    Driver *arr_to_sort = (Driver*) calloc(db->num_drivers, sizeof(Driver));
    memcpy(arr_to_sort, db->drivers, db->num_drivers*sizeof(Driver));
    Driver *key_driver = (Driver*) calloc(1, sizeof(Driver));
    key_driver->lastname = (char*) malloc((strlen(name)+1)*sizeof(char));
    strcpy(key_driver->lastname, name);
    qsort(arr_to_sort, db->num_drivers, sizeof(Driver), compare_names);
    Driver* found = bsearch(key_driver, arr_to_sort, db->num_drivers, sizeof(Driver), compare_names);
    free(key_driver->lastname);
    free(key_driver);
    free(db->drivers);
    db->drivers = arr_to_sort;
    return found;
}

int add_driver(Database* db, char* inp_name, char* inp_team) {
    if (search_driver(db, inp_name)) {
        printf("ERROR: Driver %s already in database\n", inp_name);
        return 0;
    }

    int i = db->num_drivers;
    Driver *upd_arr = calloc(i+1, sizeof(Driver));
    memcpy(upd_arr, db->drivers, i*sizeof(Driver));
    free(db->drivers);
    upd_arr[i].team = (char*) malloc((strlen(inp_team)+1)*sizeof(char));
    upd_arr[i].lastname = (char*) malloc((strlen(inp_name)+1)*sizeof(char));
    strcpy(upd_arr[i].lastname, inp_name);
    strcpy(upd_arr[i].team, inp_team);
    upd_arr[i].hrs = 0;
    upd_arr[i].min = 0;
    upd_arr[i].sec = 0;
    db->drivers = upd_arr;
    db->num_drivers++;

    return 1;
}

int print_standings(Database* db, FILE* stream) {
    Driver *arr_to_sort = (Driver*) calloc(db->num_drivers, sizeof(Driver));
    memcpy(arr_to_sort, db->drivers, db->num_drivers*sizeof(Driver));
    qsort(arr_to_sort, db->num_drivers, sizeof(Driver), compare_times);

    for (int i = 0; i < db->num_drivers; i++) {
        Driver cur = arr_to_sort[i];
        fprintf(stream, "%s %s %i %i %i\n", cur.lastname, cur.team, cur.hrs, cur.min, cur.sec);
    }

    free(arr_to_sort);
    return 1;
}

void reset_db(Database* db) {
    for (int i = 0; i < db->num_drivers; i++) {
        free(db->drivers[i].lastname);
        free(db->drivers[i].team);
    }
    db->num_drivers = 0;
}

int free_db(Database* db) {
    reset_db(db);
    free(db->drivers);
    free(db);
    return 1;
}

int update_time (Database* db, char* name, int add_hrs, int add_mins, int add_secs) {
    Driver *driver = search_driver(db, name);
    if (!driver) {
        printf("ERROR: No driver found in database\n");
        return 0;
    }

    if (add_mins < 0 || add_mins > 59) {
        printf("ERROR: Minutes must be a value between 0 and 59\n");
        return 0;
    }

    if (add_secs < 0 || add_secs > 59) {
        printf("ERROR: Seconds must be a value between 0 and 59\n");
        return 0;
    }

    if (add_hrs < 0) {
        printf("ERROR: Hours cannot be a negative value\n");
        return 0;
    }
    
    if (driver->sec + add_secs >= 60) {
        add_mins++;
        driver->sec = driver->sec + add_secs - 60;
    } else {
        driver->sec = driver->sec + add_secs;
    }

    if (driver->min + add_mins >= 60) {
        add_hrs++;
        driver->min = driver->min + add_mins - 60;
    } else {
        driver->min = driver->min + add_mins;
    }

    driver->hrs = driver->hrs + add_hrs;

    return 1;
}

int import_standings(Database* db, char* filename) {
    FILE *stream = fopen(filename, "r");
    if (!stream) {
        printf("ERROR: Cannot open file %s\n", filename);
        return 0;
    }

    reset_db(db);

    while (1) {
        char name[100];
        char team[100];
        int hrs;
        int mins;
        int secs;
        int read_status = fscanf(stream, "%s %s %i %i %i\n", name, team, &hrs, &mins, &secs);
        if (read_status == -1) {
            break;
        }
        add_driver(db, name, team);
        update_time(db, name, hrs, mins, secs);
    }

    fclose(stream);
    return 1;
}

int main(void) {
    Database* db = calloc(1, sizeof(Database));
    db->num_drivers = 0;

    while (1) {
        char buffer[1000];
        int quit = 0;
        int success = 0;
        int args;
        fgets(buffer, 1000, stdin);
        
        switch (buffer[0]) {
        case 'A': ;
            char name[100];
            char team[100];
            args = sscanf(buffer, "A %s %s", name, team);
            if (args == 2) {
                success = add_driver(db, name, team);
            } else {
                printf("ERROR: Wrong number of arguments - should be 2\n");
                success = 0;
            }
            break;
        
        case 'U': ;
            char search_name[100];
            int hour;
            int min;
            int sec;
            args = sscanf(buffer, "U %s %i %i %i", search_name, &hour, &min, &sec);
            if (args == 4) {
                success = update_time(db, search_name, hour, min, sec);
            } else {
                printf("ERROR: Wrong number of arguments - should be 4\n");
                success = 0;
            }
            break;
        
        case 'L':
            success = print_standings(db, stdout);
            break;

        case 'W': ;
            char write_filename[100];
            sscanf(buffer, "W %s", write_filename);
            FILE* file = fopen(write_filename, "w");
            success = print_standings(db, file);
            fclose(file);
            break;
        
        case 'O': ;
            char read_filename[100];
            sscanf(buffer, "O %s\n", read_filename);
            success = import_standings(db, read_filename);
            break;
        
        case 'Q':
            success = free_db(db);
            quit = 1;
            break;

        default:
            printf("Invalid command %c\n", buffer[0]);
        }

        if (success) {
            printf("SUCCESS\n");
        }

        if (quit) {
            break;
        }
    }
}