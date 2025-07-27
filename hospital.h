#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <mysql/mysql.h> // MySQL C API header

// --- Structures ---
// Matches the 'patients' table schema
typedef struct {
    int id;
    char first_name[51];
    char last_name[51];
    char dob[11]; // YYYY-MM-DD
    char gender[11];
    char contact_number[16];
} Patient;

// Matches the 'appointments' table schema
typedef struct {
    int id;
    int patient_id;
    char doctor_name[101];
    char appointment_date[20]; // YYYY-MM-DD HH:MI:SS
    char reason[256];
} Appointment;


// --- Function Prototypes ---

// From db_utils.c
MYSQL* db_connect();

// From patient_db.c
void add_patient(MYSQL *conn, const Patient *patient);

// From appointment_db.c
void schedule_appointment(MYSQL *conn, const Appointment *appointment);

// From search_db.c
void find_patient_by_id(MYSQL *conn, int patient_id);


#endif //HOSPITAL_H
