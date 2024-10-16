#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>

typedef struct student
{
	int rollno;
	char name[30];
	float marks;
	struct student *next;
}SLL;

//Fun in stud_add.c 
extern void add_new_record(SLL **);
extern int count_node(SLL *);

//Fun in stud_del.c 
extern void delet(SLL **);
extern void del_all(SLL **);
extern void del_roll(SLL **);
extern void del_name(SLL **);

//Fun in stud_show.c file
extern void show(SLL *);

//Fun in stud_mod file
extern void mod_record(SLL **);
void mod_roll(SLL **);
void mod_name(SLL **);
void mod_percent(SLL **);
void reverse_link(SLL **);

//Fun in stud_save file
void exit_file(SLL *);
void save_file(SLL *);


//fun in stud_sort.c
void sort(SLL *);
void sort_roll(SLL *);
void sort_name(SLL *);
void sort_percent(SLL *);

//fun in saving file
void exit_file(SLL *);
void save_file(SLL *);






