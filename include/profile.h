#ifndef PROFILE_H
#define PROFILE_H

#include <mysql/mysql.h> 
#include "database.h"
#include <ctype.h>

typedef struct {
    int user_id;
    char name[50];
    char username[200];
    char password[15];
    char dob[20];
    char phone[15];
    char email[200];
} User;

//User current_user;
extern User current_user;

void createUserProfile(MYSQL *conn);
void signIn(MYSQL *conn);
void secondMenu(User current_user, MYSQL *conn);
int userAuthentication(MYSQL *conn, const char *username, const char *password);
void manageProfile(MYSQL *conn, User current_user);
void updateUsername(MYSQL *conn, User current_user);
void updateName(MYSQL *conn, User current_user);
void updatePassword(MYSQL *conn, User current_user);
void updateDOB(MYSQL *conn, User current_user);
void updatePhoneNum(MYSQL *conn, User current_user);
void updateEmail(MYSQL *conn, User current_user);
void deleteProfile(MYSQL *conn, User current_user);
int isUsernameUnique(MYSQL *conn, const char *username);
int isEmailUsed(char *email);
bool dateFormatValid(char *date);
bool phoneNumberValid(const char *phoneNumber);
bool timeFormatValid(const char *time);
void exitProgram();  
#endif // PROFILE_H