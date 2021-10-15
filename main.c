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
	char names[32];
	char phoneNumbers[32];
	char emailAddresses[32];
	char serialNumbers[32];
} AddressBook;

int main(void)
{
}

void delete_contact(){
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

	deleteOption: ;
	printf("Please select an option: ");
	scanf("%d",&choice);
	if(choice == 0){
		//goes back a menu in the program
	}
	else if(choice == 1){
		char myName[32];
		printf("Enter the name: ");
		scanf("%s", &myName);
		while(1){
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
	else if(choice == 2){
		char myNumber[32];
		printf("Enter a phone number: ");
		scanf("%s", &myNumber);
		while(1){
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
	else if(choice == 3){
		char myEmail[32] ;
		printf("Enter the email: ");
		scanf("%s", &myEmail);
		while(1){
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
	else if(choice == 4){
		char mySi[32];
		printf("Enter a serial number: ");
		scanf("%s", &mySi);
		while(1){
			fread(&ab, sizeof(ab), 1, fp);
			if(feof(fp){
				break;
			}
			if(strcmp(ab.serialNumbers, mySi) == 0){
				found = 1;
			}
			else{
				fwrite(&ab,sizeof(ab), 1, fp1);
			}
		}
	}
	else{
		goto deleteOption;
	}
	fclose(fp);
	fclose(fp1);
	
	if(found == 0)
	{
		printf("Could not find the contact.\n");
	}
	else{
		//read from temp file and write to main file.
		fp = fopen(DEFAULT_FILE, "wb");
		fp1 = fopen("temp.text", "rb");
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
	


}