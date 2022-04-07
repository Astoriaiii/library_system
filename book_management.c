#include "book_management.h"
#include <string.h>

//get book information from input 
Book* GetBook(unsigned int id, char* title, char* authors, unsigned int year, unsigned int copies)
{
	Book* book = (Book*)malloc(sizeof(Book));
	book->id = id;
	book->title = (char*)malloc(sizeof(char) * (strlen(title)+1));
	strcpy(book->title, title);
	book->authors = (char*)malloc(sizeof(char) * (strlen(authors) + 1));
	strcpy(book->authors, authors);
	book->year = year;
	book->copies = copies;
	book->next = NULL;
	return book;
}

//write the information in booklist to file
int store_books(FILE* file)
{
	if (!file) return 1;
	fprintf(file, "%u\n", all_books->length);
	int i = 0;
	Book* p = all_books->list;
	for (; i < all_books->length; i++, p=p->next)
	{
		fprintf(file, "%u\n", p->id);
		fprintf(file, "%s\n", p->title);
		fprintf(file, "%s\n", p->authors);
		fprintf(file, "%u\t%u\n", p->year, p->copies);
	}
	return 0;
}

//load book from files into linked list
int load_books(FILE* file)
{
	if (!file || !all_books) return 1;
	fscanf(file, "%u", &all_books->length);
	unsigned int id, year, copies;
	char title[1024], authors[1024];
	int i = 0;
	Book* p = NULL;
	for (; i < all_books->length; i++)
	{
		//get book information
		fscanf(file, "%u\n", id);
		fgets(title, 1024, file);
		fgets(authors, 1024, file);
		fscanf(file, "%u\n", year);
		fscanf(file, "%u\n", copies);
		Book* tmp_book = GetBook(id, title, authors, year, copies);
		//manipulate linked list
		if (p == NULL) all_books->list = tmp_book;
		else p->next = tmp_book;
		p = tmp_book;
	}
	return 0;
}

//prepare for book management(add, search)
Book* CopyBook(Book copy)
{
	Book* book= (Book*)malloc(sizeof(Book));
	book->id = copy.id;
	book->title = (char*)malloc(sizeof(char) * (strlen(copy.title) + 1));
	strcpy(book->title, copy.title);
	book->authors = (char*)malloc(sizeof(char) * (strlen(copy.authors) + 1));
	strcpy(book->authors, copy.authors);
	book->year = copy.year;
	book->copies = copy.copies;
	//manipulate linked list
	book->next = NULL;
	return book;
}

//add_book according to id to linked list
int add_book(Book book)
{
	int i = 0;
	//find linked list
	Book* p = all_books->list;
	for (; i < all_books->length; i++, p = p->next)
	{
		if (p->id == book.id) 
		return 1;
	}
	//manipulate linked list
	Book* tmp_book = CopyBook(book);
	p->next = tmp_book;
	all_books->length++;
	return 0;
}

//remove book from linked list
int remove_book(Book book)
{
	int i = 0;
	//find booklist
	Book* p = all_books->list;
	Book* target = NULL;
	Book* father = NULL;
	for (; i < all_books->length; i++, p = p->next)
	{
		if (p->id == book.id)
		{
			target = p;
			break;
		}
		father = p;
	}
	//manipulate linked list
	if (target == NULL) 
	return 1;
	if (all_books->list == target) 
	all_books->list = target->next;
	else 
	father->next = target->next;
	all_books->length--;
	return 0;
}

//find book by title
BookList find_book_by_title(const char* title)
{
	BookList list;
	list.length = 0;
	list.list = NULL;
	Book* father = NULL;
	int i = 0;
	//find booklist
	Book* p = all_books->list;
	for (; i < all_books->length; i++, p = p->next)
	{
		if (strcmp(title, p->title) == 0)
		{
			Book* tmp_book = CopyBook(*p);
			if (father == NULL) 
			list.list = tmp_book;
			else 
			father->next = tmp_book;
			father = tmp_book;
			list.length++;
		}
	}
	return list;
}

//find book by author
BookList find_book_by_author(const char* author)
{
	BookList list;
	list.length = 0;
	list.list = NULL;
	Book* father = NULL;
	int i = 0;
	Book* p = all_books->list;
	for (; i < all_books->length; i++, p = p->next)
	{
		if (strcmp(author, p->authors)==0)
		{
			Book* tmp_book = CopyBook(*p);
			if (father == NULL) 
			list.list = tmp_book;
			else 
			father->next = tmp_book;
			father = tmp_book;
			list.length++;
		}
	}
	return list;
}

//find book by year
BookList find_book_by_year(unsigned int year)
{
	BookList list;
	list.length = 0;
	list.list = NULL;
	Book* father = NULL;
	int i = 0;
	Book* p = all_books->list;
	for (; i < all_books->length; i++, p = p->next)
	{
		if (year==p->year)
		{
			Book* tmp_book = CopyBook(*p);
			if (father == NULL) 
			list.list = tmp_book;
			else 
			father->next = tmp_book;
			father = tmp_book;
			list.length++;
		}
	}
	return list;
}
