#include <stdio.h>
#include "user.h"
#include "menu.h"

void Register();
void Login();
void SearchBooks();
void Display();
void BorrowBook();
void ReturnBook();
void AddBook();
void RemoveBook();

int main(int argc, char* argv[])
{
	//argv[1] book file
	//argv[2] user file
	FILE* file = fopen(argv[1], "r");
	if (load_books(file))
	{
		printf("Book file load false\n");
		exit(1);
	}
	fclose(file);
	file = fopen(argv[2], "r");
	if (load_users(file))
	{
		printf("User file load false\n");
		exit(1);
	}
	fclose(file);
	int option;
	do {
		menu_initial();
		scanf("%d", &option);
		if (option == 1) Register();
		else if (option == 2) Login();
		else if (option == 3) SearchBooks();
		else if (option == 4) Display();
	} while (option != 5);
	file = fopen(argv[1], "w");
	if (store_books(file))
	{
		printf("store book file false\n");
		exit(1);
	}
	fclose(file);
	file = fopen(argv[2], "w");
	if (store_users(file))
	{
		printf("store user file false\n");
		exit(1);
	}
	return 0;
}

void Register()
{
	char name[1024], username[1024], passward[1024];
	printf("Please input your name: ");
	fgets(name, 1024, stdin);
	printf("Please input your username: ");
	fgets(username, 1024, stdin);
	printf("Please input your passward: ");
	fgets(passward, 1024, stdin);
	User* user = GetUser(name, username, passward);
	if (add_user(*user) == 0) printf("Register Sucess!\n");
	else printf("The username already registed\n");
	DeleteUser(user);
}

void Login()
{
	char username[1024], passward[1024];
	printf("Please input your username: ");
	fgets(username, 1024, stdin);
	printf("Please input your passward: ");
	fgets(passward, 1024, stdin);
	int re = UserLogging(username, passward);
	if (re == 0) printf("There has no this username\n");
	else if (re == 1) printf("Passward Error\n");
	else if (re == 2)
	{
		int option;
		do {
			menu_user();
			scanf("%d", &option);
			if (option == 1) BorrowBook();
			else if (option == 2) ReturnBook();
			else if (option == 3) SearchBooks();
			else if (option == 4) Display();
		} while (option != 5);
	}
	else if (re == 3)
	{
		int option;
		do {
			menu_librain();
			scanf("%d", &option);
			if (option == 1) AddBook();
			else if (option == 2) RemoveBook();
			else if (option == 3) SearchBooks();
			else if (option == 4) Display();
		} while (option != 5);
	}
}

void SearchBooks()
{

}