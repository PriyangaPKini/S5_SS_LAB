#include<string.h>
#include<stdlib.h>
#include<stdio.h>
struct
{
	char dname[10],fname[10][10];
	int fcnt;
}dir[10];

int i,ch,dcnt=0,k;
char f[30], d[30];


void createdir(){
	printf("\nEnter name of directory -- ");
	scanf("%s", dir[dcnt].dname);
	dir[dcnt].fcnt=0;
	dcnt++;
	printf("Directory created");

}
void createfile()
{
	int flag=0;
	printf("\nEnter name of the directory -- ");
	scanf("%s",d);
	for(i=0;i<dcnt;i++){
		if(strcmp(d,dir[i].dname)==0)
		{
			printf("Enter name of the file -- ");
			scanf("%s",dir[i].fname[dir[i].fcnt++]);
			printf("File created");
			flag=1;
			break;
		}
	}
	if(flag==0)
		printf("Directory %s not found",d);
}

void delete(){
	printf("\nEnter name of the directory -- ");
	scanf("%s",d);
	for(i=0;i<dcnt;i++)
	{
		if(strcmp(d,dir[i].dname)==0)
		{
			printf("Enter name of the file -- ");
			scanf("%s",f);
			for(k=0;k<dir[i].fcnt;k++)
			{
				if(strcmp(f, dir[i].fname[k])==0)
				{
					printf("File %s is deleted ",f);
					dir[i].fcnt--;
					strcpy(dir[i].fname[k],dir[i].fname[dir[i].fcnt]);
					break;
				}
			}
			printf("File %s not found",f);
			break;
		}
	}
	printf("Directory %s not found",d);


}
void search(){
	printf("\nEnter name of the directory -- ");
	scanf("%s",d);
	for(i=0;i<dcnt;i++)
	{
		if(strcmp(d,dir[i].dname)==0)
		{
			printf("Enter the name of the file -- ");
			scanf("%s",f);
			for(k=0;k<dir[i].fcnt;k++)
			{
				if(strcmp(f, dir[i].fname[k])==0)
				{
					printf("File %s is found ",f);
					break;
				}
			}
			printf("File %s not found",f);
			break;
		}
	}
	printf("Directory %s not found",d);


}

void display(){
	if(dcnt==0)
		printf("\nNo Directories ");
	else
	{

		for(i=0;i<dcnt;i++)
		{
			printf("\n*%s*\t",dir[i].dname);
			for(k=0;k<dir[i].fcnt;k++)
				printf("%s\t",dir[i].fname[k]);
		}
	}

}


void main()
{

while(1)
{
	printf("\n\n1. Create Directory\n2. Create File\n3. Delete File");
	printf("\n4. Search File\n5. Display\n6. Exit\n\nEnter your choice -- ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: createdir();
				break;

		case 2: createfile();
				break;

		case 3: delete();
			break;

		case 4: search();
				break;
		case 5: display();
				break;

		default:exit(0);
	}
}
}

