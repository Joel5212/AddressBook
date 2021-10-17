/*Header file for the file that handles all menu options*/
#ifndef ABK_MENUS_H
#define ABK_MENUS_H

#include "address_book.h"

#define NONE 0
#define NUM 1
#define CHAR 2

#define WINDOW_SIZE 5

//Function Prototypes In Order
void menu_header(const char *str);
void main_menu(void);
int get_option(int type, const char *msg);
void menu();

void add_contacts_menu(void);
void add_contacts();

void searchByName();
void searchByPhone();
void searchByEmail();
void searchContact();

void edit_contact();
void name();
void phoneNumbers();
void email();

void list_all_contacts();

void delete_contact();

// Status menu(AddressBook *address_book);
// Status save_prompt(AddressBook *address_book);
// Status add_contacts(AddressBook *address_book);
// Status search_contact(AddressBook *address_book);
// Status edit_contact(AddressBook *address_book);
// Status delete_contact(AddressBook *address_book);
// Status list_contacts(AddressBook *address_book, const char *title, int *index, const char *msg, Modes mode);

#endif