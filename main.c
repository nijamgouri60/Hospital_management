// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hospital.h"

void show_menu() {
    printf("\n--- Hospital Management System ---\n");
    printf("1. Add New Patient\n");
    printf("2. Schedule Appointment\n");
    printf("3. Find Patient by ID\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    MYSQL *conn = db_connect(); // Connect to the database
    int choice;

    do {
        show_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Patient new_patient;
                printf("Enter First Name: ");
                scanf("%s", new_patient.first_name);
                printf("Enter Last Name: ");
                scanf("%s", new_patient.last_name);
                printf("Enter DOB (YYYY-MM-DD): ");
                scanf("%s", new_patient.dob);
                printf("Enter Gender: ");
                scanf("%s", new_patient.gender);
                printf("Enter Contact Number: ");
                scanf("%s", new_patient.contact_number);
                
                add_patient(conn, &new_patient);
                break;
            }
            case 2: {
                Appointment new_appointment;
                printf("Enter Patient ID to schedule for: ");
                scanf("%d", &new_appointment.patient_id);
                printf("Enter Doctor Name: ");
                scanf(" %[^\n]", new_appointment.doctor_name);
                printf("Enter Appointment Date (YYYY-MM-DD HH:MI:SS): ");
                scanf(" %[^\n]", new_appointment.appointment_date);
                printf("Enter Reason for Appointment: ");
                scanf(" %[^\n]", new_appointment.reason);
                
                schedule_appointment(conn, &new_appointment);
                break;
            }
            case 3: {
                int patient_id;
                printf("Enter Patient ID to search for: ");
                scanf("%d", &patient_id);
                find_patient_by_id(conn, patient_id);
                break;
            }
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    mysql_close(conn); // Close the database connection
    return 0;
}
