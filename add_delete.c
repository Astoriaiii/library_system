//
// Created by PC on 2022/3/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "book_management.h"
//#include "borrow_return.c"

//add book to book link list
int add_book (Book book) {
//printf("1");
    //Book *head_Book = (Book*)malloc(sizeof(Book));
//printf("1");
    //struct node *head_Book;
    //FILE *file = (FILE*)malloc(sizeof(FILE));
//printf("1");
    Book *p_Book = (Book*) malloc(sizeof (Book));
//printf("1");
    //Book *head_Book = (Book*)malloc(sizeof(head_Book));
    char *temp1;
    temp1 = (char*)malloc(100*sizeof(char));
    char *temp2;
    temp2 = (char*) malloc(100*sizeof(char));
    //int y;
    //int c;
    
    //p_Book->title = (char*)malloc(sizeof(p_Book->title));
//printf("1");
    printf("Enter the title of the book you wish to add:");
//printf("1");
    fflush(stdin);
    scanf("%s", temp1);
//printf("1");
    
//printf("1");.
    //if (temp.isalpha() == true)

    p_Book->title = (char *) malloc (100*sizeof(char));
    strcpy (p_Book->title, temp1);
    //free(temp1);
    
    //p_Book->authors = (char*)malloc(sizeof(p_Book->authors));
//printf("1");
    printf("Enter the author of the book you wish to add:");
//printf("1");
    //scanf("%s", p_Book->authors);
    fflush(stdin);
    scanf("%s", temp1);
    //scanf("%s", temp2);
//printf("1");
    //free(p_Book->authors);
printf("1");
    p_Book->authors = (char *) malloc (100*sizeof(char));
    strcpy(p_Book->authors, temp2);
    //free(temp);

    printf("Enter year that book released:");
    fflush(stdin);
    scanf("%s", temp1);
    p_Book->year = atoi(temp1);
printf("1");
    //int ret1;
    //ret1 = scanf("%d", &p_Book->year);
    //scanf("%d", &p_Book->year);
//printf("1");
    //if (ret1 == 0) {
        //printf("Invalid input. Please input again.\n");
        //exit(0);
    //}
    //else {
        //p_Book->year = y;
//printf("1");
    //}

    printf("Enter number of copies of the book that you wish to add:");
    fflush(stdin);
    scanf("%s", temp2);
    p_Book->copies = atoi(temp2);
    //int ret2;
printf("1");
    //ret2 = scanf("%d", &c);
    //scanf("%d", &p_Book->year);
//printf("1");
    //if (ret2 == 0) {
        //printf("Invalid input. Please input again.\n");
        //exit(0);
    //}
    //else {
        //p_Book->copies = c;
        //printf("1");
    //}

    /*if (head_Book == NULL) {
        head_Book = p_Book;
        p_Book->next = NULL;
    }
    else {
        Book * q_Book = head_Book;
        while (q_Book->next != NULL) {
            q_Book = q_Book->next;
            q_Book->next = p_Book;
        }
    }*/
printf("1");
    createNode(p_Book);
    //store_books(file, head_Book);
    return 0;
}


//delete book from book link list
/*int remove_book(Book book) {
    Book *p_Book;
    Book *q_Book;
    Book *head_Book;
    printf("Enter the id of book you prefer to delete:");
    int ret1 = scanf("%d", &q_Book->id);
    if (ret1 == 0) {
        printf("Invalid input. Please input again.");
    }
    else{
        p_Book = head_Book;
        if (head_Book == NULL) {
            printf("No more book for remove");
        }
        while (p_Book->id != q_Book->id && p_Book->next != NULL){
            p_Book = q_Book;
            p_Book = p_Book->next;
        }
        if (p_Book->id == q_Book->id){
            if (p_Book == head_Book){
                head_Book = p_Book->next;
            }
            else {
                q_Book->next = p_Book->next;
            }
            free(p_Book);
        }
    }
    return 0;
}*/

/*struct node* createBookList(){
    return createNode (NULL);
}*/

//create node for linked list
Book* createNode(Book *book) {
    //Book *p_node = (Book*) malloc (sizeof(Book));
	printf("1");
    Book *q_book = (Book*)malloc(sizeof(Book));
printf("2");
    if (q_book != NULL){
        if (book != NULL) {
            //q_book = &(p_node->Book);
printf("3");
            q_book->id = book->id;
printf("4");
            strcpy(q_book->title, book->title);
printf("5");
            strcpy(q_book->authors, book->authors);
printf("6");
            q_book->year = book->year;
printf("7");
            q_book->copies = book->copies;
        }
        q_book->next = NULL;
printf("8");
    }
printf("9");
    return q_book;
}

//add node to linked list
Book* add_node(Book* head_node, Book *book) {
    if (head_node != NULL) {
        Book* p_book = createNode(book);
        //printf(p_book);
        //Book *q_book = (Book*)malloc(sizeof(Book));
        //strcpy(q_book->title, book->title);
        //strcpy(q_book->authors, book->authors);
        //q_book->year = book->year;
        //q_book->copies = book->copies;
        if (p_book != NULL) {
            Book *q_book = head_node;
            while (q_book->next !=NULL)
                q_book = q_book->next;
            q_book->next = p_book;
            return p_book;
        }
    }
    return NULL;
}

/*void display_book(){
    Book *temp_Book;
    //Book *head_Book;
    while (temp_Book) {
        printf("%d %s %s %d %d", temp_Book->id, temp_Book->title, temp_Book->authors, temp_Book->year, temp_Book->copies);
        temp_Book = temp_Book->next;
    }
}*/



