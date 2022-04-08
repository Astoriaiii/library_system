#include <stdio.h>
#include "user.h"
#include "menu.h"

void Register();
void Login();
void SearchBooks();
void Display(BookList* list);
void BorrowBook(User* user);
void ReturnBook(User* user);
void AddBook();
void RemoveBook();

extern BookList* all_books;
extern UserList* all_users;

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
		else if (option == 4) Display(all_books);
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
	if(strcmp(name,"\n")==0) fgets(name, 1024, stdin);
	printf("Please input your username: ");
	fgets(username, 1024, stdin);
	printf("Please input your passward: ");
	fgets(passward, 1024, stdin);
	User* user = GetUser(name, username, passward);
	if (add_user(*user) == 0) printf("Register Success!\n");
	else printf("The username already registed\n");
	DeleteUser(user);
}

void Login()
{
	char username[1024], passward[1024];
	printf("Please input your username: ");
	fgets(username, 1024, stdin);
	if (strcmp(username, "\n") == 0) fgets(username, 1024, stdin);
	printf("Please input your passward: ");
	fgets(passward, 1024, stdin);
	//if(passward[strlen(passward)-1]=='\n') passward[strlen(passward) - 1] = '\0';
	int re = UserLogging(username, passward);
	if (re == 0) printf("There has no this username\n");
	else if (re == 1) printf("Passward Error\n");
	else if (re == 2)
	{
		int option;
		User* user = FindUser(username, passward);
		do {
			menu_user();
			scanf("%d", &option);
			if (option == 1) BorrowBook(user);
			else if (option == 2) ReturnBook(user);
			else if (option == 3) SearchBooks();
			else if (option == 4) Display(all_books);
		} while (option != 5);
	}
	else if (re == 3)
	{
		int option;
		do {
			menu_librarian();
			scanf("%d", &option);
			if (option == 1) AddBook();
			else if (option == 2) RemoveBook();
			else if (option == 3) SearchBooks();
			else if (option == 4) Display(all_books);
		} while (option != 5);
	}
}

void SearchBooks()
{
	int option;
	do {
		menu_search();
		scanf("%d", &option);
		if (option == 1)
		{
			char title[1024];
			printf("Please input the book's title: ");
			fgets(title, 1024, stdin);
			if(strcmp(title,"\n")==0) fgets(title, 1024, stdin);
			BookList list = find_book_by_title(title);
			if (list.length != 0) Display(&list);
			else printf("There is no book with title \"%s\"\n", title);
		}
		else if (option == 2)
		{
			char author[1024];
			printf("Please input the book's author: ");
			fgets(author, 1024, stdin);
			if(strcmp(author,"\n")==0) fgets(author, 1024, stdin);
			BookList list = find_book_by_author(author);
			if (list.length != 0) Display(&list);
			else printf("There is no book with author \"%s\"\n", author);
		}
		else if (option == 3)
		{
			unsigned int year;
			printf("Please input the book's year: ");
			scanf("%u", &year);
			BookList list = find_book_by_year(year);
			if (list.length != 0) Display(&list);
			else printf("There is no book with year \"%u\"\n", year);
		}
	} while (option != 4);
}

void Display(BookList* list)
{
	if (!list) return;
	if (list->length == 0) return;
	printf("id\ttitle\nauthor\tyear\tcopies\n");
	Book* p = list->list;
	while (p)
	{
		printf("%u\t%s\n%s\t\t\t\t%u\t%u\n", p->id, p->title, p->authors, p->year, p->copies);
		p = p->next;
	}
}

void BorrowBook(User* user)
{
	unsigned int id;
	printf("Please input the book's id: ");
	scanf("%d", &id);
	int re = UserBorrowBook(user, id);
	if (re == 0) printf("There is no book with id \"%u\"\n", id);
	else if (re == 1) printf("The user already has the book\n");
	else if (re == 2) printf("Borrow Success\n");
}

void ReturnBook(User* user)
{
	Display(user->borrowed_book);
	unsigned int id;
	printf("Please input the book's id: ");
	scanf("%d", &id);
	int re = UserReturnBook(user, id);
	if (re == 0) printf("There is no book with id \"%u\"\n", id);
	else if (re == 1) printf("The user had not borrow this book\n");
	else if (re == 2) printf("Return Success\n");
}

void AddBook()
{
	unsigned int id, year, copies;
	char title[1024], author[1024];
	printf("Please input the book's id: ");
	scanf("%u", &id);
	printf("Please input the book's title: ");
	fgets(title, 1024, stdin);
	if(strcmp(title,"\n")==0) fgets(title, 1024, stdin);
	printf("Please input the book's author: ");
	fgets(author, 1024, stdin);
	printf("Please input the book's year: ");
	scanf("%u", &year);
	printf("Please input the book's copies: ");
	scanf("%u", &copies);
	Book* book = GetBook(id, title, author, year, copies);
	if (add_book(*book)) printf("Add book error\n");
	else printf("Success\n");
}

void RemoveBook()
{
	unsigned int id, year, copies;
	char title[1024], author[1024];
	printf("Please input the book's id: ");
	scanf("%u", &id);
	printf("Please input the book's title: ");
	fgets(title, 1024, stdin);
	if (strcmp(title, "\n") == 0) fgets(title, 1024, stdin);
	printf("Please input the book's author: ");
	fgets(author, 1024, stdin);
	printf("Please input the book's year: ");
	scanf("%u", &year);
	printf("Please input the book's copies: ");
	scanf("%u", &copies);
	Book* book = GetBook(id, title, author, year, copies);
	if (remove_book(*book)) printf("Remove book error\n");
	else printf("Success\n");
}
