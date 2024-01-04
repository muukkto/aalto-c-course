#ifndef _PROJECT__H_
#define _PROJECT__H_
#include <stdio.h>

typedef struct {
	char* lastname;
	char* team;
    int hrs;
    int min;
    int sec;
} Driver;

typedef struct {
	Driver* drivers;
    int num_drivers;
} Database;

int compare_times (const void * a, const void * b);

int compare_names (const void* key, const void* elem);

Driver* search_driver (Database* db, char* name);

int add_driver(Database* db, char* inp_name, char* inp_team);

int update_time (Database* db, char* name, int add_hrs, int add_mins, int add_secs);

int print_standings(Database* db, FILE* stream);

int import_standings(Database* db, char* filename);

void reset_db(Database* db);

int free_db(Database* db);

#endif //! _PROJECT__H_