/*Header file that contains typedefs of Modes, MenuOptions, Status, MenuFeatures, ContactInfo, and AddressBook*/

#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

#define DEFAULT_FILE "address_book.csv"
typedef struct
{
	char name[32];
	char phoneNumbers[32];
	char emailAddresses[32];
} ContactInfo;

#endif
