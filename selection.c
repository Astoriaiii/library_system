//
// Created by PC on 2022/3/21.
//
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "book_management.h"

//manage the main dashboard
void main_selection {
    p_Book Book = (p_Book)malloc(sizeof(Book));
    book->next = Null;
    p_user user = (p_user)malloc(sizeof(user));
    user->bookList = Null;
    user->next = Null;
    while (1){
        int num=0;
        system("cls");
        menu_initial();
        scanf("%d", &num);
        switch (num){
            case 1: user_register();
            break;
            case 2: login();
            break;
            case 3: search_book();
            break;
            case 4: display_book();
            break;
            case 5: deleteALL(book, node); free(book); free(node);exit(0);
            break;
        }
    }
    return;
}

void librarian_selection {

};

