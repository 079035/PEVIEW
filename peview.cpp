#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

int main() {
	FILE *fp;
	char str[100] = { 0, };
	char name[100][100] = { 0, };
	int num[100];
	char fn[1000];
	int t, d;
	cout << "type file name : ";
	cin >> fn;

	fp = fopen(fn, "rt");
	if (fp == NULL) {
		cout << "error!" << endl;
	}
	
	fseek(fp, 0, SEEK_SET);
	fread(str, 2, 1, fp);
	printf("\tName\t\t\tData\t  value \n");

	cout << "Dos_Header_Signature\t : ";
	printf(" \t%x%x\t  %s\n", *(str + 1), *str, str);
	cout << endl;

	fseek(fp, 60, SEEK_SET);

	fread(num, 4, 1, fp);
	printf("e_lfanew      \t    \t :");
	printf("\t%.8x  \n", *num);
	cout << endl;
	t = *num;

	fseek(fp, t + 4, SEEK_SET);
	fread(num, 2, 1, fp);
	printf("machine\t      \t    \t :");
	printf("\t%.8x  \n", *num);
	cout << endl;

	fread(num, 2, 1, fp);
	cout << "Number of Sections       :";
	printf("\t%.8x  \n", *num);
	cout << endl;

	fseek(fp, t + 20, SEEK_SET);
	
	fread(num, 2, 1, fp);
	cout << "Size of Optional Header  :";
	printf("\t%.8x  \n", *num);
	cout << endl;

	fread(num, 2, 1, fp);
	printf("Characteristics\t         :");
	printf("\t%.8x  \n", *num);
	cout << endl;

	t += 40;
	fread(num, 2, 1, fp);

	printf("Magic       \t\t :");
	printf("\t%.8x \n", *num);
	cout << endl;

	fseek(fp, t, SEEK_SET);

	fread(num, 4, 1, fp);
	printf("AddressOfEntryPoint      :");
	printf("\t%.8x \n", *num);
	cout << endl;

	fseek(fp, t + 12, SEEK_SET);

	fread(num, 4, 1, fp);
	printf("ImageBase       \t :");
	printf("\t%.8x \n", *num);
	cout << endl;

	fread(num, 4, 1, fp);
	printf("SectionAlignment       \t :");
	printf("\t%.8x \n", *num);
	cout << endl;

	fread(num, 4, 1, fp);
	printf("FileAlignment      \t :");
	printf("\t%.8x \n", *num);
	cout << endl;

	t += 40;

	fseek(fp, t, SEEK_SET);

	fread(num, 4, 1, fp);
	printf("SizeOfImage       \t :");
	printf("\t%.8x \n", *num);
	cout << endl;

	fread(num, 4, 1, fp);
	printf("SizeOfHeaders      \t :");
	printf("\t%.8x \n", *num);
	cout << endl;

	t += 12;

	fseek(fp, t, SEEK_SET);
	
	fread(num, 2, 1, fp);
	printf("Subsystem       \t :");
	printf("\t%.8x \n", *num);
	cout << endl;

	t += 24;

	fseek(fp, t, SEEK_SET);
	
	fread(num, 4, 1, fp);
	printf("NumberOfDataDirectories  :");
	printf("\t%.8x \n",*num);
	cout << endl;

	t = 0;
	strcpy(name[t], "EXPORT Table\t\t");
	t++;
	strcpy(name[t], "IMPORT Table\t\t");
	t++;
	strcpy(name[t], "RESOURCE Table\t\t");
	t++;
	strcpy(name[t], "EXCEPTION Table\t\t");
	t++;
	strcpy(name[t], "SECURITY Table\t\t");
	t++;
	strcpy(name[t], "BASE RELOCATION Table\t");
	t++;
	strcpy(name[t], "DEBUG Directory\t\t");
	t++;
	strcpy(name[t], "COPYRIGHT Table\t\t");
	t++;
	strcpy(name[t], "GLOBALPTR Table\t\t");
	t++;
	strcpy(name[t], "TLS Table\t\t");
	t++;
	strcpy(name[t], "LOAD_CONFIG Table\t");
	t++;
	strcpy(name[t], "BOUND_IMPORT Table\t");
	t++;
	strcpy(name[t], "IAT Table\t\t");
	t++;
	strcpy(name[t], "DELAY_IMPORT Descriptors");
	t++;
	strcpy(name[t], "COM_DESCRIPTOR Table\t");
	t++;
	strcpy(name[t], "Reserved Directory\t");
	t++;


	for (d = *num, t = 0; d != 0; d--, t++) {
		cout << endl;
		fread(num, 4, 1, fp);
		printf("%s :", name[t]);
		printf("\t%.8x \n", *num);
		fread(num, 4, 1, fp);
		printf("\t\t\t\t%.8x \n", *num);
	}

	fclose(fp);
	return 0;
}