/*main function*/

#include"header.h"
int main()
{
	SLL *headptr=0;
	char op;
	int c=0;
while(1){
printf("*******STUDENT RECORD MENU********\n");
printf("a/A : Add new record\n");
printf("d/D : Delete a record\n");
printf("s/S : Show the list\n");
printf("m/M : Modify a record\n");
printf("v/V : Save\n");
printf("e/E : Exit\n");
printf("t/T : Sort the list\n");
printf("l/L : Delete all the records\n");
printf("r/R : Reverse the list\n");
printf("Enter your choice\n");
scanf(" %c",&op);
if(op>='A' && op<='Z')
	op=op^32;
switch(op){
	case 'a':add_new_record(&headptr);break;
	case 'd':delet(&headptr);break;
	case 's':show(headptr);break;
	case 'm':mod_record(&headptr);break;
	case 'v':save_file(headptr);break;
	case 'e':exit_file(headptr);break;
	case 't':sort(headptr);break;
	case 'l':del_all(&headptr);break;
	case 'r':reverse_link(&headptr);break;
	default :printf("Invalid input\n");
}
//sleep(1);
}
}




