#ifndef MENU_C
#define MENU_C#include <stdio.h>
#include "book_management.h"

//Initially list when user open the project
void menu_initial(){
	printf("Please choose an option:\n");
	printf("1) Register an account\n");
	printf("2) Login\n");
	printf("3) Search for books\n");
	printf("4) Display all books\n");
	printf("5) Quit\n");
	printf(" Option:\n");
}

//Menu displayed for librarian to operate books
void menu_librarian(){
	printf("Please choose an option:\n");
	printf("1) Add a book\n");
	printf("2) Remove a book\n");
	printf("3) Search for books\n");
	printf("4) Display all books\n");
	printf("5) Log out\n");
	printf(" Option:\n");
}

//Menu displayed for user to operate books
void menu_user() {
    printf("Please choose an option:\n");
    printf("1) Borrow a book\n");
    printf("2) Return a book\n");
    printf("3) Search for books\n");
    printf("4) Display all books\n");
    printf("5) Log out\n");
    printf(" Option:\n");
}

//Menu displayed for search books
/* void menu_search() {
    printf("1) search by title\n");
    printf("2) search by author\n");
    printf("3) search by year\n");
    printf("4) Quit\n");
    printf(" Option:\n");
}*/

#endif
