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
