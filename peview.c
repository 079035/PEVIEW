#include <stdio.h>
#include <string.h>

int main()

{

        FILE *fp;

        char str[100]={0,};

        char name[100][100]={0,};

        int num[100];

        char fn[1000];

        int t,d;

        printf("type file name : ");

        scanf("%s", fn);



        fp=fopen(fn,"rt"); //파일경로에 공백 x



        if(fp==NULL){

               printf("error!\n");

        }

        //fprintf(fp,"Hello world\n");

        fseek(fp,0,SEEK_SET);

        fread(str,2,1,fp);

        printf("\tName\t\t\tData\t  value \n");



        printf("Dod_Header_Signature : ");

        printf(" \t%x%x\t  %s\n",*(str+1),*str,str);

        printf("\n");



        fseek(fp,60,SEEK_SET);



        fread(num,4,1,fp);

        printf("\te_flanew     :");

        printf("\t\t%.8x  \n", *num);

        printf("\n");

        t=*num;



        fseek(fp,t,SEEK_SET);

        fread(num,4,1,fp);

        printf("NT_Header_Signature  :");

        printf("\t\t%.8x  \n", *num);

        printf("\n");



        fseek(fp,t+4,SEEK_SET);

        fread(num,2,1,fp);

        printf("\tmachine\t     :");

        printf("\t\t%.8x  \n", *num);

        printf("\n");



        fread(num,2,1,fp);

        printf("Number of Sections   :");

        printf("\t\t%.8x  \n", *num);

        printf("\n");



        fseek(fp,t+20,SEEK_SET);



        fread(num,2,1,fp);

        printf("Size Of Optional Header:");

        printf("\t%.8x  \n", *num);

        printf("\n");



        fread(num,2,1,fp);

        printf("Characteristics\t      :\t");

        printf("\t%.8x  \n", *num);

        printf("\n");



        t=t+40;

        fread(num,2,1,fp);



        printf("Magic \t\t\t:");

        printf("\t%.8x  \n", *num);

        printf("\n");



        fseek(fp,t,SEEK_SET);



        fread(num,4,1,fp);

        printf("Address of Entry Point :");

        printf("\t%.8x  \n", *num);

        printf("\n");



        fseek(fp,t+12,SEEK_SET);



        fread(num,4,1,fp);

        printf("Image Base\t\t :");

        printf("\t%.8x  \n", *num);

        printf("\n");



        fread(num,4,1,fp);

        printf("Section Alignment\t :");

        printf("\t%.8x  \n", *num);

        printf("\n");



        fread(num,4,1,fp);

        printf("File Alignment\t\t :");

        printf("\t%.8x  \n", *num);

        printf("\n");



        t=t+40;

        fseek(fp,t,SEEK_SET);



        fread(num,4,1,fp); //130

        printf("Size of Image\t\t :");

        printf("\t%.8x  \n", *num);

        printf("\n");



        fread(num,4,1,fp);

        printf("Size of Headers\t\t :");

        printf("\t%.8x  \n", *num);

        printf("\n");



        fseek(fp,t+12,SEEK_SET);



        fread(num,2,1,fp);

        printf("Sybsystem\t\t :");

        printf("\t%.8x  \n", *num);

        printf("\n");



        t=t+36; //154

        fseek(fp,t,SEEK_SET);



        fread(num,4,1,fp);

        printf("Number of Data Directories :");

        printf("\t%.8x  \n", *num);

        printf("\n");



        t=0;

        strcpy(name[t],"EXPORT Table\t\t"),t++;

        strcpy(name[t],"IMPORT Table\t\t"),t++;

        strcpy(name[t],"RESOURCE Table\t\t"),t++;

        strcpy(name[t],"EXCEPTION Table\t\t"),t++;

        strcpy(name[t],"CERTIFICATE Table\t"),t++;

        strcpy(name[t],"BASE RELOCATION Table\t"),t++;

        strcpy(name[t],"DEBUG Directory\t\t"),t++;

        strcpy(name[t],"Architecture Specific Data"),t++;

        strcpy(name[t],"GLOBAL POINTER Register"),t++;

        strcpy(name[t],"TLS Table\t\t"),t++;

        strcpy(name[t],"LOAD CONFIGURATION Table"),t++;

        strcpy(name[t],"BOUND IMPORT Table \t"),t++;

        strcpy(name[t],"IMPORT Address Table\t"),t++;

        strcpy(name[t],"DELAY IMPORT Descriptors"),t++;

        strcpy(name[t],"CLI Header\t\t"),t++;

        strcpy(name[t],"\t\t\t"),t++;





        for(d=(*num),t=0;d!=0;d--,t++)

        {

        printf("\n");

        fread(num,4,1,fp);

        printf("%s :",name[t]);

        printf("\t%.8x  \n", *num);

        fread(num,4,1,fp);

        printf("\t\t\t\t%.8x  \n", *num);

        }





//      fclose(fp);



return 0;

}
