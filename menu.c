#include<stdio.h>

void menu_initial(){
	int initial_option;
	printf("Please choose an option:")
	printf("1) Register an account");
	printf("2) Login");
	printf("3) Search for books");
	printf("4) Display all books");
	printf("5) Quit");
	printf(" Option:");
	scanf("%d", initial_option);
}

void menu_librarian(){
	int librarian_option;
	printf("Please choose an option:")
	printf("1) Register an account");
	printf("2) Login");
	printf("3) Search for books");
	printf("4) Display all books");
	printf("5) Log out");
	printf(" Option:");
	scanf("%d", librarian_option);
}

void menu_user(){
	int user_option;
	printf("Please choose an option:")
	printf("1) Borrow a book");
	printf("2) Return a book");
	printf("3) Search for books");
	printf("4) Display all books");
	printf("5) Log out");
	printf(" Option:");
	scanf("%d", user_option);
}
