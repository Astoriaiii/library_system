//
// Created by PC on 2022/3/24.
//

#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "book_management.h"
//#include "borrow_return.c"
 Book *head_Book;
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
       
        head_Book = (Book*)malloc(sizeof(Book));
	head_Book->next = NULL;
        Book *end_Book = (Book*)malloc(sizeof(Book));	
	head_Book  = end_Book;
        while (end_Book != NULL) { 
		Book* q_Book =  (Book*)malloc(sizeof(Book));
		title=(char*)malloc(sizeof(char)*100);
		authors=(char*)malloc(sizeof(char)*100);
                a = fscanf(file,"%s %s\t%s\t%s\t%s", id, title, authors, year, copies);
		fgetc(file);
            if (a != 5){
		free((void*)end_Book);

		break;
                
           }
a = atoi(id);
q_Book->id = a;
a = atoi(year);
q_Book->year = a;
a = atoi(copies);
q_Book->copies = a;
            q_Book->title = (char*)malloc(100*sizeof(char));
            q_Book->authors = (char*)malloc(100*sizeof(char));
	    strcpy(q_Book->title,title);
	    strcpy(q_Book->authors,authors);
q_Book->next= NULL;
end_Book -> next = q_Book;
end_Book = end_Book ->next;
    }
	fclose(file);
    return 0;
}

void display(){
	Book* temp_Book;
	temp_Book = head_Book->next;
	while(temp_Book){
		printf("%d\t%s\t%s\t%d\t%d\n", temp_Book->id, temp_Book->title, temp_Book->authors, temp_Book->year, temp_Book->copies);
		temp_Book = temp_Book->next;
	}
}
