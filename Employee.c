#include<stdio.h>
#include<stdlib.h>

#define ADD 1
#define DELETE 2
#define MODIFY 3
#define FIND 4
#define SAVE 5
#define LOAD 6
#define DISPLAY_ALL 7
#define QUIT 8

struct emp{
	int code;
	char name[20];
	char address[20];
	int salary;
	char phoneNo[10];
};

struct node{
	struct emp *e;
	struct node *next;
};

struct node *list;

struct emp * getEmployee(){
	struct emp *e = (struct emp *)malloc(sizeof(struct emp));
	printf("\n Enter Employee details...\n");
	printf(" Code : ");			scanf("%d",&(e->code));
	printf(" Name : ");			scanf("%s",e->name);
	printf(" Salary : ");		scanf("%d",&(e->salary));
	printf(" Phone no : ");		scanf("%s",e->phoneNo);
	printf(" Address : ");		scanf("%s",e->address);
	return e;
}

void printHeader(){
	char str[] = "---------------------------------------------------------";
	printf("\n|%-5.7s|%-10.12s|%10.12s|%10.12s|%20.22s|",str,str,str,str,str);
	printf("\n| %-5s | %-10s | %-10s | %-10s | %-20s |","Code","Name","Salary","Phone No","Address"); 
	printf("\n|%-5.7s|%-10.12s|%10.12s|%10.12s|%20.22s|",str,str,str,str,str);
}

void printFooter(){
	char str[] = "---------------------------------------------------------";
	printf("\n|%-5.7s|%-10.12s|%10.12s|%10.12s|%20.22s|",str,str,str,str,str);
}

void printEmployee(struct emp *e){
	printf("\n| %-5d | %-10s | %-10d | %-10s | %-20s |",e->code,e->name,e->salary,e->phoneNo,e->address); 
}

void addEmployee(){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->e = getEmployee();
	temp->next = NULL;
	if(list==NULL)		list = temp;
	else{
		struct node *ptr = NULL;
		for(ptr = list; ptr->next!=NULL; ptr = ptr->next);
		ptr->next = temp;
	}
}

void deleteEmployee(){
	if(list==NULL)		printf("\n List Empty!");
	else{
		int code;
		printf("\n Enter Emp code : ");
		scanf("%d",&code);
		struct node *ptr = list;
		struct emp *e = ptr->e;
		if(e->code==code){
			printHeader();
			printEmployee(list->e);
			list = list->next;
			printFooter();
		}else{
			while(ptr->next!=NULL && (ptr->next->e->code)!=code)
				ptr = ptr->next;
			if(ptr->next==NULL)		printf("\n Employee not found!");
			else{
				printHeader();
				printEmployee(ptr->next->e);
				ptr->next = ptr->next->next;
				printFooter();
			}
		}		
	}
}

void findEmployee(){
	int code;
	printf("\n Enter Emp code : ");
	scanf("%d",&code);
	struct node *ptr = list;
	while(ptr!=NULL && ptr->e->code != code)
		ptr = ptr->next;
	if(ptr==NULL)		printf("\n Employee not found!");
	else{
		printHeader();
		printEmployee(ptr->e);
		printFooter();
	}
}

void modifyEmployee(){
	if(list==NULL)		printf("\n List Empty!");
	else{
		int code;
		printf("\n Enter Emp code : ");
		scanf("%d",&code);
		struct node *ptr = list;
		struct emp *e = ptr->e;
		if(e->code==code){
			printHeader();
			printEmployee(list->e);
			printFooter();
			list->e = getEmployee();
		}else{
			while(ptr->next!=NULL && (ptr->next->e->code)!=code)
				ptr = ptr->next;
			if(ptr->next==NULL)		printf("\n Employee not found!");
			else{
				printHeader();
				printEmployee(ptr->next->e);
				printFooter();
				struct node *temp = (struct node *)malloc(sizeof(struct node));
				temp->e = getEmployee();
				temp->next = ptr->next->next;
				ptr->next = temp;
			}
		}		
	}
}

void save(){
	char fileName[10];
	printf("\n Type FileName : ");
	scanf("%s",fileName);
	FILE *fp = fopen(fileName,"w+");
	struct node *ptr = list;
	int count = 0;
	for(ptr = list; ptr!=NULL; ptr = ptr->next, count++);
	fprintf(fp,"%d\n",count);
	for(ptr = list; ptr!=NULL; ptr = ptr->next, count++)
		fprintf(fp,"%d %s %d %s %s\n",ptr->e->code, ptr->e->name, ptr->e->salary, ptr->e->phoneNo, ptr->e->address);
	fclose(fp);
}

void load(){
	char fileName[10];
	printf("\n Type FileName : ");
	scanf("%s",fileName);
	FILE *fp = fopen(fileName,"r");
	int count = 0;
	fscanf(fp,"%d\n",&count);
	struct emp *e = (struct emp *) malloc(sizeof(struct node));
	printHeader();
	while(count-- > 0){
		fscanf(fp,"%d %s %d %s %s\n",&(e->code), e->name, &(e->salary), e->phoneNo, e->address);
		printEmployee(e);
	}
	printFooter();
}

void printAllEmployee(){
	printHeader();
	struct node *ptr;
	for(ptr = list; ptr!=NULL; ptr = ptr->next)
		printEmployee(ptr->e);
	printFooter();
}

int main(){
	list = NULL;
	int choice;
	do{
		printf("\n");
		printf("\n %d. ADD",ADD);
		printf("\n %d. DELETE",DELETE);
		printf("\n %d. MODIFY",MODIFY);
		printf("\n %d. FIND",FIND);
		printf("\n %d. SAVE",SAVE);
		printf("\n %d. LOAD",LOAD);
		printf("\n %d. DISPLAY ALL",DISPLAY_ALL);
		printf("\n %d. QUIT",QUIT);
		printf("\n choice : "); 
		scanf("%d",&choice);
		switch(choice){
			case ADD 		 : 	addEmployee();
								break;
			case DELETE 	 : 	deleteEmployee();
								break;
			case MODIFY		 :	modifyEmployee();
								break;
			case FIND		 :	findEmployee();
								break;
			case SAVE		 :	save();
								break;
			case DISPLAY_ALL : 	printAllEmployee();
								break;
			case LOAD		 :	load();
								break;
			default			 : exit(0);
		}
	}while(choice!=QUIT);
}