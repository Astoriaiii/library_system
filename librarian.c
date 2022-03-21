#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "book_management.h"

//allow librarians to create new book
struct Book *create_new_Book {
	struct Book *head_Book;
	struct Book *p_Book;
	unsigned int id;
	char *title; 
	char *authors;
	unsigned int year;
	unsigned int copies;
	
	printf("Enter the id of you wish to add");
	scanf("%d", id);
	printf("Enter the title of the book you wish to add");
	scanf("%s", title);
	printf("Enter the author of the book you wish to add");
	scanf("%s", authors);
	printf("Enter the year that the book you wish to add was released");
	scanf("%d", year);
	printf("Enter the number of copies of the book that you wish to add");
	scanf("%s", copies);
	
	p_Book = (struct Book *) malloc (sizeof(struct Book));
	p_Book->id = id;
	strcpy (p_Book->title, title);
	strcpy (p_Book->authors, authors);
	p_Book->year = year;
	p_Book->copies = copies;

    return head_Book;
}

//utilize link list to insert new book to book list
int add_Book(Book book) {
	
	struct Book *p;
	struct Book *q;
	p = q = head_Book;
	if (head_Book == Null) {
		head_Book = new_Book;
		new_Book->next = Null;
	}
	else{
		while ((new_Book->id > p->id) && (p->next != Null)){
			q = p;
			p = p->next;			
		}
		if (new_Book->id <= p->id) {
			new_Book->next = p;
			if (head_Book == p){
				head_Book = new_Book;
			}
			else{
				q->next = new_Book
			}
		}
		else {
			p->next = new_Book;
			new_book->next = Null;
		}
	}
	return 0;
}

//utilize link list to remove book from book list
int remove_book(Book book) {
    int id;
    struct Book *p;
    struct Book *q;
    p = q = head_Book;

    while (p->id !=id && p->next != Null) {
        q = p;
        p = p->next;
    }
    if (p->id = id) {
        if (p == head_Book){
            head_Book = p->next;
        }
        else{
            q->next = p->next;
        }

        free(p);
        printf("deletion successful!")
    }
    else {
        printf ("The book could not be found.");
    }
    return 0;
}