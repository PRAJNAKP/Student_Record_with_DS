//Funs to delete nodes

#include"header.h"
void delet(SLL **ptr)
{
	if(*ptr==0)
	{
		printf("No records found\n");
		return;
	}
	char op;
	printf("R/r:Enter to del roll num\n");
	printf("N/n:Enter to del name\n");
	scanf(" %c",&op);
	if(op>='A'&& op<='Z')
		op^=32;
	switch(op)
	{
		case 'r':del_roll(ptr);break;
		case 'n':del_name(ptr);break;
		default:printf("Invalid option in deleting file\n");
	}
}
void del_roll(SLL **ptr)
{
	SLL *del,*prev;
	int roll;
	printf("Enter the roll no\n");
	scanf(" %d",&roll);
	del=*ptr;		
	while(del)
	{
		if(del->rollno==roll)
		{
			if(del==*ptr)
				*ptr=del->next;
			else
				prev->next=del->next;
			free(del);
			return;
		}
		prev=del;
		del=del->next;
	}
	printf("roll num not found in database\n");
}


void del_name(SLL **ptr)
{
	SLL *del=*ptr,*prev;
	char name[30];
	int c=0;
	printf("Enter the name to del\n");
	scanf(" %s",name);
	while(del)
	{
		if(strcmp(del->name,name)==0)
			c++;
		del=del->next;
	}
	del=*ptr;
	if(c>1)
	{
		while(del)
		{
		if(strcmp(del->name,name)==0)
		printf("%d %s %f\n",del->rollno,del->name,del->marks);
		del=del->next;
		}
		del_roll(ptr);
		printf("%s deleted\n",name);
	}
	del=*ptr;
	if(c==1)
	{
		while(del)
		{
			if(strcmp(del->name,name)==0)
			{
				if(del==*ptr)
				*ptr=del->next;
			else
				prev->next=del->next;
			free(del);
			return;
		}
		prev=del;
		del=del->next;
		}
	}
	else
		printf("Name not found in data base\n");
}

void del_all(SLL **ptr)
{
	if(*ptr==0)
	{
		printf("No records found\n");
		return;
	}
	SLL *del=*ptr;
	while(del)
	{
		*ptr=del->next;
		free(del);
		del=*ptr;
	}
	printf("All nodes deleted\n");
}
