#ifndef REMINDER_H
#define REMINDER_H

#include <mysql/mysql.h>
#include "profile.h" // Assuming User structure is defined in profile.h


// New reminder management function declarations
void manageReminders(MYSQL *conn, User current_user);
void showUserReminders(MYSQL *conn, User current_user);
void createReminder(MYSQL *conn, int user_id, int task_id, const char *message, const char *status, int year, int month, int day, int hour, int minute, int second);
void updateReminder(MYSQL *conn, int reminder_id, int task_id, const char *message, const char *status, int year, int month, int day, int hour, int minute, int second);
void deleteReminder(MYSQL *conn, int reminder_id);

#endif // TASK_H