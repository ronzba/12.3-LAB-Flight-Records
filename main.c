#include <stdio.h>
#include <stdlib.h>
#include "flights.h"

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc != 2) {
        printf("ERROR NO ARGS\n");
        return 1;
    }

    // Open file
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("ERROR FILE NOT OPEN\n");
        return 1;
    }

    // Allocate memory for flights array
    Flight *flights = malloc(sizeof(Flight) * MAX_FLIGHTS);

    // Read and parse CSV into flights array
    char line[100];
    int num_flights = 0;
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%3s,%3s,%2s,%d", flights[num_flights].origin, flights[num_flights].destination,
               flights[num_flights].airline, &flights[num_flights].passengers);
        num_flights++;
    }

    // Prompt user for airline code and count flights/passengers
    char airline_code[MAX_CODE_LENGTH-1];
    printf("Enter a two-letter airline code: ");
    scanf("%2s", airline_code);
    int num_airline_flights = 0;
    int total_airline_passengers = 0;
    int i;
    for (i = 0; i < num_flights; i++) {
        if (strcmp(flights[i].airline, airline_code) == 0) {
            num_airline_flights++;
            total_airline_passengers += flights[i].passengers;
        }
    }

    // Print summary statistics
    printf("airline: %s\n", airline_code);
    printf("flights: %d\n", num_airline_flights);
    printf("passengers: %d\n", total_airline_passengers);

    // Clean up and exit
    fclose(file);
    free(flights);
    return 0;
}

