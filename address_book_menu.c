// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>

// #include "address_book_fops.h"
// #include "address_book_menu.h"
// #include "address_book.h"

// int get_option(int type, const char *msg)
// {
// 	/*
// 	 * Mutilfuction user intractions like
// 	 * Just an enter key detection
// 	 * Read an number
// 	 * Read a charcter
// 	 */

// 	if (type == NUM)
// 	{
// 		int option;
// 		printf(msg);
// 		scanf("%d", &option);
// 		return option;
// 	}
// 	else if (type == CHAR)
// 	{
// 		char option;
// 		printf(msg);
// 		scanf("%c", &option);
// 		return (int)option;
// 	}
// 	/* Fill the code to add above functionality */
// }

// Status save_prompt(AddressBook *address_book)
// {
// 	char option;

// 	do
// 	{
// 		main_menu();

// 		option = get_option(CHAR, "\rEnter 'N' to Ignore and 'Y' to Save: ");

// 		if (option == 'Y')
// 		{
// 			save_file(address_book);
// 			printf("Exiting. Data saved in %s\n", DEFAULT_FILE);

// 			break;
// 		}
// 	} while (option != 'N');

// 	free(address_book->list);

// 	return e_success;
// }

// Status list_contacts(AddressBook *address_book, const char *title, int *index, const char *msg, Modes mode)
// {
// 	/*
// 	 * Add code to list all the contacts availabe in address_book.csv file
// 	 * Should be menu based
// 	 * The menu provide navigation option if the entries increase the page size
// 	 */

// 	return e_success;
// }

// void menu_header(const char *str)
// {
// 	fflush(stdout);

// 	system("clear");

// 	printf("#######  Address Book  #######\n");
// 	if (str != '\0')
// 	{
// 		printf("#######  %s\n", str);
// 	}
// }

// void main_menu(void)
// {
// 	menu_header("Features:\n");

// 	printf("0. Exit\n");
// 	printf("1. Add Contact\n");
// 	printf("2. Search Contact\n");
// 	printf("3. Edit Contact\n");
// 	printf("4. Delete Contact\n");
// 	printf("5. List Contacts\n");
// 	printf("6. Save\n");
// 	printf("\n");
// 	printf("Please select an option: ");
// }

// void add_contacts_menu(AddressBook *address_book, char *name)
// {

// 	address_book->fp = fopen(DEFAULT_FILE, "w");

// 	while (1)
// 	{
// 		fread(&address_book->list, sizeof(address_book->list), 1, address_book->fp);

// 		if (feof(address_book->fp) || strlen(name))
// 		{
// 			menu_header("Add Contact:\n");
// 			printf("0. Back\n");
// 			printf("1. Name: \n");
// 			printf("2. Phone No 1 \n");
// 			printf("3. Email ID 1 \n");
// 			printf("\n");
// 			printf("Please select an option: ");
// 			break;
// 		}
// 		if (stringcmp(address_book->list->name[NAME_COUNT][NAME_LEN], name) == 0)
// 		{
// 			menu_header("Add Contact:\n");
// 			printf("0. Back\n");
// 			printf("1. Name: %s\n", address_book->list->name[NAME_COUNT][NAME_LEN]);
// 			printf("2. Phone No 1: %s\n", address_book->list->phone_numbers[PHONE_NUMBER_COUNT][NUMBER_LEN]);
// 			printf("3. Email ID 1: %s\n", address_book->list->email_addresses[PHONE_NUMBER_COUNT][NUMBER_LEN]);
// 			printf("\n");
// 			printf("Please select an option: ");
// 			break;
// 		}
// 	}

// 	menu_header("Add Contact:\n");
// 	printf("0. Back\n");
// 	printf("1. Name: \n");
// 	printf("2. Phone No 1 \n");
// 	printf("3. Email ID 1 \n");
// 	printf("\n");
// 	printf("Please select an option: ");
// }

// Status menu(AddressBook *address_book)
// {
// 	ContactInfo backup;
// 	Status ret;
// 	int option;

// 	do
// 	{
// 		main_menu();

// 		option = get_option(NUM, "");

// 		if ((address_book->count == 0) && (option != e_add_contact))
// 		{
// 			get_option(NONE, "No entries found!!. Would you like to add? Use Add Contacts");

// 			continue;
// 		}

// 		switch (option)
// 		{
// 		case e_add_contact:

// 			add_contacts(address_book);
// 			/* Add your implementation to call add_contacts function here */

// 			break;
// 		case e_search_contact:
// 			search_contact(address_book);
// 			break;
// 		case e_edit_contact:
// 			edit_contact(address_book);
// 			break;
// 		case e_delete_contact:
// 			delete_contact(address_book);
// 			break;
// 		case e_list_contacts:
// 			break;
// 			/* Add your implementation to call list_contacts function here */
// 		case e_save:
// 			save_file(address_book);
// 			break;
// 		case e_exit:
// 			break;
// 		}
// 	} while (option != e_exit);

// 	return e_success;
// }

// Status add_contacts(AddressBook *address_book)
// {
// 	/* Add the functionality for adding contacts here */
// 	do
// 	{
// 		char name[32] = "";
// 		// char phoneNumber[32] = "";
// 		// char emailAddress[32] = "";
// 		add_contacts_menu(address_book, name);
// 		address_book->fp = fopen(DEFAULT_FILE, "w");
// 		int option = get_option(NUM, "");
// 		switch (option)
// 		{
// 		case 0:
// 			/* code */
// 			fwrite(&address_book->list, sizeof(address_book->list), 1, address_book->fp);
// 			fclose(address_book->fp);
// 			menu(address_book);
// 			break;
// 		case 1:
// 			// load_file(address_book)

// 			printf("\nEnter the name: ");
// 			for(int i = 0; i < list[i])
// 			scanf("%s", &address_book->list[i].name);
// 			printf("hello");
// 			// name = address_book->list->name[NAME_COUNT][NAME_LEN];
// 			// save_file(address_book);

// 			break;

// 		case 2:
// 			// load_file(address_book);
// 			printf("\nEnter Phone Number: ");
// 			scanf("%s", &address_book->list->phone_numbers[PHONE_NUMBER_COUNT][NUMBER_LEN]);
// 			// phoneNumber = address_book->list->phone_numbers[PHONE_NUMBER_COUNT][NUMBER_LEN];
// 			// save_file(address_book);
// 			fwrite(&address_book->list, sizeof(address_book->list), 1, address_book->fp);
// 			break;

// 		case 3:
// 			address_book->fp = fopen(DEFAULT_FILE, "w");
// 			printf("\nEnter Email address");
// 			scanf("%s", &address_book->list->email_addresses[EMAIL_ID_COUNT][EMAIL_ID_LEN]);
// 			// emailAddress = address_book->list->email_adresses[EMAIL_ID_COUNT][EMAIL_ID_LEN];
// 			fwrite(&address_book->list, sizeof(address_book->list), 1, address_book->fp);
// 			break;

// 		default:
// 			break;
// 		}
// 	} while (1);
// 	return e_success;
// }

// Status search(const char *str, AddressBook *address_book, int loop_count, int field, const char *msg, Modes mode)
// {
// 	/* Add the functionality for adding contacts here */
// }

// Status search_contact(AddressBook *address_book)
// {

// 	/* Add the functionality for search contacts here */
// }

// Status edit_contact(AddressBook *address_book)
// {
// 	/* Add the functionality for edit contacts here */
// }

// Status delete_contact(AddressBook *address_book)
// {
// 	/* Add the functionality for delete contacts here */
// }
