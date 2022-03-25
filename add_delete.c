//
// Created by PC on 2022/3/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"
#include "borrow_return.c"

int add_book (Book book) {
    Book *p_Book = (Book*) malloc(sizeof (p_Book));
    char temp[100];

    printf("Enter the title of the book you wish to add:");
    scanf("%s", temp);
    //if (temp.isalpha() == true)

    p_Book->title = (char *) malloc (sizeof(strlen(temp)));
    strcpy (p_Book->title, &temp);

    printf("Enter the author of the book you wish to add:");
    scanf("%s", temp);
    p_Book->authors = (char *) malloc (sizeof(strlen(temp)));
    strcpy(p_Book->authors, &temp);

    printf("Enter year that book released:");
    int ret1;
    ret1 = scanf("%d", &p_Book->year);
    if (ret1 == 0) {
        printf("Invalid input. Please input again.");
        exit(0);
    }
    else {
        p_Book->year = p_Book->year;
    }

    printf("Enter number of copies of the book that you wish to add:");
    int ret2;
    ret2 = scanf("%d", &p_Book->copies);
    if (ret2 == 0) {
        printf("Invalid input. Please input again.");
        exit(0);
    }
    else {
        p_Book->copies = p_Book->copies;
    }

    if (head_Book == NULL) {
        head_Book = p_Book;
        p_Book->next = NULL;
    }
    else {
        Book * q_Book = head_Book;
        while (q_Book->next != NULL) {
            q_Book = q_Book->next;
            q_Book->next = p_Book;
        }
    }
    return 0;
}

int remove_book(Book book) {
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
}

struct node* createBookList(){
    return createNode (NULL);
}

/*void display_book(){
    Book *temp_Book;
    //Book *head_Book;
    while (temp_Book) {
        printf("%d %s %s %d %d", temp_Book->id, temp_Book->title, temp_Book->authors, temp_Book->year, temp_Book->copies);
        temp_Book = temp_Book->next;
    }
}*/



