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
#include "address_book_menu.h"

struct ContactInfo
{
	char name[32];
	char phoneNumbers[32];
	char emailAddresses[32];
};

/* Printing a menu for when the edit option is prompted*/
printf("==================Address Book=============");
printf("======== Search Contact to edit by==========\n\n")

printf("1. Name\n\n");
printf("2. PhoneNumber\n\n");
printf("3. Email\n\n");
printf("0. Exit\n\n");

printf("========================================================\n\n");

printf("\nPlease enter your Choice:");
scanf("%d",&editc);

/* Switch case for the 3 cases he wants*/
switch (editc)
{
    case 1: name();
    break;

    case 2: phoneNumbers();
    break;

    case 3: email();
    break;

    case 0: exit(0);
}

/* Edit by name case */
void name()

{
FILE *fp,*fp1;
struct emp t,t1;
int name ,found=0,count=0;


fp=fopen(fname,"rb");
fp1=fopen("temp.dat","wb");

/* Prompt user to enter employee name as thats what has been chosen for editing*/
/* Save it to temporary */

printf("\nEnter the Employee Name you want to edit:");
scanf("%d",&name);

/* while loop till either name is found and changed or not found*/
while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
if(t.name==name)
{
found=1;
printf("\nEnter Employee Email:");
scanf("%d",&t.email);

fflush(stdin);
printf("\nEnter Employee Name:");
scanf("%s",t.name);
printf("\nEnter Employee Phone number:");
scanf("%d",&t.phoneNumbers);
fwrite(&t,sizeof(t),1,fp1);
}
else
{
fwrite(&t,sizeof(t),1,fp1);
}
}
fclose(fp);
fclose(fp1);

if(found==0)
{
printf("Sorry No Record Found\n\n");
}
else
{
fp=fopen(fname,"wb");
fp1=fopen("temp.dat","rb");

while(1)
{
fread(&t,sizeof(t),1,fp1);

if(feof(fp1))
{
break;
}
fwrite(&t,sizeof(t),1,fp);
}

}
fclose(fp);
fclose(fp1);
}

/* Edit by phone number case */

void phoneNumbers()
{
FILE *fp,*fp1;
struct emp t,t1;
int phoneNumbers ,found=0,count=0;


fp=fopen(fname,"rb");
fp1=fopen("temp.dat","wb");

printf("\nEnter the Employee Phone number you want to edit:");
scanf("%d",&phoneNumbers);

while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
if(t.phoneNumbers==phoneNumbers)
{
found=1;
printf("\nEnter New Employee Email:");
scanf("%d",&t.email);

fflush(stdin);
printf("\nEnter New Employee Name:");
scanf("%s",t.name);
printf("\nEnter New Employee Phone number:");
scanf("%d",&t.phoneNumbers);
fwrite(&t,sizeof(t),1,fp1);
}
else
{
fwrite(&t,sizeof(t),1,fp1);
}
}
fclose(fp);
fclose(fp1);

if(found==0)
{
printf("Sorry No Record Found\n\n");
}
else
{
fp=fopen(fname,"wb");
fp1=fopen("temp.dat","rb");

while(1)
{
fread(&t,sizeof(t),1,fp1);

if(feof(fp1))
{
break;
}
fwrite(&t,sizeof(t),1,fp);
}

}
fclose(fp);
fclose(fp1);
}

/* Edit by email case */
void email()
{
FILE *fp,*fp1;
struct emp t,t1;
int email ,found=0,count=0;


fp=fopen(fname,"rb");
fp1=fopen("temp.dat","wb");

printf("\nEnter the Employee email you want to edit:");
scanf("%d",&email);

while(1)
{
fread(&t,sizeof(t),1,fp);

if(feof(fp))
{
break;
}
if(t.email==email)
{
found=1;
printf("\nEnter New Employee Email:");
scanf("%d",&t.email);

fflush(stdin);
printf("\nEnter New Employee Name:");
scanf("%s",t.name);
printf("\nEnter New Employee Phone number:");
scanf("%d",&t.phoneNumbers);
fwrite(&t,sizeof(t),1,fp1);
}
else
{
fwrite(&t,sizeof(t),1,fp1);
}
}
fclose(fp);
fclose(fp1);

if(found==0)
{
printf("Sorry No Record Found\n\n");
}
else
{
fp=fopen(fname,"wb");
fp1=fopen("temp.dat","rb");

while(1)
{
fread(&t,sizeof(t),1,fp1);

if(feof(fp1))
{
break;
}
fwrite(&t,sizeof(t),1,fp);
}

}
fclose(fp);
fclose(fp1);
}