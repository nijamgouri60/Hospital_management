// search_db.c
#include <stdio.h>
#include "hospital.h"

void find_patient_by_id(MYSQL *conn, int patient_id) {
    char query[256];
    sprintf(query, "SELECT patient_id, first_name, last_name, dob, gender, contact_number FROM patients WHERE patient_id = %d", patient_id);

    // Execute the query
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Search failed: %s\n", mysql_error(conn));
        return;
    }

    // Store the result set
    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        fprintf(stderr, "mysql_store_result failed: %s\n", mysql_error(conn));
        return;
    }

    // Fetch the row
    MYSQL_ROW row;
    if ((row = mysql_fetch_row(result))) {
        printf("\n--- Patient Found ---\n");
        printf("  ID: %s\n", row[0]);
        printf("  Name: %s %s\n", row[1], row[2]);
        printf("  Date of Birth: %s\n", row[3]);
        printf("  Gender: %s\n", row[4]);
        printf("  Contact: %s\n", row[5]);
        printf("---------------------\n");
    } else {
        printf("❌ Patient with ID %d not found.\n", patient_id);
    }

    // IMPORTANT: Free the result set to prevent memory leaks
    mysql_free_result(result);
}
