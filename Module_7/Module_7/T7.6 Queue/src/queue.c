#include "queue.h"
#include <string.h>
#include <stdlib.h>

int enqueue(struct studentqueue *q, const char *name) {
    struct studentqueue *current = q;
    
    while (current->next) {
        current = current->next;
    }

    struct studentqueue *new_student = (struct studentqueue*) malloc(sizeof(struct studentqueue));
    char* student_name = (char*) malloc((strlen(name)+1)*sizeof(char)); 
    
    if (new_student == NULL) {
        return 0;
    }

    if (student_name == NULL) {
        return 0;
    }
    
    strcpy(student_name, name);
    new_student->name = student_name;
    new_student->next = NULL;

    current->next = new_student;

    return 1;
}

int dequeue(struct studentqueue *q, char *buffer, unsigned int size) {
    if (q->next == NULL) {
        return 0;
    }
    
    struct studentqueue *first_student = q->next;

    if (strlen(first_student->name) > size) {
        return 0;
    }

    q->next = first_student->next;

    strcpy(buffer, first_student->name);

    free(first_student->name);
    free(first_student);

    return 1;

}