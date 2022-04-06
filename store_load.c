//
// Created by PC on 2022/3/24.
//

#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "book_management.h"
#include "borrow_return.c"

/*
//store information from book link list to file
int store_books(FILE *file, Book *head_Book) {
    //if ((file = fopen("book.txt","w+")) == NULL) {
        //printf("Error occurs when open the file");
        //return -1;}
        //Book *head_Book;
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
*/


//read book information on link list from files
int load_books(FILE *file) {
    //FILE *file;
int a;
	char* title;
	char* authors;
char id[20];
char year[20];
char copies[20];
    if ((file = fopen("books.txt", "r")) == NULL) {
        printf("Error occurs when open the file\n");
        return -1;
    }
        Book *head_Book, *temp_Book;
        head_Book = (Book*)malloc(sizeof(Book));
        head_Book->next = (Book*)malloc(sizeof(Book));
        temp_Book = head_Book;
        Book *q_Book = (Book*)malloc(sizeof(Book));
        temp_Book->next= (Book*)malloc(sizeof(Book));
        //temp_Book = (Book*)malloc(sizeof(Book));
        while (temp_Book) { 
                //temp_Book = (Book*)malloc(sizeof(Book));
		title=(char*)malloc(sizeof(char)*100);
		authors=(char*)malloc(sizeof(char)*100);
            a = fscanf(file,"%s %s\t%s\t%s\t%s", id, title, authors, year, copies);
fgetc(file);
            if (a != 5){
		free((void*)temp_Book);
		break;
                //printf("3");
            }
a = atoi(id);
temp_Book->id = a;
a = atoi(year);
temp_Book->year = a;
a = atoi(copies);
temp_Book->copies = a;
             //temp_Book->id = atoi(temp_Book->id);
            //temp_Book->year = atoi(temp_Book->year);
            //temp_Book->copies = atoi(temp_Book->copies);
            temp_Book->title = (char*)malloc(100*sizeof(char));
            temp_Book->authors = (char*)malloc(100*sizeof(char));
	    strcpy(temp_Book->title,title);
	    strcpy(temp_Book->authors,authors);
//printf("%d\t%d\n", temp_Book->year, temp_Book->copies);
	   printf("%d\t%s\t%s\t%d\t%d\n", temp_Book->id, temp_Book->title, temp_Book->authors, temp_Book->year, temp_Book->copies);
q_Book = temp_Book;
temp_Book->next = (Book*)malloc(sizeof temp_Book->next);
	temp_Book = temp_Book->next;
            //if (head_Book == NULL){
              //  head_Book->next = temp_Book;
           // }
            //else{
              //  p_Book->next = temp_Book;

    }
	fclose(file);
    return 0;
}


/*
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
}*/
