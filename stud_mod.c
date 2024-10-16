/*modification file*/

#include"header.h"
void mod_record(SLL **ptr)
{
	if(*ptr==0)
	{
		printf("No records found\n");
		return;
	}
	char op;
	printf("Enter which record to search for modification\n"); 
	printf("R/r : To modify with rollno\n");
	printf("N/n : To modify name\n");
	printf("P/p : To modify percentage\n");
	scanf(" %c",&op);
	if(op>='A' && op<='Z')
		op=op^32;
	if(ptr==0)
	{
		printf("No records found\n");
		return;
	}
	switch(op){
		case 'r':mod_roll(ptr);break;
		case 'n':mod_name(ptr);break;
		case 'p':mod_percent(ptr);break;
		default :printf("invalid choice\n");
	}

}
void mod_roll(SLL **ptr)
{
	int roll,f=0;
	SLL *mod=*ptr;
	printf("Enter roll num to modify\n");
	scanf(" %d",&roll);
	while(mod)
	{
		if(mod->rollno==roll)
		{
			printf("%d %s %f\n",mod->rollno,mod->name,mod->marks);
			printf("Enter the modifying details - name and marks\n");
			scanf(" %s %f",mod->name,&mod->marks);
			f=1;
		}
		mod=mod->next;
	}
	if(f==0)
		printf("Roll num not found\n");
}
		


void mod_name(SLL **ptr)
{
	char name[30];
	int c=0;
	SLL *mod=*ptr;
	printf("Enter name to modify\n");
	scanf(" %s",name);
	while(mod)
	{
		if(strcmp(mod->name,name)==0){
		printf("%d %s %f\n",mod->rollno,mod->name,mod->marks);
		c++;
		}
		mod=mod->next;
	}
	mod=*ptr;
	if(c==0)
		printf("Name not found\n");
	else if(c>1)
	{
		printf("In the above list,Enter roll num to modify\n");
		int roll,f=0;
		scanf(" %d",&roll);
		while(mod)
		{
		if(mod->rollno==roll)
		{
			printf("%d %s %f\n",mod->rollno,mod->name,mod->marks);
			printf("Enter the modifying details - name\n");
			if((strcmp(mod->name,name)==0)&& mod->rollno==roll)
			{
				scanf(" %s",mod->name);
				f=1;
			}
		}
		mod=mod->next;
		}
		if(f==0)
			printf("Roll num not matched\n");
	}
	else
	{	
		while(mod)
		{
			if((strcmp(mod->name,name))==0)
				break;
			mod=mod->next;
		}
		printf("Enter the modifying detail-name\n");
		scanf(" %s",mod->name);
	}	
}

void mod_percent(SLL **ptr)
{
	float percen;
	int c=0;
	SLL *mod=*ptr;
	printf("Enter percent to modify\n");
	scanf(" %f",&percen);
	while(mod)
	{
		if(mod->marks==percen){
			printf("%d %s %f\n",mod->rollno,mod->name,mod->marks);
		c++;
		}
		mod=mod->next;
	}
	mod=*ptr;
	if(c==0)
		printf("Percentage not found\n");
	else if(c>1)
	{
		printf("In the above list,Enter roll num to modify\n");
		int roll,f=0;
		scanf(" %d",&roll);
		while(mod)
		{
		if(mod->rollno==roll)
		{
			printf("%d %s %f\n",mod->rollno,mod->name,mod->marks);
			printf("Enter the modifying details - percent\n");
			if((mod->marks==percen)&& mod->rollno==roll)
			{scanf(" %f",&mod->marks);
			f=1;
			}
		}
		mod=mod->next;
		}
		if(f==0)
			printf("Roll num not matched\n");
	}
	else
	{	
		while(mod)
		{
			if(mod->marks==percen)
				break;
			mod=mod->next;
		}
		printf("Enter the modifying detail-percent\n");
		scanf(" %f",&mod->marks);
	}	
}



void reverse_link(SLL **ptr){
	if(*ptr==0){
		printf("no records found\n");
		return;
	}
	int c=count_node(*ptr);
	SLL **arr,*temp=*ptr;
	if(c>1){
		arr=(SLL**)malloc(sizeof(SLL*)*c);
		int i=0;
		while(temp){
			arr[i++]=temp;
			temp=temp->next;
		}
		//Modifying link positions
		for(i=1;i<c;i++)
			arr[i]->next=arr[i-1];
		arr[0]->next=0;
		*ptr=arr[c-1];
	}
}




