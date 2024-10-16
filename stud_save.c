//Saving file

#include"header.h"
void exit_file(SLL *ptr){
	char c;
	printf("Enter:\ns:save and exit\ne:exit without saving\n");
	scanf(" %c",&c);
	switch(c){
		case 's':save_file(ptr);break;
		case 'e':exit(0);break;
		default:printf("Invalid choice in exit file\n");
	}
}


void save_file(SLL *ptr)
{
	sort_roll(ptr);
	FILE *fp;
	fp=fopen("student.dat","a+");
	if(fp==NULL){
		printf("Error in opening file\n");
		return;
	}
	if(ptr==0){
		printf("No records to save\n");
		return;
	}
	while(ptr){
		fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
		ptr=ptr->next;
	}
	fclose(fp);
	exit(0);

}
