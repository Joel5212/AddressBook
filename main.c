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