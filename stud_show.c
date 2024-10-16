
//print_node in tabular form

#include"header.h"
void show(SLL *ptr){
	if(ptr==0)
	{
		printf("No records found\n");
		return;
	}
	while(ptr)
	{
		printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
}

