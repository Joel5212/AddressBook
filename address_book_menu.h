/*Header file for the file that handles all menu options*/
#ifndef ABK_MENUS_H
#define ABK_MENUS_H

#include "address_book.h"

#define NONE 0
#define NUM 1
#define CHAR 2

//Function Prototypes In Order
int get_option(int type, const char *msg);
void menu_header(const char *str);
void main_menu();
Status menu();

void add_contacts_menu();
Status add_contacts();

void search_contacts_menu();
Status search_contact();
void searchByName();
void searchByPhone();
void searchByEmail();

void edit_contacts_menu();
Status edit_contact();
void editByName();
void editByPhone();
void editByEmail();

Status list_all_contacts();

void delete_contacts_menu();
Status delete_contact();
void deleteByName();
void deleteByPhone();
void deleteByEmail();


#endif