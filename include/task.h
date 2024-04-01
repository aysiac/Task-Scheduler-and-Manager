#ifndef TASK_H
#define TASK_H

#include <mysql/mysql.h> // Include the MySQL definitions
#include <stdbool.h>     // For `bool` type

// Assuming User is defined in profile.h
#include "profile.h"
#include "database.h"
#include "reminder.h"
#include <ctype.h>

typedef struct {
    int task_id;
    char task_name[101];
    char description[201];
    char task_duration[9];  // "HH:MM:SS"
    char priority[7];       // e.g., "low", "medium", "high"
    int user_id;
    bool complete;
} Task;

void createTaskForm(MYSQL *conn, User current_user);
void manageTask(MYSQL *conn, User current_user);
void updateTaskForm(MYSQL *conn, Task task, User current_user);
void deleteTaskByID(MYSQL *conn, Task task, User current_user);
bool validateTaskID(MYSQL *conn, User current_user, int taskID);
int fetchTaskById(MYSQL *conn, User current_user, Task *task);
void printCategories(MYSQL *conn);
void showUserTasks(MYSQL *conn, User current_user);


#endif // TASK_H