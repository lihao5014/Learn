#ifndef _LOGIN_VIEW_H
#define _LOGIN_VIEW_H

#define LENGTH 32

typedef struct LoginView_t
{
	char usernameLabel[LENGTH];
	char passworLabel[LENGTH];
	char username[LENGTH];
	char password[LENGTH];
}LoginView;

void setUsername(LoginView *this,const char* username);
const char* getUsername(LoginView *this);

void setPassword(LoginView *this,const char password[]);
const char* getPassword(LoginView *this);

#endif //_LOGIN_VIEW_H