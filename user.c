#include "user.h"
#include <string.h>

//catch user information 
User* GetUser(char* name, char* username, char* passward)
{
	User* user = (User*)malloc(sizeof(User));
	user->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(user->name, name);
	user->username = (char*)malloc(sizeof(char) * (strlen(username) + 1));
	strcpy(user->username, username);
	user->passward = (char*)malloc(sizeof(char) * (strlen(passward) + 1));
	strcpy(user->passward, passward);
	user->borrowed_book = GetBookList();
	return user;
}


//form linked list of user
UserList* GetUserList()
{
	UserList* list = (UserList*)malloc(sizeof(UserList));
	list->list = NULL;
	list->length = 0;
	return list;
}

//store user information in linked list to files
int store_users(FILE* file)
{
	if (!file) return 1;
	fprintf(file, "%u\n", all_users->length);
	int i = 0;
	User* p = all_users->list;
	for (; i < all_users->length; i++, p = p->next)
	{
		fprintf(file, "%s\n", p->name);
		fprintf(file, "%s\n", p->username);
		fprintf(file, "%s\n", p->passward);
	}
	return 0;
}

//load user information from file to linked list of user
int load_users(FILE* file)
{
	if (!file) return 1;
	DeleteUserList(all_users);
	if (!all_users) all_users = GetUserList();
	fscanf(file, "%u", &all_users->length);
	char name[1024], username[1024], passward[1024];
	int i = 0;
	User* p = NULL;
	for (; i < all_users->length; i++)
	{
		fgets(name, 1024, file);
		fgets(username, 1024, file);
		fgets(passward, 1024, file);
		User* tmp_book = GetUser(name,username,passward);
		if (p == NULL) all_users->list = tmp_book;
		else p->next = tmp_book;
		p = tmp_book;
	}
	return 0;
}

//copy user information temporarily for future manipulation
User* CopyUser(User copy)
{
	User* user = (User*)malloc(sizeof(User));
	user->name = (char*)malloc(sizeof(char) * (strlen(copy.name) + 1));
	strcpy(user->name, copy.name);
	user->username = (char*)malloc(sizeof(char) * (strlen(copy.username) + 1));
	strcpy(user->username, copy.username);
	user->passward = (char*)malloc(sizeof(char) * (strlen(copy.passward) + 1));
	strcpy(user->passward, copy.passward);
	return user;
}

//add_user to user linked list
int add_user(User user)
{
	if (!all_users) all_users = GetUserList();
	int i = 0;
	User* p = all_users->list;
	for (; i < all_users->length; i++, p = p->next)
	{
		if (strcmp(user.username,p->username)==0) return 1;
	}
	User* tmp_user = CopyUser(user);
	p->next = tmp_user;
	all_users->length++;
	return 0;
}

//release space of user
void DeleteUser(User* user)
{
	free(user->name);
	free(user->username);
	free(user->passward);
	free(user);
}

//initialize the user information file
void DeleteUserList(UserList* list)
{
	if (!list) return;
	User* p = list->list;
	User* next = NULL;
	while (p)
	{
		next = p->next;
		DeleteUser(p);
		p = next;
	}
	list->length = 0;
	list->list = NULL;
}

//remove user from linked list
int remove_user(User user)
{
	if (!all_users) return 1;
	int i = 0;
	User* p = all_users->list;
	User* target = NULL;
	User* father = NULL;
	for (; i < all_users->length; i++, p = p->next)
	{
		if (strcmp(user.username,p->username)==0)
		{
			target = p;
			break;
		}
		father = p;
	}
	if (target == NULL) return 1;
	if (all_users->list == target) all_users->list = target->next;
	else father->next = target->next;
	all_users->length--;
	DeleteUser(target);
	return 0;
}

//check if the user is in the list
int HasUser(char* username)
{
	if (!all_users) return 0;
	User* p = all_users->list;
	while (p)
	{
		if (strcmp(p->username, username) == 0) return 1;
		p = p->next;
	}
	return 0;
}

//allow user to login
int UserLogging(char* username, char* passward)
{
	if (strcmp(username, SPECIAL_USER) == 0 && strcmp(passward, PASSWARD) == 0) return 3;
	if (HasUser(username) == 0) return 0;
	User* p = all_users->list;
	while (p)
	{
		if (strcmp(p->username, username) == 0)
		{
			if (strcmp(p->passward, passward) == 0) return 2;
			else return 1;
		}
		p = p->next;
	}
	return 0;
}

//allow user to borrow book by id
int BorrowBook(User* user, unsigned int id)
{
	Book* book = find_book_by_id(id);
	if (!book) return 0;
	if (user->borrowed_book->length > 0)
	{
		Book* p = user->borrowed_book->list;
		int i = 0;
		int flag = 0;
		for (; i < user->borrowed_book->length; i++, p = p->next)
		{
			if (p->id == book->id)
			{
				flag = 1;
				break;
			}
		}
		if (!flag) return 1;
		Book* tmp_book = CopyBook(*book);
		Book* p = user->borrowed_book->list;
		while (p->next) p = p->next;
		p->next = tmp_book;
		user->borrowed_book->length++;
	}
	else
	{
		Book* tmp_book = CopyBook(*book);
		user->borrowed_book->list = tmp_book;
		user->borrowed_book->length++;
	}
	return 2;
}

//allow user to return book by id
int ReturnBook(User* user, unsigned int id)
{
	Book* book = find_book_by_id(id);
	if (!book) return 0;
	if (user->borrowed_book->length == 0) return 1;
	Book* p = user->borrowed_book->list;
	Book* target = NULL;
	Book* father = NULL;
	int i = 0;
	for (; i < user->borrowed_book->length; i++, p = p->next)
	{
		if (p->id == id)
		{
			target = p;
			break;
		}
		father = p;
	}
	if (target == NULL) return 1;
	if (user->borrowed_book->list == target) user->borrowed_book->list = target->next;
	else father->next = target->next;
	user->borrowed_book->length--;
	DeleteBook(target);
	return 2;
}
