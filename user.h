#ifndef USER_C
#define USER_C

#include <stdio.h>
#include "book_management.h"

#define SPECIAL_USER "librarian\n"
#define PASSWARD "librarian\n"

typedef struct _User {
	char* name; //name
	char* username; //username
	char* passward; //passward
	BookList* borrowed_book; //user's borrowed book
	struct _User* next; //pointer to the next user
}User;

typedef struct _UserList {
	User* list; // pointer to a list of struct User.
	unsigned int length; // number of elements in the (User*) List 
}UserList;

//catch user information 
User* GetUser(char* name, char* username, char* passward);

//form linked list of user
UserList* GetUserList();

//copy user information temporarily for future manipulation
User* CopyUser(User copy);

//release space of user
void DeleteUser(User* user);

//initialize the user information file
void DeleteUserList(UserList* list);

//store user information in linked list to files
int store_users(FILE* file);

//load user information from file to linked list of user
int load_users(FILE* file);

//add_user to user linked list
int add_user(User user);

//remove user from linked list
int remove_user(User user);

//check if the user is in the list
int HasUser(char* username);

//allow users to log in
//return 0 if no username, 1 if wrong passward, 2 if common user, 3 if special user
int UserLogging(char* username, char* passward);

//allow users to borrow book
//return 0 if no this book, 1 if the user already had the book, 2 if sucess
int UserBorrowBook(User* user, unsigned int id);

//allow users to return book
//return 0 if no this book, 1 if the user had not borrow this book, 2 if sucess
int UserReturnBook(User* user, unsigned int id);

User* FindUser(char* username, char* passward);

#endif
