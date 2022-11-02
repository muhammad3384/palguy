//Write to a file (Save)

//Let's build an example that saves our four pieces of information:
// First name, Last name, Address, Age

#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h> // exit() prototype

#define MAXLEN 20

int main()
{
	FILE* SaveData_fp;

	if ((SaveData_fp = fopen("Info.txt", "w+")) == NULL)
	{
		printf("Can't Open");
		exit(1);
	}

	char first_name[MAXLEN];
	char last_name[MAXLEN];
	char address[MAXLEN];
	int age;

	printf("Enter your first name: ");
	fgets(first_name, sizeof(first_name), stdin);
	fprintf(SaveData_fp, "%s\n", first_name);

	printf("Enter your last name: ");
	fgets(last_name, sizeof(last_name), stdin);
	fprintf(SaveData_fp, "%s\n", last_name);

	printf("Enter your address: ");
	fgets(address, sizeof(address), stdin);
	fprintf(SaveData_fp, "%s\n", address);

	printf("Enter your age: ");
	scanf("%d", &age);
	fprintf(SaveData_fp, "%d\n", age);

	fclose(SaveData_fp);

	return 0;

}