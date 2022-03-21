//
// Created by PC on 2022/3/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_management.h"

// find book according to book title
BookList find_book_by_title (const char *title) {
    struct Book *p_Book = head_book;
    int index = 0;
    while (p_Book != Null) {
        if (strcmp(p_Book->title, title) == 0){
            printf ("ID\tTitle\tAuthor\tYear\tCopies\t");
            printf("%d\t%s\t%s\t%d\t%d\t", p_Book->id, p_Book->title, p_Book->author, p_Book->year, p_Book->copies);
            index ++;
        }
        if (index > 0){
            break;
        }
        p_Book = p_Book->next;
    }
    if (index == 0){
        printf("The book you are searching is not existing or available!")
    }
    return head_Book;
};

// find book according to the author of book
BookList find_book_by_author (const char *author) {
    struct Book *p_Book = head_book;
    int index = 0;
    while (p_Book != Null) {
        if (strcmp(p_Book->author, title) == 0){
            printf ("ID\tTitle\tAuthor\tYear\tCopies\t");
            printf("%d\t%s\t%s\t%d\t%d\t", p_Book->id, p_Book->title, p_Book->author, p_Book->year, p_Book->copies);
            index ++;
        }
        if (index > 0){
            break;
        }
        p_Book = p_Book->next;
    }
    if (index == 0){
        printf("The book you are searching is not existing or available!")
    }
    return head_Book;
};

//find book according to the year when book published
BookList find_book_by_year (unsigned int year) {
    struct Book *p_Book = head_book;
    int index = 0;
    while (p_Book != Null) {
        if (p_Book->year == year){
            printf ("ID\tTitle\tAuthor\tYear\tCopies\t");
            printf("%d\t%s\t%s\t%d\t%d\t", p_Book->id, p_Book->title, p_Book->author, p_Book->year, p_Book->copies);
            index ++;
        }
        if (index > 0){
            break;
        }
        p_Book = p_Book->next;
    }
    if (index == 0){
        printf("The book you are searching is not existing or available!")
    }
    return head_Book;
}

