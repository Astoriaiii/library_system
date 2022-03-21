//
// Created by PC on 2022/3/18.
//
#include <stdio.h>
#include <stdlib.h>
#include "book_management.h"

void borrow_book(struct Book *p_Book){
    printf("Please choose the book you want to borrow by number:");
    char num[1024];
    if (fgets(num, 1024, stdin) != Null && scanf_s(num, "%d", &id) != EOF) {
        if (p_Book == Null){
            printf("The book does not exist.")
        }
        else {
            p_Book = p_Book->next;
            p_Book->id = p_Book;
            while (Book->next != Null){
                q_Book = q_Book->next;
            }
            p_Book = (Book *)malloc(sizeof(Book));
            p_Book->next = Null;
            q_Book->next = p_Book;

            printf("Borrow successful!");


            
        }

    }
}

