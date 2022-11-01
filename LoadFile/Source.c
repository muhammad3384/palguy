//Read info from a file (Load)

//Let's build an example that loads our four pieces of saved information:
// First name, Last name, Address, Age

#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h> // exit() prototype

#define MAXLEN 20

int main()
{
	char tempFirst[MAXLEN];
	char tempLast[MAXLEN];
	char tempAddress[MAXLEN];
	char tempAge[MAXLEN];

	FILE* SaveData_fp;

	if ((SaveData_fp = fopen("Saved Info.txt", "r")) == NULL)
	{
		printf("Can't Open");
		exit(1);
	}

	char first_name[MAXLEN];
	char last_name[MAXLEN];
	char address[MAXLEN];
	int age;

	fgets(tempFirst, MAXLEN, SaveData_fp);
	tempFirst[strlen(tempFirst) - 1] = '\0';
	strcpy(first_name, tempFirst, MAXLEN);

	fgets(tempLast, MAXLEN, SaveData_fp);
	tempLast[strlen(tempLast) - 1] = '\0';
	strcpy(last_name, tempLast, MAXLEN);

	fgets(tempAddress, MAXLEN, SaveData_fp);
	tempAddress[strlen(tempAddress) - 1] = '\0';
	strcpy(address, tempAddress, MAXLEN);

	fgets(tempAge, MAXLEN, SaveData_fp);
	age = atoi(tempAge);

	printf("First Name: %s \n", first_name);
	printf("Last Name: %s \n", last_name);
	printf("Address: %s \n", address);
	printf("Age: %d \n", age);

	return 0;
}