/*Main method that groups all of the subfiles together
-Calls load_file() from address_book_fops.c
If it returns the Status e_success:
	-Call menu() from address_book_menu.c which calls compiles all of the methods into one method
		-After the menu() is called, calls save_prompt() from address_book_menu.c it prompts the user to save the file,
		prompting the method save_file() from address_book_foops.c*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "address_book.h"
typedef struct
{
	char name[32];
	int phoneNumbers;
	char emailAddresses[32];
	int serialNumber;
} AddressBook;

int main(void)
{
}

void delete_contact(){
	FILE *fp, *fp1;
	struct AddressBook ab, ab2;
	int id, choice, found = 0, count = 0;
	fp = fopen(DEFAULT_FILE, "rb");
	fp1 = fopen(DEFAULT_FILE, "wb");
	

	printf("####### Search Contact to Delete by:\n\n");
	printf("0. Back\n");
	printf("1. Name\n");
	printf("2. Phone No\n");
	printf("3. Email ID\n");
	printf("4. Serial No\n\n");

	choice: ;
	printf("Please select an option: ");
	scanf("%d",&choice);
	if(choice == 0){
		//goes back a menu in the program
	}
	else if(choice == 1){
		char name[32];
		printf("Enter the name: ");
		scanf("%s", &name);
		while(1){
			fread(&ab, sizeof(ab), 1, fp);
			//reaches the end of the file, break
			if(feof(fp){
				break;
			}
			if(strcmp(ab.name, &name) == 0){
				found = 1;
			}
			else{
				fwrite(&ab, sizeof(ab), 1, fp1);
			}	
		}	
	}
	else if(choice == 2){
		int phoneNumber;
		printf("Enter a phone number: ");
		scanf("%d", &phoneNumber);
		while(1){
			fread(&ab, sizeof(ab),1,fp);
			if(feof(fp){
				break;
			}
			if(ab.phoneNumbers == phoneNumber){
				found = 1;
			}
			else{
				fwrite(&ab,sizeof(ab), 1, fp1);
			}
		}
	}
	else if(choice == 3){
		char email[32] ;
		printf("Enter the email: ");
		scanf("%s", &email);
		while(1){
			fread(&ab, sizeof(ab), 1, fp);
		
			if(feof(fp){
				break;
			}
			if(strcmp(ab.name, &email) == 0){
				found = 1;
			}
			else{
				fwrite(&ab, sizeof(ab), 1, fp1);
			}	
		}
	}
	else if(choice == 4){
		int serialNumber;
		printf("Enter a serial number: ");
		scanf("%d", &serialNumber);
		while(1){
			fread(&ab, sizeof(ab),1,fp);
			if(feof(fp){
				break;
			}
			if(ab.serialNumbers == serialNumber){
				found = 1;
			}
			else{
				fwrite(&ab,sizeof(ab), 1, fp1);
			}
		}
	}
	else{
		goto choice;
	}
	fclose(fp);
	fclose(fp1);
	if(found == 0)
	{
		printf("Could not find the contact.\n");
	}
	else{
		fp = fopen(fname, "wb");
		fp1 = fopen("temp.text", "rb");
	}
	while(1){
		fread(&ab, sizeof(ab), 1, fp1);
		if(feof(fp1)){
			break;
		}
		fwrite(&ab, sizeof(ab), 1, fp);
	}
	fclose(fp);
	fclose(fp1);



}