//
// Created by PC on 2022/3/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"
//#include "add_delete.c"

//create linked list for book
//Booklist Book* createBookList(){
    //return createNode(NULL);
//}

// find book according to book title
BookList find_book_by_title (const char *title) {
    BookList title_list;
    Book *head_Book;
    Book *title_Book = head_Book->next;
    //set p_node for traverse link list
    //struct Book *p_Book = head_book;
    //Book* list = createBookList();
    //Book* head_Book = aList.list;
    //Book* head_book = (Book*)malloc(sizeof(Book));
    //Book* head_book;
    //head_Book->next =(Book*)malloc(sizeof(Book));
    //Book *p_Book;
    //p_Book = (Book*)malloc(sizeof(Book));
    //head_Book->next = p_Book;
    ////head_book = (Book*)malloc(sizeof(Book));
    //head_book = p_Book;
    int index = 0;
    while (title_Book != NULL) {
        //set condition of equality
        if (strcmp(title_Book->title, title) == 0){
            //add_node(head_Book, p_Book);
            printf ("ID\tTitle\tAuthor\tYear\tCopies\t");
            printf("%d\t%s\t%s\t%d\t%d\t", title_Book->id, title_Book->title, title_Book->authors, title_Book->year, title_Book->copies);
            index ++;
        }
        //if (index > 0){
            //break;
       // }
        title_Book = title_Book->next;
    }
    /*if (index == 0){
        aList.list = NULL;
        aList.length = 0;
        printf("The book you are searching is not existing or available!");
    }*/
    return title_list;
}

// find book according to the author of book
BookList find_book_by_author (const char *author) {
//printf("1");
    BookList author_list;
    Book *head_Book = (Book*)malloc(sizeof(Book));
    Book *author_Book = head_Book->next;
    //struct Book *p_Book = head_book;
    //Book* head_book;
    //Book* p_Book;
    //head_book = (Book*)malloc(sizeof(Book));
    //head_book = p_Book;
    int index = 0;
    while (author_Book->next !=NULL) {
	//printf("%s %s\n", author,author_Book ->authors);
        if (strcmp(author_Book->authors, author) == 0){
            printf ("ID\tTitle\tAuthor\tYear\tCopies\t");
            printf("%d\t%s\t%s\t%d\t%d\t", author_Book->id, author_Book->title, author_Book->authors, author_Book->year, author_Book->copies);
            index ++;
        }
       // if (index > 0){
            //break;
        //}
        author_Book = author_Book->next;
    }
    if (index == 0){
        printf("The book you are searching is not existing or available!\n");
    }
    return author_list;
}

//find book according to the year when book published
BookList find_book_by_year (unsigned int year) {
    BookList year_list;
    Book *head_Book = (Book*)malloc(sizeof(Book));
    Book *year_Book = head_Book->next;
    //struct Book *p_Book = head_book;
    //Book* head_book;
    //Book* p_Book;
    //head_Book = (Book*)malloc(sizeof(Book));
    //head_Book = p_Book;
    int index = 0;
    while (year_Book) {
        if (year_Book->year == year){
            printf ("ID\tTitle\tAuthor\tYear\tCopies\t");
            printf("%d\t%s\t%s\t%d\t%d\t", year_Book->id, year_Book->title, year_Book->authors, year_Book->year, year_Book->copies);
            index ++;
        }
        //if (index > 0){
            //break;
        //}
        year_Book = year_Book->next;
    }
    if (index == 0){
        printf("The book you are searching is not existing or available!\n");
    }
    return year_list;
}


//Menu displayed for search books
void menu_search() {
    printf("1) search by title\n");
    printf("2) search by author\n");
    printf("3) search by year\n");
    printf("4) Quit\n");
    printf(" Option:\n");
}

void search(){
    char option = '1';
    char *title_search, *author_search;
    int year_search;
    while (option != '4'){
            int count = 0;
            menu_search();
            scanf("%c", &option);
	    /*while (getchar()!=0){
		count++;
            }
	    if(count>0){
		printf("Invalid option. PLease try again.\n");
		continue;
	    }
            else{
		break;
	    }*/
	switch (option) {
	    case '1':
		title_search = (char*)malloc(100*sizeof(char));
		printf("Please enter the title you want to search:");
		scanf("%s", title_search);
		find_book_by_title (title_search);
		break;
	    case '2':
		author_search = (char*)malloc(100*sizeof(char));
		printf("Please enter the author you want to search:");
		scanf("%s", author_search);
		find_book_by_author (author_search);
		break;
	    case '3':
		//year_search = (int*)malloc(sizeof(int)):
		printf("Please enter the year you want to search:");
		scanf("%d", &year_search);
		find_book_by_year (year_search);
		break;
	    case '4':
		break;
	    default:
		printf("Invalid option. Please try again.\n");
		break;
	}
    }
}
