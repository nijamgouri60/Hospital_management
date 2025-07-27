// db_utils.c
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h> 
#include "hospital.h"

// Database credentials
static const char *DB_HOST = "localhost";
static const char *DB_USER = "hospital_user";     // Use root
static const char *DB_PASS = NULL;       // No password
static const char *DB_NAME = "hospital_db";

MYSQL* db_connect() {
    MYSQL *conn = mysql_init(NULL);

    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(EXIT_FAILURE);
    }

    // Connect as root with no password
    if (mysql_real_connect(conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(EXIT_FAILURE);
    }

    printf("Database connection successful!\n");
    return conn;
}
