/*File that handles all of the menu options*/

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "abk_fileops.h"
#include "abk_log.h"
#include "abk_menus.h"
#include "abk.h"

int get_option(int type, const char *msg)
{
	/*
	 * Mutilfuction user intractions like
	 * Just an enter key detection
	 * Read an number
	 * Read a charcter
	 */ 

	if (type == NUM)
	{
		short option;
		printf(msg);
		scanf("%u", option);
		return option;
	}
	else if (type == CHAR)
	{
		char option;
		printf(msg);
		scanf("%c", &option);
		return (int)option;
	}
	/* Fill the code to add above functionality */
}

Status save_prompt(AddressBook *address_book)
{
	char option;

	do
	{
		main_menu();

		option = get_option(CHAR, "\rEnter 'N' to Ignore and 'Y' to Save: ");

		if (option == 'Y')
		{
			save_file(address_book);
			printf("Exiting. Data saved in %s\n", DEFAULT_FILE);

			break;
		}
	} while (option != 'N');

	free(address_book->list);

	return e_success;
}

Status list_contacts(AddressBook *address_book, const char *title, int *index, const char *msg, Modes mode)
{
	/* 
	 * Add code to list all the contacts availabe in address_book.csv file
	 * Should be menu based
	 * The menu provide navigation option if the entries increase the page size
	 */ 

	return e_success;
}

void menu_header(const char *str)
{
	fflush(stdout);

	system("clear");

	printf("#######  Address Book  #######\n");
	if (str != '\0')
	{
		printf("#######  %s\n", str);
	}
}

void main_menu(void)
{
	menu_header("Features:\n");

	printf("0. Exit\n");
	printf("1. Add Contact\n");
	printf("2. Search Contact\n");
	printf("3. Edit Contact\n");
	printf("4. Delete Contact\n");
	printf("5. List Contacts\n");
	printf("6. Save\n");
	printf("\n");
	printf("Please select an option: ");
}

void add_contacts_menu(void)
{
	menu_header("Add Contact:\n");

	printf("0. Back\n");
	printf("1. Name\n");
	printf("2. Phone No 1\n");
	printf("3. Email ID 1\n");
	printf("\n");
	printf("Please select an option: ");
}

Status menu(AddressBook *address_book)
{
	ContactInfo backup;
	Status ret;
	int option;

	do
	{
		main_menu();

		option = get_option(NUM, "");

		if ((address_book-> count == 0) && (option != e_add_contact))
		{
			get_option(NONE, "No entries found!!. Would you like to add? Use Add Contacts");

			continue;
		}

		switch (option)
		{
		case e_add_contact:

			add_contacts(address_book);
			/* Add your implementation to call add_contacts function here */

			break;
		case e_search_contact:
			search_contact(address_book);
			break;
		case e_edit_contact:
			edit_contact(address_book);
			break;
		case e_delete_contact:
			delete_contact(address_book);
			break;
		case e_list_contacts:
			break;
			/* Add your implementation to call list_contacts function here */
		case e_save:
			save_file(address_book);
			break;
		case e_exit:
			break;
		}
	} while (option != e_exit);

	return e_success;
}

Status add_contacts(AddressBook *address_book)
{
	/* Add the functionality for adding contacts here */
	do
	{
		add_contacts_menu();

		int option = get_option(NUM, "");
		switch (expression)
		{
		case 0:
			/* code */

			menu(address_book);

			break;
		case 1:
			load_file(address_book)
				printf("Enter the name:   ");
			scanf("%s", address_book.list->name[NAME_COUNT][NAME_LEN]);
			save_file(address_book);

			break;

		case 2:
			load_file(address_book);
			printf("Enter Phone Number");
			scanf("%s", address_book.list->phone_numbers[PHONE_NUMBER_COUNT][NUMBER_LEN]);
			save_file(address_book);
			break;

		case 3:
			printf("Enter Email address");
			scanf("%s", address_book.list->email_addresses[EMAIL_ID_COUNT][EMAIL_ID_LEN]);
			break;
		default:
			break;
		}
	} while (1)
}

Status search(const char *str, AddressBook *address_book, int loop_count, int field, const char *msg, Modes mode)
{
	/* Add the functionality for adding contacts here */
	return e_success;
	return e_fail;
}
}

Status search_contact(AddressBook *address_book)
{
	/* Add the functionality for search contacts here */
	return e_success;
	return e_fail;
}
}

Status edit_contact(AddressBook *address_book)
{
	/* Add the functionality for edit contacts here */
	return e_success;
	return e_fail;
}
}

Status delete_contact(AddressBook *address_book)
{
	/* Add the functionality for delete contacts here */
	return e_success;
	return e_fail;
}
}