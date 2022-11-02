#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXLEN 20
#define NumOfEntries 3

typedef struct entry
{
	char firstName[MAXLEN];
	char lastName[MAXLEN];
	char address[MAXLEN];
	int age;

} ENTRY;

typedef struct data
{
	bool status;
	ENTRY data;

} DATA;

void FIllStructureArray(DATA info[]);
void LoadInfoFromDisk(DATA info[]);
void SaveInfoFromDisk(DATA info[]);

void PrintArray(DATA info[]);
void EnterDataEntry(DATA info[], ENTRY name);


int main()
{

	DATA info[NumOfEntries];
	ENTRY name;

	FIllStructureArray(info);
	PrintArray(info);
	
	LoadInfoFromDisk(info);
	PrintArray(info);

	printf("\n------\n");
	printf("Enter your first name: ");
	fgets(name.firstName, sizeof(name.firstName), stdin);
	name.firstName[strlen(name.firstName) - 1] = '\0'; //fgets adds a \n to the end of the string, which ruins the formatting of the save file.

	printf("Enter your last name: ");
	fgets(name.lastName, sizeof(name.lastName), stdin);
	name.lastName[strlen(name.lastName) - 1] = '\0';

	printf("Enter your address: ");
	fgets(name.address, sizeof(name.address), stdin);
	name.address[strlen(name.address) - 1] = '\0';

	printf("Enter your age: ");
	scanf_s("%d", &name.age);
	printf("\n------\n");

	EnterDataEntry(info, name);

	PrintArray(info);

	SaveInfoFromDisk(info);

	return 0;
}

void PrintArray(DATA info[])
{
	printf("\n------------------------------\n");
	for (int i = 0; i < NumOfEntries; i++)
	{
		printf("\n~~~\n");
		printf("First Name: %s\n", info[i].data.firstName);
		printf("Last Name: %s\n", info[i].data.lastName);
		printf("Address: %s\n", info[i].data.address);
		printf("Age: %d\n", info[i].data.age);
	}
}

void EnterDataEntry(DATA info[], ENTRY name)
{
	for (int i = 0; i < NumOfEntries; i++)
	{
		if (info[i].status != true)
		{
			info[i].status = true;
			info[i].data = name;
			break;
		}
	}
}

void FIllStructureArray(DATA info[])
{
	for (int i = 0; i < NumOfEntries; i++)
	{
		info[i].status = false;
		strcpy(info[i].data.firstName, "\0");
		strcpy(info[i].data.lastName, "\0");
		strcpy(info[i].data.address, "\0");
		info[i].data.age = 0;
	}
}

void LoadInfoFromDisk(DATA info[])
{
	char tempStatus[MAXLEN];
	char tempFirst[MAXLEN];
	char tempLast[MAXLEN];
	char tempAddress[MAXLEN];
	char tempAge[MAXLEN];
	
	FILE* LoadData_fp;

	if ((LoadData_fp = fopen("Info.txt", "r")) == NULL)
	{
		printf("Can't Open");
		exit(1);
	}

	for (int i = 0; i < NumOfEntries; i++)
	{
		fgets(tempStatus, MAXLEN, LoadData_fp);
		info[i].status = atoi(tempStatus);
		
		fgets(tempFirst, MAXLEN, LoadData_fp);
		tempFirst[strlen(tempFirst) - 1] = '\0';
		strcpy(info[i].data.firstName, tempFirst, MAXLEN);

		fgets(tempLast, MAXLEN, LoadData_fp);
		tempLast[strlen(tempLast) - 1] = '\0';
		strcpy(info[i].data.lastName, tempLast, MAXLEN);

		fgets(tempAddress, MAXLEN, LoadData_fp);
		tempAddress[strlen(tempAddress) - 1] = '\0';
		strcpy(info[i].data.address, tempAddress, MAXLEN);

		fgets(tempAge, MAXLEN, LoadData_fp);
		info[i].data.age = atoi(tempAge);
	}

	fclose(LoadData_fp);
}

void SaveInfoFromDisk(DATA info[])
{
	FILE* SaveData_fp;

	if ((SaveData_fp = fopen("Info.txt", "w")) == NULL)
	{
		printf("Can't Open");
		exit(1);
	}

	for (int i = 0; i < NumOfEntries; i++)
	{
		fprintf(SaveData_fp, "%d\n", info[i].status);
		fprintf(SaveData_fp, "%s\n", info[i].data.firstName);
		fprintf(SaveData_fp, "%s\n", info[i].data.lastName);
		fprintf(SaveData_fp, "%s\n", info[i].data.address);
		fprintf(SaveData_fp, "%d\n", info[i].data.age);
	}

	fclose(SaveData_fp);

}