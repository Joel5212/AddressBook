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
int main(void)
{
}

void delete_contact(){
	FILE *fp, *fp1;
	struct AddressBook ab, ab2;
	int id, choice, found = 0, count = 0;
	char[] name;
	printf("Make a menu");
	scanf("%d",&choice);
	while(1){
		fread(&ab, sizeof(ab),1,fp);
		//reaches the end of the file, break
		if(feof(fp){
			break;
		}
		if(strcmp(ab.name, name) ==0){
			found = 1;
		}
		else{
			fwrite(&ab,sizeof(ab), 1, fp1);
			
		}
	}
	


}