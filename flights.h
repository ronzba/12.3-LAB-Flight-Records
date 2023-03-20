#ifndef FLIGHTS_H
#define FLIGHTS_H

#define MAX_CODE_LENGTH 4
#define MAX_FLIGHTS 200

typedef struct Flight {
    char origin[MAX_CODE_LENGTH];
    char destination[MAX_CODE_LENGTH];
    char airline[MAX_CODE_LENGTH-1];
    int passengers;
} Flight;

#endif
