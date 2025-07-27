// patient_db.c
#include <stdio.h>
#include "hospital.h"

void add_patient(MYSQL *conn, const Patient *patient) {
    char query[512];

    // Create the SQL INSERT query
    // NOTE: For production, use prepared statements to prevent SQL injection!
    sprintf(query, "INSERT INTO patients(first_name, last_name, dob, gender, contact_number) VALUES('%s', '%s', '%s', '%s', '%s')",
            patient->first_name,
            patient->last_name,
            patient->dob,
            patient->gender,
            patient->contact_number);

    // Execute the query
    if (mysql_query(conn, query)) {
        fprintf(stderr, "INSERT failed: %s\n", mysql_error(conn));
        return;
    }

    printf("New patient added successfully with ID: %llu\n", mysql_insert_id(conn));
}
