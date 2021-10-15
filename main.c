/*Main method that groups all of the subfiles together
-Calls load_file() from address_book_fops.c
If it returns the Status e_success:
	-Call menu() from address_book_menu.c which calls compiles all of the methods into one method
		-After the menu() is called, calls save_prompt() from address_book_menu.c it prompts the user to save the file,
		prompting the method save_file() from address_book_foops.c*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "address_book.h"
<<<<<<< HEAD

char filename[] = {"address_book.csv"};

void searchByName()
{
	FILE *filePointer;
	filePointer = fopen(filename, "rb");

	ContactInfo target;
	char targetName[32];

	int found = 0;
	
	printf("\nEnter the Contact Name: ");
	scanf("&s", &targetName);

	while(1)
	{
		fread(&target, sizeof(target), 1, filePointer);

		if (feof(filePointer))
		{
			break;
		}
		if (strcmp(targetName, target.name) == 0)
		{
			system("cls");
			printf("Contact Info of %s:\n\n", target.name);
			printf("Name: %s\n", target.name);
			printf("Phone Number: %s\n", target.phoneNumbers);
			printf("Email: %s\n", target.emailAddresses);

			found = 1;
		}
	}

	if (found == 0)
	{
		printf("\nNo Contact Found");
	}
	fclose(filePointer);
}

void searchByPhone()
{
	FILE *filePointer;
	filePointer = fopen(filename, "rb");

	ContactInfo target;
	char targetPhone[32];

	int found = 0;
	
	printf("\nEnter the Contact Phone: ");
	scanf("&s", &targetPhone);

	while(1)
	{
		fread(&target, sizeof(target), 1, filePointer);

		if (feof(filePointer))
		{
			break;
		}
		if (strcmp(targetPhone, target.phoneNumbers) == 0)
		{
			system("cls");
			printf("Contact Info of %s:\n\n", target.name);
			printf("Name: %s\n", target.name);
			printf("Phone Number: %s\n", target.phoneNumbers);
			printf("Email: %s\n", target.emailAddresses);

			found = 1;
		}
	}

	if (found == 0)
	{
		printf("\nNo Contact Found");
	}
	fclose(filePointer);
}

void searchByEmail()
{
	FILE *filePointer;
	filePointer = fopen(filename, "rb");

	ContactInfo target;
	char targetEmail[32];

	int found = 0;
	
	printf("\nEnter the Contact Email: ");
	scanf("&s", &targetEmail);

	while(1)
	{
		fread(&target, sizeof(target), 1, filePointer);

		if (feof(filePointer))
		{
			break;
		}
		if (strcmp(targetEmail, target.emailAddresses) == 0)
		{
			system("cls");
			printf("Contact Info of %s:\n\n", target.name);
			printf("Name: %s\n", target.name);
			printf("Phone Number: %s\n", target.phoneNumbers);
			printf("Email: %s\n", target.emailAddresses);

			found = 1;
		}
	}

	if (found == 0)
	{
		printf("\nNo Contact Found");
	}
	fclose(filePointer);
}

void searchContact()
{

	int searchMethod;
	int searchAgainChoice;
	bool searchAgain = true;

	while (searchAgain == true)
	{
		do {
			system("cls");
			printf("========== Search Contact ==========\n\n");

			printf("1. Search by Name\n");
			printf("2. Search by Phone Number\n");
			printf("3. Search by Email\n");
			printf("4. Exit to Main Menu\n\n");

			printf("Please Enter Your Choice: ");
			scanf("%d", &searchMethod);

		} while(!(searchMethod >= 1 && searchMethod <= 4));

		switch (searchMethod)
		{
		case 1:
			searchByName();
			break;
		case 2:
			searchByPhone();
			break;
		case 3:
			searchByEmail();
			break;
		case 4:
			return;
		default:
			break;
		}

		do {
			system("cls");
			printf("Would You Like To Search Again or Exit to Main Menu?\n\n");
			
			printf("1. Search Again\n");
			printf("2. Exit to Main Menu\n\n");

			printf("Please Enter Your Choice: ");
			scanf("%d", &searchAgainChoice);

		} while(!(searchAgainChoice >= 1 && searchAgainChoice <= 2));

		if (searchAgainChoice == 1)
		{
			searchAgain = true;
		}
		else
		{
			searchAgain = false;
		}
	}

}

int main(void)
{	
	searchContact();
	return 0;
}
=======
#include "address_book_menu.h"

struct ContactInfo
{
	char name[32];
	char phoneNumbers[32];
	char emailAddresses[32];
};

//Function Prototypes In Order
void menu_header(const char *str)
void main_menu(void)
int get_option(int type, const char *msg);
void menu();

void add_contacts_menu(void);
void add_contacts();




//Main function
int main()
{
	menu();
}


//Beginning
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

void menu()
{
	int option;

	do
	{
		main_menu();

		option = get_option(NUM, "");

		switch (option)
		{
		case e_add_contact:
			add_contacts();
			/* Add your implementation to call add_contacts function here */
			break;
		case e_search_contact:
			search_contact();
			break;
		case e_edit_contact:
			edit_contact();
			break;
		case e_delete_contact:
			delete_contact();
			break;
		case e_list_contacts:
			list_contacts();
			break;
			/* Add your implementation to call list_contacts function here */
		case e_save:
			save_file();
			break;
		case e_exit:
			break;
		}
	} while (option != e_exit);

	return e_success;
}

//ADD CONTACT FUNCTIONS
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

void add_contacts()
{
	FILE *fp;
	struct ContactInfo contactInfo;

	do
	{
		add_contacts_menu();

		int option = get_option(NUM, "");
		switch (option)
		{
		case 0:
			/* code */
			fwrite(&contactInfo, sizeof(contactInfo), 1, fp);
			menu();

			break;
		case 1:
			printf("Enter the name: ");
			scanf("%s", contactInfo.name);
			break;

		case 2:
			printf("Enter the phone number: ");
			scanf("%s", contactInfo.phoneNumbers);
			break;

		case 3:
			printf("Enter the email address: ");
			scanf("%s", contactInfo.emailAddresses);
			break;
		default:
			break;
		}
	} while (1);
}


//SEARCH CONTACT FUNCTIONS

//EDIT CONTACT FUNCTIONS

//DELETE CONTACT FUNCTIONS

//LIST CONTACTS FUNCTIONS

//SAVE FUNCTION



>>>>>>> 09fd1437a2dc655dc048ad7530822ac3d053589a
