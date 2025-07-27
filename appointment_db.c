// appointment_db.c
#include <stdio.h>
#include "hospital.h"

void schedule_appointment(MYSQL *conn, const Appointment *appointment) {
    char query[512];

    // Format the SQL INSERT query.
    // For production code, always prefer prepared statements to prevent SQL injection.
    sprintf(query, "INSERT INTO appointments(patient_id, doctor_name, appointment_date, reason) VALUES(%d, '%s', '%s', '%s')",
            appointment->patient_id,
            appointment->doctor_name,
            appointment->appointment_date,
            appointment->reason);

    // Execute the query
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Appointment scheduling failed: %s\n", mysql_error(conn));
        return;
    }

    printf("✅ Appointment scheduled successfully!\n");
}
