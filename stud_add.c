//Add begin

#include"header.h"
void add_new_record(SLL **ptr)
{
	 SLL *new,*pre=*ptr,*last;
	 new=(SLL*)malloc(sizeof(SLL));
	 int i,f=0,c=count_node(*ptr);
	 sort_roll(*ptr);
	 if(*ptr==0){
	 new->rollno=1;
	 }
	 else
 	 {
		 for(i=1;i<=c;i++)
		 {
			 if(pre->rollno==i)
			 {
				 pre=pre->next;
				 if(pre==0)
					 f=1;
			 }
			 else
			 {
				 f=1;
				 break;
			 }
		 }
		 if(f==1)
		 {
			 f=0;
			 new->rollno=i;
		 }
	 }
	 printf("Enter the student name and percent\n");
	 scanf(" %s %f",new->name,&new->marks);
	 if((*ptr==0)||(new->rollno<(*ptr)->rollno))
	 {
		 new->next=*ptr;
		 *ptr=new;
	 }
	 else
	 {
		last=*ptr;
	 	while((last->next!=0) && (new->rollno)>(last->next->rollno))	
 	 	last=last->next;
	 	last->next=new;
	 }
}




		 last=*ptr;
		 while(last->next)
			 last=last->next;
		 last->next=new;
	 }





int count_node(SLL *ptr){
	int c=0;
	while(ptr){
		c++;
		ptr=ptr->next;
	}
	return c;
}

