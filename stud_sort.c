//Sorting data

#include"header.h"
void sort(SLL *ptr)
{
	if(ptr==0)
	{
		printf("No records found\n");
		return;
	}
	char op;
	printf("Enter\n N/n:Sort with name\n P/p:sort with percentage\n");
	scanf(" %c",&op);
	if(op>='A'&& op<='Z')
		op=op^32;
	switch(op){
		case 'n':sort_name(ptr);break;
		case 'p':sort_percent(ptr);break;
		default:printf("invalid choice\n");
		}
}


void sort_roll(SLL *ptr){
	if(ptr==0){
	//	printf("no records\n");
		return;}
	int i,j,c=count_node(ptr);
	SLL *p1=ptr,*p2,temp;
	for(i=0;i<c-1;i++)
	{
		p2=p1->next;
		for(j=0;j<c-1-i;j++)
		{
			if(p1->rollno>p2->rollno)
			{
				temp.rollno=p1->rollno;
				strcpy(temp.name,p1->name);
				temp.marks=p1->marks;

				p1->rollno=p2->rollno;
				strcpy(p1->name,p2->name);
				p1->marks=p2->marks;
				
				p2->rollno=temp.rollno;
				strcpy(p2->name,temp.name);
				p2->marks=temp.marks;
			}
			p2=p2->next;
		}
		p1=p1->next;
	}
}

void sort_name(SLL *ptr){
	if(ptr==0){
		printf("no records\n");
		return;}
	int i,j,c=count_node(ptr);
	SLL *p1=ptr,*p2,temp;
	for(i=0;i<c-1;i++){
		p2=p1->next;
		for(j=0;j<c-1-i;j++){
			if(strcmp(p1->name,p2->name)>0)
			{
				temp.rollno=p1->rollno;
				strcpy(temp.name,p1->name);
				temp.marks=p1->marks;

				p1->rollno=p2->rollno;
				strcpy(p1->name,p2->name);
				p1->marks=p2->marks;
				
				p2->rollno=temp.rollno;
				strcpy(p2->name,temp.name);
				p2->marks=temp.marks;
			}
			p2=p2->next;
		}
		p1=p1->next;
	}
 	show(ptr);
}


void sort_percent(SLL *ptr){
	if(ptr==0){
		printf("no records\n");
		return;}
	int i,j,c=count_node(ptr);
	SLL *p1=ptr,*p2,temp;
	for(i=0;i<c-1;i++){
		p2=p1->next;
		for(j=0;j<c-1-i;j++){
			if(p1->marks>p2->marks){
				temp.rollno=p1->rollno;
				strcpy(temp.name,p1->name);
				temp.marks=p1->marks;

				p1->rollno=p2->rollno;
				strcpy(p1->name,p2->name);
				p1->marks=p2->marks;
				
				p2->rollno=temp.rollno;
				strcpy(p2->name,temp.name);
				p2->marks=temp.marks;
			}
			p2=p2->next;
		}
		p1=p1->next;
	}
 	show(ptr);
}
