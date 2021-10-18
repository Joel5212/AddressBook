#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "address_book.h"
#include "address_book_menu.h"

int get_option(int type, const char *msg)
{
	if (type == NUM)
	{
		int option;
		printf(msg);
		scanf("%d", &option);
		printf("\n");
		return option;
	}
	else if (type == CHAR)
	{
		char option;
		printf(msg);
		scanf("%c", &option);
		printf("\n");
		return (int)option;
	}
}

void menu_header(const char *str)
{
	fflush(stdout);

	printf("#######  Address Book  #######\n");
	if (*str != 0)
	{
		printf("#######  %s\n", str);
	}
}

void main_menu()
{
	menu_header("Features:\n");

	printf("0. Exit\n");
	printf("1. Add Contact\n");
	printf("2. Search Contact\n");
	printf("3. Edit Contact\n");
	printf("4. Delete Contact\n");
	printf("5. List Contacts\n");
	printf("\n");
	printf("Please select an option: ");
}

void add_contacts_menu()
{
	menu_header("Add Contact:\n");

	printf("0. Back\n");
	printf("1. Name\n");
	printf("2. Phone No 1\n");
	printf("3. Email ID 1\n");
	printf("\n");
	printf("Please select an option: ");
}

void search_contacts_menu()
{
	menu_header("Search Contact by:\n");

	printf("0. Back\n");
	printf("1. Name\n");
	printf("2. Phone\n");
	printf("3. Email\n");
	printf("\n");
	printf("Please select an option: ");
}

void edit_contacts_menu()
{
	menu_header("Edit Contact by:\n");

	printf("0. Back\n");
	printf("1. Name\n");
	printf("2. Phone\n");
	printf("3. Email\n");
	printf("\n");
	printf("Please select an option: ");
}

void delete_contacts_menu()
{
	menu_header("Delete Contact by:\n");

	printf("0. Back\n");
	printf("1. Name\n");
	printf("2. Phone\n");
	printf("3. Email\n");
	printf("\n");
	printf("Please select an option: ");
}

Status menu()
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
		case e_exit:
			break;
		}
	} while (option != e_exit);

	return e_success;
}

Status add_contacts()
{
	FILE *fp; //create file pointer
	ContactInfo contactInfo;
	int option;
	fp = fopen(DEFAULT_FILE, "ab");

	do
	{
		add_contacts_menu();

		option = get_option(NUM, "");
		switch (option)
		{
		case e_first_opt:
			fwrite(&contactInfo, sizeof(contactInfo), 1, fp); //transfer block of bytes to the file
			fclose(fp);
			break;

		case e_second_opt:
			printf("Enter the name: ");
			scanf("%s", contactInfo.name);
			break;

		case e_third_opt:
			printf("Enter the phone number: ");
			scanf("%s", contactInfo.phone_number);
			break;

		case e_fourth_opt:
			printf("Enter the email address: ");
			scanf("%s", contactInfo.email_address);
			break;
		default:
			break;
		}
	} while (option != e_exit);

	return e_success;
}

void searchByName()
{
	FILE *filePointer;
	filePointer = fopen(DEFAULT_FILE, "rb");

	ContactInfo target;
	char targetName[32];

	int found = 0;

	printf("\nEnter the Contact Name: ");
	scanf("%s", &targetName);

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
			printf("Phone Number: %s\n", target.phone_number);
			printf("Email: %s\n", target.email_address);
			printf("\n");

			found = 1;
		}
	}

	if (found == 0)
	{
		printf("\nNo Contact Found\n\n");
	}
	fclose(filePointer);
}

void searchByPhone()
{
	FILE *filePointer;
	filePointer = fopen(DEFAULT_FILE, "rb");

	ContactInfo target;
	char targetPhone[32];

	int found = 0;

	printf("\nEnter the Contact Phone: ");
	scanf("%s", &targetPhone);

	while (1)
	{
		fread(&target, sizeof(target), 1, filePointer);

		if (feof(filePointer))
		{
			break;
		}
		if (strcmp(targetPhone, target.phone_number) == 0)
		{
			system("cls");
			printf("Contact Info of %s:\n\n", target.name);
			printf("Name: %s\n", target.name);
			printf("Phone Number: %s\n", target.phone_number);
			printf("Email: %s\n", target.email_address);
			printf("\n");

			found = 1;
		}
	}

	if (found == 0)
	{
		printf("\nNo Contact Found\n\n");
	}
	fclose(filePointer);
}

void searchByEmail()
{
	FILE *filePointer;
	filePointer = fopen(DEFAULT_FILE, "rb");

	ContactInfo target;
	char targetEmail[32];

	int found = 0;

	printf("\nEnter the Contact Email: ");
	scanf("%s", &targetEmail);

	while (1)
	{
		fread(&target, sizeof(target), 1, filePointer);

		if (feof(filePointer))
		{
			break;
		}
		if (strcmp(targetEmail, target.email_address) == 0)
		{
			system("cls");
			printf("Contact Info of %s:\n\n", target.name);
			printf("Name: %s\n", target.name);
			printf("Phone Number: %s\n", target.phone_number);
			printf("Email: %s\n", target.email_address);
			printf("\n");

			found = 1;
		}
	}

	if (found == 0)
	{
		printf("\nNo Contact Found\n\n");
	}
	fclose(filePointer);
}

Status search_contact()
{
	int option;

	do
	{
		search_contacts_menu();

		option = get_option(NUM, "");

		switch (option)
		{
		case e_first_opt:
			break;
		case e_second_opt:
			searchByName();
			break;
		case e_third_opt:
			searchByPhone();
			break;
		case e_fourth_opt:
			searchByEmail();
			break;
		}
	} while (option != e_exit);

	return e_success;
}

void editByName()
{
	FILE *fp, *fp1;
	ContactInfo contactInfo;
	char name[NAME_LEN];
	int found = 0, count = 0;

	fp = fopen(DEFAULT_FILE, "rb");
	fp1 = fopen("temp.dat", "wb");

	printf("\nEnter the Employee Name you want to edit:");
	scanf("%s", &name);

	/* while loop till either name is found and changed or not found*/
	while (1)
	{
		fread(&contactInfo, sizeof(contactInfo), 1, fp);

		if (feof(fp))
		{
			break;
		}
		if (strcmp(contactInfo.name, name) == 0)
		{
			found = 1;
			printf("\nEnter New Employee Name:");
			scanf("%s", &contactInfo.name);

			fflush(stdin);
			printf("\nEnter New Employee Phone number:");
			scanf("%s", &contactInfo.phone_number);
			printf("\nEnter New Employee Email:");
			scanf("%s", &contactInfo.email_address);
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
	{
		printf("Sorry No Record Found\n\n");
	}
	else
	{
		fp = fopen(DEFAULT_FILE, "wb");
		fp1 = fopen("temp.dat", "rb");

		while (1)
		{
			fread(&contactInfo, sizeof(contactInfo), 1, fp1);

			if (feof(fp1))
			{
				break;
			}
			fwrite(&contactInfo, sizeof(contactInfo), 1, fp);
		}
	}
	fclose(fp);
	fclose(fp1);
}

/* Edit by phone number case */
void editByPhone()
{
	FILE *fp, *fp1;
	ContactInfo contactInfo;
	char phoneNumber[NUMBER_LEN];
	int found = 0, count = 0;

	fp = fopen(DEFAULT_FILE, "rb");
	fp1 = fopen("temp.dat", "wb");

	printf("\nEnter the Employee Phone Number you want to edit:");
	scanf("%s", &phoneNumber);

	while (1)
	{
		fread(&contactInfo, sizeof(contactInfo), 1, fp);

		if (feof(fp))
		{
			break;
		}
		if (strcmp(contactInfo.phone_number, phoneNumber) == 0)
		{
			found = 1;
			printf("\nEnter New Employee Name:");
			scanf("%s", &contactInfo.name);

			fflush(stdin);
			printf("\nEnter New Employee Phone number:");
			scanf("%s", &contactInfo.phone_number);
			printf("\nEnter New Employee Email:");
			scanf("%s", &contactInfo.email_address);
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
	{
		printf("Sorry No Record Found\n\n");
	}
	else
	{
		fp = fopen(DEFAULT_FILE, "wb");
		fp1 = fopen("temp.dat", "rb");

		while (1)
		{
			fread(&contactInfo, sizeof(contactInfo), 1, fp1);

			if (feof(fp1))
			{
				break;
			}
			fwrite(&contactInfo, sizeof(contactInfo), 1, fp);
		}
	}
	fclose(fp);
	fclose(fp1);
}

/* Edit by email case */
void editByEmail()
{
	FILE *fp, *fp1;
	ContactInfo contactInfo;
	char email[EMAIL_ID_LEN];
	int found = 0, count = 0;

	fp = fopen(DEFAULT_FILE, "rb");
	fp1 = fopen("temp.dat", "wb");

	printf("\nEnter the Employee Email you want to edit:");
	scanf("%s", &email);

	while (1)
	{
		fread(&contactInfo, sizeof(contactInfo), 1, fp);

		if (feof(fp))
		{
			break;
		}
		if (strcmp(contactInfo.email_address, email) == 0)
		{
			found = 1;
			printf("\nEnter New Employee Name:");
			scanf("%s", &contactInfo.name);

			fflush(stdin);
			printf("\nEnter New Employee Phone number:");
			scanf("%s", &contactInfo.phone_number);
			printf("\nEnter New Employee Email:");
			scanf("%s", &contactInfo.email_address);
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
	{
		printf("Sorry No Record Found\n\n");
	}
	else
	{
		fp = fopen(DEFAULT_FILE, "wb");
		fp1 = fopen("temp.dat", "rb");

		while (1)
		{
			fread(&contactInfo, sizeof(contactInfo), 1, fp1);

			if (feof(fp1))
			{
				break;
			}
			fwrite(&contactInfo, sizeof(contactInfo), 1, fp);
		}
	}
	fclose(fp);
	fclose(fp1);
}

Status edit_contact()
{
	int option;

	do
	{
		edit_contacts_menu();

		option = get_option(NUM, "");

		switch (option)
		{
		case e_first_opt:
			break;
		case e_second_opt:
			editByName();
			break;
		case e_third_opt:
			editByPhone();
			break;
		case e_fourth_opt:
			editByEmail();
			break;
		}
	} while (option != e_exit);

	return e_success;
}

//LIST CONTACTS FUNCTIONS
Status list_all_contacts()
{
	int option;

	FILE *fp;
	ContactInfo display;

	fp = fopen(DEFAULT_FILE, "rb");

	//Address Book Header
	printf("\n######\tAddress Book\t######\n");
	printf("######\tSearch Result:\n");

	//Top of Display Table
	printf("====================================================================================================\n");
	printf(":  S.No  : Name\t\t\t\t: Phone No\t\t\t\t: Email ID\t\t\t\t:\n");
	printf("====================================================================================================\n");

	//Body of Display Table
	while (1)
	{
		if (feof(fp)){
			break;
		}

		fread(&display, sizeof(display), 1, fp);

		printf(":  %s  : ", display.si_no);
		printf("%s\t\t\t: ", display.name);
		printf("%s\t\t\t: ", display.phone_number);
		printf("%s\t\t: ", display.email_address);
		printf("\n");
		printf("====================================================================================================\n");
	}
	//Bottom line of Display Table
	printf("====================================================================================================\n");

	fclose(fp);

	//Options to go back to main menu selection screen
	printf("Go Back To Main Menu: [0]");
	scanf("%d\n", &option);

	if (option == 0)
	{
		menu();
	}
	return e_success;
}

void deleteByName()
{
	FILE *fp, *temp;
	ContactInfo contactInfo;
	int found = 0;
	char myName[32];

	fp = fopen(DEFAULT_FILE, "rb");
	temp = fopen("temp.dat", "wb");

	printf("Enter the name: ");
	scanf("%s", &myName);
	while (1)
	{
		fread(&contactInfo, sizeof(contactInfo), 1, fp);
		//reaches the end of the file, break
		if (feof(fp))
		{
			break;
		}
		//if the string matches, set found = 1, don't write to file
		if (strcmp(contactInfo.name, myName) == 0)
		{
			found = 1;
		}
		else
		{
			//else, copy main file's data into a temp file
			fwrite(&contactInfo, sizeof(contactInfo), 1, temp);
		}
	}

	if (found == 0)
	{
		printf("Could not find the contact.\n");
	}
	else
	{
		//read from temp file and write to main file.
		while (1)
		{
			fread(&contactInfo, sizeof(contactInfo), 1, temp);
			if (feof(temp))
			{
				break;
			}
			fwrite(&contactInfo, sizeof(contactInfo), 1, fp);
		}
		fclose(fp);
		fclose(temp);
	}
}

void deleteByPhone()
{
	FILE *fp, *temp;
	ContactInfo contactInfo;
	int found = 0;
	char myNumber[32];

	fp = fopen(DEFAULT_FILE, "rb");
	temp = fopen("temp.dat", "wb");

	printf("Enter the phone number: ");
	scanf("%s", &myNumber);
	while (1)
	{
		fread(&contactInfo, sizeof(contactInfo), 1, fp);
		//reaches the end of the file, break
		if (feof(fp))
		{
			break;
		}
		//if the string matches, set found = 1, don't write to file
		if (strcmp(contactInfo.phone_number, myNumber) == 0)
		{
			found = 1;
		}
		else
		{
			//else, copy main file's data into a temp file
			fwrite(&contactInfo, sizeof(contactInfo), 1, temp);
		}
	}

	if (found == 0)
	{
		printf("Could not find the contact.\n");
	}
	else
	{
		//read from temp file and write to main file.
		while (1)
		{
			fread(&contactInfo, sizeof(contactInfo), 1, temp);
			if (feof(temp))
			{
				break;
			}
			fwrite(&contactInfo, sizeof(contactInfo), 1, fp);
		}
		fclose(fp);
		fclose(temp);
	}
}

void deleteByEmail()
{
	FILE *fp, *temp;
	ContactInfo contactInfo;
	int found = 0;
	char myEmail[32];

	fp = fopen(DEFAULT_FILE, "rb");
	temp = fopen("temp.dat", "wb");

	printf("Enter the email: ");
	scanf("%s", &myEmail);
	while (1)
	{
		fread(&contactInfo, sizeof(contactInfo), 1, fp);
		//reaches the end of the file, break
		if (feof(fp))
		{
			break;
		}
		//if the string matches, set found = 1, don't write to file
		if (strcmp(contactInfo.email_address, myEmail) == 0)
		{
			found = 1;
		}
		else
		{
			//else, copy main file's data into a temp file
			fwrite(&contactInfo, sizeof(contactInfo), 1, temp);
		}
	}

	if (found == 0)
	{
		printf("Could not find the contact.\n");
	}
	else
	{
		//read from temp file and write to main file.
		while (1)
		{
			fread(&contactInfo, sizeof(contactInfo), 1, temp);
			if (feof(temp))
			{
				break;
			}
			fwrite(&contactInfo, sizeof(contactInfo), 1, fp);
		}
		fclose(fp);
		fclose(temp);
	}
}

Status delete_contact()
{
	int option;

	do
	{
		delete_contacts_menu();

		option = get_option(NUM, "");

		switch (option)
		{
		case e_first_opt:
			break;
		case e_second_opt:
			deleteByName();
			break;
		case e_third_opt:
			deleteByPhone();
			break;
		case e_fourth_opt:
			deleteByEmail();
			break;
		}
	} while (option != e_exit);

	return e_success;
}

int main()
{
	menu();
	return 0;
}