/*This file handles creating, loading, writing to, and saving files. "address_book.csv"???*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <ctype.h>

#include "address_book.h"

Status load_file(AddressBook *address_book)
{
	/*
	uses the passed address of AddressBook so that you can access the internal FILE pointer fp
	so you don't have to instantiate a new FILE pointer
	*/
	int ret;
	ret = access(DEFAULT_FILE, F_OK);
	/* 
	 * Check for file existance
	 */

	if (ret == 0)
	{
		/* 
		 * Do the neccessary step to open the file
		 * Do error handling
		 */ 
		
		

		address_book->fp = fopen(DEFAULT_FILE, "r+");
		ContactInfo ContactTable[];
		if(address_book->fp == NULL){
			printf("Error: Could not open the file.\n");
			return e_fail;
		}
	}
	else
	{
		/* Create a file for adding entries */
		address_book->fp = fopen(DEFAULT_FILE, "r+");
	}

	return e_success;
}

Status save_file(AddressBook *address_book)
{
	/*
	 * Write contacts back to file.
	 * Re write the complete file currently
	 */ 
	address_book->list->email_addresses;
	address_book->list->name;
	address_book->list->phone_numbers;
	address_book->list->si_no;
	//address_book->fp = fopen(DEFAULT_FILE, "w");

	if (address_book->fp == NULL)
	{
		printf("Error: Could not find a file to write to.\n")
		return e_fail;
	}

	/* 
	 * Add the logic to save the file
	 * Make sure to do error handling
	 */ 

	fclose(address_book->fp);

	return e_success;
}
