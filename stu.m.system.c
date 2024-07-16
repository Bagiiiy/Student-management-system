#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct studentcourse{
	char cname[30];
	char grade[5];
	char cid[10];
    }studentcourse;
    
typedef struct student{
   	char name[20];
   	char indexno[25];
   	char department[50];
   	char courses[100];
    int count;
    struct studentcourse sc[10];}student;

typedef struct course{
   	char cid[20];
   	char cname[30];
   	float cvalue;
   } course;
    char grade[5];

   

void Sadd(){
	system("cls");
	printf("\n                      ------------Add student details-----------\n\n\n");
	student *s;
	FILE*studentfile;
	struct student stu;
	char cname[30];
	char command;
	int j,c;
	studentfile=fopen("student.txt","a");
   	fflush(stdin);
	printf("Enter student name = \n");
	scanf("%[^\n]s",&stu.name);
	fflush(stdin);
   	printf("Indexno =\n");
   	scanf("%[^\n]s",&stu.indexno);
   	fflush(stdin);
   	printf("Department =\n");
   	scanf("%[^\n]s",&stu.department);
   	printf("\nHow Many courses are following by this student :- ");
    scanf("%d",&c);

    s= (student*)calloc(c,sizeof(student));

    int number_of_courses=c;
    for (j=0;j<c;j++){
    	printf("\nEnter course name =",j+1);
    	scanf(" %[^\n]s",cname);
        printf("\n    Enter The grade ('A', 'B', 'C', 'D', 'E' Or if absent 'AB'):- ");
        scanf("%s",stu.sc[c].grade);
	}
	fwrite(&stu,sizeof(struct student),1,studentfile);
	fclose(studentfile);
    printf("\nData enter is successful!\n");
	printf("\n\nDo you want to enter a new student(y/n) : ");
    scanf(" %s",&command);
    if(command=='y'||command=='Y')
        Sadd();
    else
        main();
}

void Sdisplay(){
system ("cls");
	printf("\n                      ------------View student details-----------\n\n\n");
	int x;
	int f=1;
	char index[20];
	char command;
	FILE*studentfile, *coursefile;
	struct student stu;
	struct course cd;
	float gpa;
	studentfile=fopen("student.txt","r");

 printf("\n\tEnter Student Index No : ");
 scanf("%s",index);
 while(fread(&stu,sizeof(struct student),1,studentfile)) {
  if(strcmp(index,stu.indexno)==0) {
   int totalcredit=0;
   float creditGrade=0.0,totalGPA=0.0;
   printf("\n Name      : %s\n",stu.name);
   printf("\n Index No   : %s\n",stu.indexno);
   printf("\n Department : %s\n",stu.department);
   printf("\nCourses & Grades : \n");
   for(int c=0; c<stu.count; c++) {
     while(fread(&cd,sizeof(struct course),1,coursefile)) {
      if(strcmp(stu.sc[c].cname,cd.cname)==0) {
      totalcredit+=cd.cvalue;
      if(strcmp("A",stu.sc[c].grade)==0)
       creditGrade+=cd.cvalue*4.0;
      else if(strcmp("B",stu.sc[c].grade)==0)
       creditGrade+=cd.cvalue*3.0;
      else if(strcmp("C",stu.sc[c].grade)==0)
       creditGrade+=cd.cvalue*2.5;
      else if(strcmp("D",stu.sc[c].grade)==0)
       creditGrade+=cd.cvalue*1.5;
      else if(strcmp("E",stu.sc[c].grade)==0)
       creditGrade+=cd.cvalue*0.0;
      else if(strcmp("AB",stu.sc[c].grade)==0)
       creditGrade+=cd.cvalue*0.0;

       break;
     }

    }
    printf("\n   %s %s:  ",stu.sc[c].cname,stu.sc[c].cid);
    printf("%s\n",stu.sc[c].grade);
   }
   totalGPA=creditGrade/totalcredit;
   printf("  Current GPA : %.2f\n",totalGPA);
  }
 }
 if(f==0){
    printf("\n    Index Number not found!!!\n\n");}
fclose(studentfile);
    printf("View another student detail press(y/n) :");
    scanf(" %c",&command);
    if(command=='y'||command=='Y')
        Sdisplay();
    else
        main();
}


void Supdate(){
	system ("cls");
	printf("\n                      ------------Update student details-----------\n\n\n");
	struct student s1,s2;
	struct course c1;
	student stu;
	int f=0;
	int c,j,x;
	char index[20];
	char command;
	FILE*studentfile;
	FILE *studentfile1;
	studentfile=fopen("student.txt","r+");
	studentfile1=fopen("student1.txt","a+");
	printf("\nEnter Index NO to update:- ");
    scanf("%s",index);
    
  	while (fread(&s1,sizeof(student),1,studentfile))
	{
	    
		if(strcmp(s1.indexno,index)==0){
		f++;
        fflush(stdin);
	    printf("\nEnter student name = \n");
       	scanf("%[^\n]s",s2.name);
	    fflush(stdin);
   	    printf("Indexno =\n");
   	    scanf("%[^\n]s",s2.indexno);
   	    fflush(stdin);
       	printf("Department =\n");
        scanf("%[^\n]s",s2.department);
   	    printf("\nHow Many courses are following by this student :- ");
        scanf("%d",&c);
        int number_of_courses=c;
        for (j=0;j<c;j++){
            printf("\nEnter course name =",j+1);
    	    scanf(" %[^\n]s",c1.cname);
            printf("\n    Enter The grade ('A', 'B', 'C', 'D', 'E' Or if absent 'AB'):- ");
            scanf("%s",s2.sc[c].grade);}

        fwrite(&s2,sizeof(struct student),1,studentfile1);
        }else{

        fwrite(&s1,sizeof(struct student),1,studentfile1);

        }
    }
    if(f==0){

        printf("\n\n                -Index Number not found!!!-\n\n");
    }else{
        printf("\n                  *student update is successfully!*\n");
    }

	fclose(studentfile);
	fclose(studentfile1);
	remove("student.txt");
	rename("student1.txt","student.txt");

    printf("\nUpdate another course detail press(y/n) :");
    scanf(" %c",&command);
    if(command=='y'||command=='Y')
        Cupdate();
    else
        main();
}
	

void Cadd(){
	system("cls");
	printf("\n                            ------------Add course details-----------\n\n\n");
	FILE*coursefile;
	struct course cd;
	char command;
	coursefile=fopen("course.txt","a");
   	fflush(stdin);
	printf("Enter course name = \n");
	scanf("%[^\n]s",&cd.cname);
	fflush(stdin);
   	printf("Enter course id =\n");
   	scanf("%[^\n]s",&cd.cid);
   	fflush(stdin);
   	printf("Enter credit value =\n");
   	scanf("%f",&cd.cvalue);
    
    fwrite(&cd,sizeof(struct course),1,coursefile);
    fclose(coursefile);
printf("\nData enter is successful!\n");   
printf("Do you Want to enter a new course press(y/n) : ");
scanf(" %s",&command);
if(command=='y'||command=='Y')
    Cadd();
else
    main();

}
void Cupdate(){
    system ("cls");
	printf("\n                      ------------Update course details-----------\n\n\n");
	course c1,c2;
	char command;
	char cid[10];
	int f=0;
	FILE *coursefile, *coursefile1;
	coursefile=fopen("course.txt","r+");
	coursefile1=fopen("course1.txt","a+");
	printf("\n        Enter course id to update:- ");
    scanf("%s",cid);
	while (fread(&c1,sizeof(course),1,coursefile))
	{
	    
		if(strcmp(c1.cid,cid)==0){
		f++;
        fflush(stdin);
	    printf("Enter course name = ");
        scanf("%[^\n]s",c2.cname);
	    fflush(stdin);
   	    printf("\n\nEnter course id = ");
   	    scanf("%[^\n]s", c2.cid);
   	    fflush(stdin);
        printf("\n\nEnter credit value = ");
        scanf("%f",&c2.cvalue);

        fwrite(&c2,sizeof(struct course),1,coursefile1);
        }else{

        fwrite(&c1,sizeof(struct course),1,coursefile1);

        }
    }
    if(f==0){

        printf("\n\ncourse Id not found!!!\n\n");
    }else{
        printf("\nCourse update is successfully!\n");
    }

	fclose(coursefile);
	fclose(coursefile1);
	remove("course.txt");
	rename("course1.txt","course.txt");

    printf("\n*Update another course detail press(y/n) :*");
    scanf(" %c",&command);
    if(command=='y'||command=='Y')
        Cupdate();
    else
        main();
}

int main(){
	printf("\n\n                                   ***************** STUDENT MANAGMENT SYSTEM *****************\n\n");
	int ch;
	do{
		printf("\n\n\n                                                1). Add student details");
        printf("\n                                                2). view student details");
        printf("\n                                                3). Update student details");
        printf("\n                                                4). Add course details");
        printf("\n                                                5). Update course details");
        printf("\n                                                0). EXIT");

        printf("\n\n\n Select your choice 1,2,3,4,5 or 0 :");
        scanf("%d",&ch);

        switch(ch){
        	case 1:
        		Sadd();
        	break;
        	case 2:
        		Sdisplay();
        	break;
			case 3:
				Supdate();
			break;
			case 4:
				Cadd();
			break;
			case 5:
			    Cupdate();
			break;
			}
	}while(ch!=0);

	return 0;
}




