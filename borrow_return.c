//
// Created by PC on 2022/3/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"

/*void add_node() {
    Book *head_Book;
    Book *p_Book;
    Book *q_Book;
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
}
*/
struct node* createNode(Book *book) {
    node *p_node = (struct node*) calloc (1, sizeof(struct node));
    Book *q_book;
    if (p_node != NULL){
        if (book != NULL) {
            q_book = &(p_node->book);
            q_book->id = book->id;
            strcpy(q_book->title, book->title);
            strcpy(q_book->authors, book->authors);
            q_book->year = book->id;
            q_book->copies = book->copies;
        }
        p_node->next = NULL;
    }
    return p_node;
};


struct node* add_node( node* head_node, Book *book) {
    if (head_node != NULL) {
        struct node* p_node = createNode(book);
        Book *q_book = &(p_node->book);
        if (p_node != NULL) {
            node *q_node = head_node;
            while (q_node->next !=NULL)
                q_node = q_node->next;
            q_node->next = p_node;
            return p_node;
        }
    }
    return NULL;
}

void delete_node() {
    Book *p_Book;
    Book *q_Book;
    Book *head_Book;
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


void borrow_book(){
    BookList *list_public;
    BookList *list_user;
    Book *p_Book;
    printf("Enter the id of book you prefer to borrow");
    scanf ("%d", p_Book->id);
    delete_node(list_public);
    list_public->length = list_public->length - 1;
    add_node(list_user);
    list_user->length = list_user->length + 1;
}

void return_book(){
    BookList *list_public;
    BookList *list_user;
    Book *p_Book;
    printf("Enter the id of book you prefer to return");
    scanf ("%d", p_Book->id);
    delete_node(list_user);
    list_user->length = list_user->length - 1;
    add_node(list_public);
    list_public->length = list_public->length + 1;
}

