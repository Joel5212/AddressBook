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
#include "address_book_menu.h"

char filename[] = {"address_book.csv"};

struct ContactInfo
{
	char name[32];
	char phoneNumbers[32];
	char emailAddresses[32];
	char serialNumbers[32];
};

//Function Prototypes In Order
void menu_header(const char *str);
void main_menu(void);
int get_option(int type, const char *msg);
void menu();

void add_contacts_menu(void);
void add_contacts();

void name();
void phoneNumbers();
void email();

//Main function
int main()
{
	menu();
	searchContact();
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
			list_all_contacts();
			break;
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
	fp = fopen(DEFAULT_FILE, "ab");
	do
	{
		add_contacts_menu();

		int option = get_option(NUM, "");
		switch (option)
		{
		case 0:
			/* code */
			fwrite(&contactInfo, sizeof(contactInfo), 1, fp);
			fclose(fp);
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
void searchByName()
{
	FILE *filePointer;
	filePointer = fopen(filename, "rb");

	ContactInfo target;
	char targetName[32];

	int found = 0;

	printf("\nEnter the Contact Name: ");
	scanf("&s", &targetName);

	while (1)
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

	while (1)
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

	while (1)
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
		do
		{
			system("cls");
			printf("========== Search Contact ==========\n\n");

			printf("1. Search by Name\n");
			printf("2. Search by Phone Number\n");
			printf("3. Search by Email\n");
			printf("4. Exit to Main Menu\n\n");

			printf("Please Enter Your Choice: ");
			scanf("%d", &searchMethod);

		} while (!(searchMethod >= 1 && searchMethod <= 4));

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

		do
		{
			system("cls");
			printf("Would You Like To Search Again or Exit to Main Menu?\n\n");

			printf("1. Search Again\n");
			printf("2. Exit to Main Menu\n\n");

			printf("Please Enter Your Choice: ");
			scanf("%d", &searchAgainChoice);

		} while (!(searchAgainChoice >= 1 && searchAgainChoice <= 2));

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

//EDIT CONTACT FUNCTIONS
/* Printing a menu for when the edit option is prompted*/

void edit_contact()
{
	int option;
	do
	{
		/* code */

		printf("==================Address Book=============");
		printf("======== Search Contact to edit by==========\n\n");

		printf("1. Name\n\n");
		printf("2. PhoneNumber\n\n");
		printf("3. Email\n\n");
		printf("0. Exit\n\n");

		printf("========================================================\n\n");

		printf("\nPlease enter your Choice:");
		option = get_option(NUM, "");

		/* Switch case for the 3 cases he wants*/
		switch (option)
		{
		case 1:
			name();
			break;

		case 2:
			phoneNumbers();
			break;

		case 3:
			email();
			break;

		case 0:
			exit(0);
		}
	} while (option != 0);
}
/* Edit by name case */
void name()
{
	FILE *fp, *fp1;
	struct ContactInfo contactInfo;
	int name, found = 0, count = 0;

	fp = fopen(DEFAULT_FILE, "rb");
	fp1 = fopen("temp.dat", "wb");

	/* Prompt user to enter employee name as thats what has been chosen for editing*/
	/* Save it to temporary */

	printf("\nEnter the Employee Name you want to edit:");
	scanf("%d", &name);

	/* while loop till either name is found and changed or not found*/
	while (1)
	{
		fread(&contactInfo, sizeof(), 1, fp);

		if (feof(fp))
		{
			break;
		}
		if (contactInfo.name == name)
		{
			found = 1;
			printf("\nEnter Employee Email:");
			scanf("%d", &contactInfo.emailAddresses);

			fflush(stdin);
			printf("\nEnter Employee Name:");
			scanf("%s", contactInfo.name);
			printf("\nEnter Employee Phone number:");
			scanf("%d", &contactInfo.phoneNumbers);
			fwrite(&contactInfo, sizeof(contactInfo), 1, fp1);
		}
		else
		{
			fwrite(&contactInfo, sizeof(contactInfo), 1, fp1);
		}
	}
	fclose(fp);
	fclose(fp1);

	if (found == 0)
		typedef struct
		{
			char names[32];
			char phoneNumbers[32];
			char emailAddresses[32];
			char serialNumbers[32];
		} AddressBook;

	int main(void)
	{
		printf("Sorry No Record Found\n\n");
	}
	else
	{
		fp = fopen(fname, "wb");
		fp1 = fopen("temp.dat", "rb");

		while (1)
		{
			fread(&t, sizeof(t), 1, fp1);

			if (feof(fp1))
			{
				break;
			}
			fwrite(&t, sizeof(t), 1, fp);
		}
	}
	fclose(fp);
	fclose(fp1);
}

/* Edit by phone number case */

void phoneNumbers()
{
	FILE *fp, *fp1;
	struct emp t, t1;
	int phoneNumbers, found = 0, count = 0;

	fp = fopen(fname, "rb");
	fp1 = fopen("temp.dat", "wb");

	printf("\nEnter the Employee Phone number you want to edit:");
	scanf("%d", &phoneNumbers);

	while (1)
	{
		fread(&t, sizeof(t), 1, fp);

		if (feof(fp))
		{
			break;
		}
		if (t.phoneNumbers == phoneNumbers)
		{
			found = 1;
			printf("\nEnter New Employee Email:");
			scanf("%d", &t.email);

			fflush(stdin);
			printf("\nEnter New Employee Name:");
			scanf("%s", t.name);
			printf("\nEnter New Employee Phone number:");
			scanf("%d", &t.phoneNumbers);
			fwrite(&t, sizeof(t), 1, fp1);
		}
		else
		{
			fwrite(&t, sizeof(t), 1, fp1);
		}
	}
	fclose(fp);
	fclose(fp1);

	if (found == 0)
	{
		printf("Sorry No Record Found\n\n");
	}
	else
	{
		fp = fopen(fname, "wb");
		fp1 = fopen("temp.dat", "rb");

		while (1)
		{
			fread(&t, sizeof(t), 1, fp1);

			if (feof(fp1))
			{
				break;
			}
			fwrite(&t, sizeof(t), 1, fp);
		}
	}
	fclose(fp);
	fclose(fp1);
}

/* Edit by email case */
void email()
{
	FILE *fp, *fp1;
	struct emp t, t1;
	int email, found = 0, count = 0;

	fp = fopen(fname, "rb");
	fp1 = fopen("temp.dat", "wb");

	printf("\nEnter the Employee email you want to edit:");
	scanf("%d", &email);

	while (1)
	{
		fread(&t, sizeof(t), 1, fp);

		if (feof(fp))
		{
			break;
		}
		if (t.email == email)
		{
			found = 1;
			printf("\nEnter New Employee Email:");
			scanf("%d", &t.email);

			fflush(stdin);
			printf("\nEnter New Employee Name:");
			scanf("%s", t.name);
			printf("\nEnter New Employee Phone number:");
			scanf("%d", &t.phoneNumbers);
			fwrite(&t, sizeof(t), 1, fp1);
		}
		else
		{
			fwrite(&t, sizeof(t), 1, fp1);
		}
	}
	fclose(fp);
	fclose(fp1);

	if (found == 0)
	{
		printf("Sorry No Record Found\n\n");
	}
	else
	{
		fp = fopen(fname, "wb");
		fp1 = fopen("temp.dat", "rb");

		while (1)
		{
			fread(&t, sizeof(t), 1, fp1);

			if (feof(fp1))
			{
				break;
			}
			fwrite(&t, sizeof(t), 1, fp);
		}
	}
	fclose(fp);
	fclose(fp1);
}

//LIST CONTACTS FUNCTIONS
void list_all_contacts()
{
	char option;
	char back = 'q';
	int result;

	FILE *fp;
	struct ContactInfo display;

	fp = fopen(DEFAULT_FILE, "rb");

	//Address Book Header
	printf("\n######\tAddress Book\t######\n");
	printf("######\tSearch Result:\n");

	//Top of Display Table
	printf("==========/==========/==========/==========/==========/==========/==========/==========/==========/==========/\n");
	printf(":  S.No  : Name\t\t\t\t: Phone No\t\t\t\t: Email ID\t\t\t\t:\n");
	printf("==========/==========/==========/==========/==========/==========/==========/==========/==========/==========/\n");

	//Body of Display Table
	while (feof(fp) != NULL)
	{
		fread(&display, sizeof(display), 1, fp);

		printf(":  %s  : ", display.serialNumbers);
		printf("%s\t\t\t: ", display.name);
		printf("%s\t\t\t: ", display.phoneNumbers);
		printf("%s\t\t: ", display.emailAddresses);
		printf("\n")
			printf("==========/==========/==========/==========/==========/==========/==========/==========/==========/==========/\n");
	}
	//Bottom line of Display Table
	printf("==========/==========/==========/==========/==========/==========/==========/==========/==========/==========/\n");

	fclose(pf);

	//Options to go back to main menu selection screen
	printf("Press: [q] | Cancel: [any other key] ");
	scanf("%c\n", &option);

	result = strcmp(&option, &back);

	if (result == -113)
	{
		menu();
	}
}

//DELETE CONTACT FUNCTIONS
void delete_contact()
{
	FILE *fp, *fp1;
	struct AddressBook ab, ab2;
	int id, choice, found = 0;
	//int count = 0;
	fp = fopen(DEFAULT_FILE, "rb");
	fp1 = fopen("temp.txt", "wb");

	printf("####### Search Contact to Delete by:\n\n");
	printf("0. Back\n");
	printf("1. Name\n");
	printf("2. Phone No\n");
	printf("3. Email ID\n");
	printf("4. Serial No\n\n");

deleteOption:;
	printf("Please select an option: ");
	scanf("%d", &choice);
	if (choice == 0)
	{
		//goes back a menu in the program
	}
	else if (choice == 1)
	{
		char myName[32];
		printf("Enter the name: ");
		scanf("%s", &myName);
		while (1)
		{
			fread(&ab, sizeof(ab), 1, fp);
			//reaches the end of the file, break
			if(feof(fp){
				break;
			}
			//if the string matches, set found = 1, don't write to file
			if(strcmp(ab.name, myName) == 0){
				found = 1;
			}
			else{
				//else, copy main file's data into a temp file
				fwrite(&ab, sizeof(ab), 1, fp1);
			}
		}
	}
	else if (choice == 2)
	{
		char myNumber[32];
		printf("Enter a phone number: ");
		scanf("%s", &myNumber);
		while (1)
		{
			fread(&ab, sizeof(ab), 1, fp);
			if(feof(fp){
				break;
			}
			if(strcmp(ab.phoneNumbers, myNumber) == 0){
				found = 1;
			}
			else{
				fwrite(&ab, sizeof(ab), 1, fp1);
			}
		}
	}
	else if (choice == 3)
	{
		char myEmail[32];
		printf("Enter the email: ");
		scanf("%s", &myEmail);
		while (1)
		{
			fread(&ab, sizeof(ab), 1, fp);
			if(feof(fp){
				break;
			}
			if(strcmp(ab.names, myEmail) == 0){
				found = 1;
			}
			else{
				fwrite(&ab, sizeof(ab), 1, fp1);
			}
		}
	}
	else if (choice == 4)
	{
		char mySi[32];
		printf("Enter a serial number: ");
		scanf("%s", &mySi);
		while (1)
		{
			fread(&ab, sizeof(ab), 1, fp);
			if(feof(fp){
				break;
			}
			if(strcmp(ab.serialNumbers, mySi) == 0){
				found = 1;
			}
			else{
				fwrite(&ab, sizeof(ab), 1, fp1);
			}
		}
	}
	else
	{
		goto deleteOption;
	}
	fclose(fp);
	fclose(fp1);

	if (found == 0)
	{
		printf("Could not find the contact.\n");
	}
	else
	{
		//read from temp file and write to main file.
		fp = fopen(DEFAULT_FILE, "wb");
		fp1 = fopen("temp.text", "rb");
		while (1)
		{
			fread(&ab, sizeof(ab), 1, fp1);
			if (feof(fp1))
			{
				break;
			}
			fwrite(&ab, sizeof(ab), 1, fp);
		}
		fclose(fp);
		fclose(fp1);
	}
}