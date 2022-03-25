//
// Created by PC on 2022/3/24.
//

#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include "book_management.h"
#include "borrow_return.c"

int store_books(FILE *file) {
    //if ((file = fopen("book.txt","w+")) == NULL) {
        //printf("Error occurs when open the file");
        //return -1;}
        Book *head_Book;
        Book *p_Book;
        if (head_Book != NULL) {
            p_Book = head_Book->next;
            FILE *file = fopen("book.txt", "w+");
            if (file != NULL) {
                fprintf(file, "%d %s %s %d %d", p_Book->id, p_Book->title, p_Book->authors, p_Book->year, p_Book->copies);
                p_Book = p_Book->next;
            }
            fclose(file);
            return 0;
        }
        else{
            printf ("Error occurs when open the file.");
            return -1;
        }
    }


int load_books(FILE *file) {
    //FILE *file;
    if ((file = fopen("book.txt", "r+")) == NULL) {
        printf("Error occurs when open the file");
        return -1;
    }
    else {
        Book *head_Book;
        Book *temp_Book = head_Book->next;
        while (temp_Book != NULL) {
            printf("%d %s %s %d %d", temp_Book->id, temp_Book->title, temp_Book->authors, temp_Book->year,
                   temp_Book->copies);
            temp_Book = temp_Book->next;
        }
        fclose(file);
    }
    return 0;
}

void readBookInFile (struct node* head_node) {
    FILE *fp = fopen("book.txt","a+");
    Book *book;
    if (fp != NULL) {
        while (fscanf(fp, "%d %s %s %d %d", book->id, book->title, book->authors, book->year, book->copies) != EOF) {
            add_node(head_node, &book);
        }
        fclose(fp);
    }
    else {
        printf("Error occurs when open the file");
    }
}