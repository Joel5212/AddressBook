/*Header file that contains typedefs of Modes, MenuOptions, Status, MenuFeatures, ContactInfo, and AddressBook*/

#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

#define DEFAULT_FILE "address_book.csv"

/* Length of a contact name  */
#define NAME_LEN 32
/* Length of a phone number */
#define NUMBER_LEN 32
/* Length of an email address */
#define EMAIL_ID_LEN 32
#define SI_NO_LEN 32

typedef enum
{
	e_first_opt,
	e_second_opt,
	e_third_opt,
	e_fourth_opt,
	e_fifth_opt,
	e_sixth_opt,
	e_no_opt = '\n' - '0',
} MenuOptions;

typedef enum
{
	e_fail = -10,
	e_back,
	e_success,
	e_no_match,
	e_new_line,
} Status;

typedef enum
{
	e_exit,
	e_add_contact,
	e_search_contact,
	e_edit_contact,
	e_delete_contact,
	e_list_contacts,
	e_save
} MenuFeatures;

typedef struct
{
	char name[NAME_LEN];
	char phone_number[NUMBER_LEN];
	char email_address[EMAIL_ID_LEN];
	char si_no[SI_NO_LEN];
} ContactInfo;

#endif
