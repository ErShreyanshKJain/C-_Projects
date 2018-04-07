#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reserve();

void display();

struct pass{

char name[20];

unsigned int age;

char gender;

};

struct seat{

struct pass p[5];

int pri[5];

int pnr[5];

struct seat *link[5];

}*start=NULL,*end=NULL,*temp[5],*tem,*q;

struct date{

int day;

int month;

int year;

}d;

 

int a=0,b=0,i=0,no,li,g;

static int pnr=2670,n,m,c,f,e,fare;

char prity[20];

void enquire(int no)

{

 

switch(no)

{

case 3120:

printf("\n\t\t-> No. of seats available : %d",n);

        printf("\n\t\t-> TIMINGS : 04:00 A.M. - 11:00 P.M.");

printf("\n\t\t-> FARE OF JOURNEY : Rs. 1320/-per head");

break;

case 4250:

printf("\n\t\t-> No. of seats available : %d",m);

printf("\n\t\t-> TIMINGS : 12:30 A.M. - 07:30 P.M.");

printf("\n\t\t-> FARE OF JOURNEY : Rs. 1670/-per head");

break;

case 1240:

printf("\n\t\t-> No. of seats available : %d",c);

printf("\n\t\t-> TIMINGS : 03:30 A.M. - 09:30 P.M.");

   printf("\n\t\t-> FARE OF JOURNEY : Rs. 1530/-per head");

   break;

case 6570:

   printf("\n\t\t-> No. of seats available : %d",f);

   printf("\n\t\t-> TIMINGS : 02:30 P.M. - 07:30 A.M.");

   printf("\n\t\t-> FARE OF JOURNEY : Rs. 1140/-per head");

   break;

case 1257:

   printf("\n\t\t-> No. of seats available : %d",e);

   printf("\n\t\t-> TIMINGS : 08:00 A.M. - 10:30 P.M.");

   printf("\n\t\t-> FARE OF JOURNEY : Rs. 1200/-per head");

   break;

   default :

    printf("Enter valid train no. ! ");

}

}

 

 

void reserve(int no)

{

int prit;

unsigned int age;

char nam[20],sex,se[10];

printf("Enter name of passenger : ");

scanf("%s",nam);

printf("Enter age of passenger : ");

scanf("%u",&age);

printf("Enter gender of passenger (m/f) : ");

scanf(" %c",&sex);

printf("\n1. HANDICAPPED (fare-350) \n2. SENIOR CITIZENS (fare-250) \n3. TATKAL (fare+1000)\n4. LADIES (fare-100) \n5. GENERAL\nEnter which quota do you belong : ");

scanf("%d",&prit);

pnr+=7;

/* printf("Enter date (in dd/mm/yyyy format): ");

scanf("%d",&d.day);

printf("/");

scanf("%d",&d.month);

printf("/");

scanf("%d",&d.year);*/

if(prit==5)

{

strcpy(prity,"GENERAL");

}

else if(prit==4)

{

fare=fare-100;

strcpy(prity,"LADIES");

}

else if(prit==3)

{

fare=fare+1000;

strcpy(prity,"TATKAL");

}

else if(prit==2)

{

fare=fare-250;

strcpy(prity,"SENIOR CITIZENS");

}

else if(prit==1)

{

fare=fare-350;

strcpy(prity,"HANDICAPPED");

}

else

{

printf("No such quota available!");

}

if(sex=='m')

strcpy(se,"male");

else

strcpy(se,"female");

printf("Record updated & bill successfully generated !\n\n");

printf("\n------------------------------- BILL ---------------------------------");

printf("\n                                                                               DATE : 24/11/2016");

printf("\n\n NAME    AGE  GENDER  QUOTA   PNR NO -----------------  TOTAL FARE");

printf("\n-----------------------------------------------------------------------");

printf("\n%s  %u    %s     %s    %d  --------------->  Rs. %d/-\n\n",nam,age,se,prity,pnr,fare);

switch(no)

{

case 3120 :

temp[0]=(struct seat *)malloc(sizeof(struct seat));

strcpy(temp[0]->p[0].name,nam);

temp[0]->p[0].age=age;

temp[0]->p[0].gender=sex;

temp[0]->pri[0]=prit;

temp[0]->pnr[0]=pnr;

if( start == NULL || prit < start->pri[0] )

{

temp[0]->link[0] = start;

start = temp[0];

}

else

{

q = start;

while( q->link[0] != NULL && q->link[0]->pri[0] <= prit ) q=q->link[0];

temp[0]->link[0] = q->link[0];

q->link[0] = temp[0];

}

 

 

break;

case 4250:

temp[1]=(struct seat *)malloc(sizeof(struct seat));

strcpy(temp[1]->p[1].name,nam);

temp[1]->p[1].age=age;

temp[1]->p[1].gender=sex;

temp[1]->pri[1]=prit;

temp[1]->pnr[1]=pnr;

if( start == NULL || prit < start->pri[1] )

{

temp[1]->link[1] = start;

start = temp[1];

}

else

{

q = start;

while( q->link[1] != NULL && q->link[1]->pri[1] <= prit ) q=q->link[1];

temp[1]->link[1] = q->link[1];

q->link[1] = temp[1];

}

 

 

 

break;

case 1240 :

temp[2]=(struct seat *)malloc(sizeof(struct seat));

strcpy(temp[2]->p[2].name,nam);

temp[2]->p[2].age=age;

temp[2]->p[2].gender=sex;

temp[2]->pri[2]=prit;

temp[2]->pnr[2]=pnr;

if( start == NULL || prit < start->pri[2] )

{

temp[2]->link[2] = start;

start = temp[2];

}

else

{ 

q = start;

while( q->link[2] != NULL && q->link[2]->pri[2] <= prit ) q=q->link[2];

temp[2]->link[2] = q->link[2];

q->link[2] = temp[2];

}

 

 

break;

case 6570 :

temp[3]=(struct seat *)malloc(sizeof(struct seat));

strcpy(temp[3]->p[3].name,nam);

temp[3]->p[3].age=age;

temp[3]->p[3].gender=sex;

temp[3]->pri[3]=prit;

temp[3]->pnr[3]=pnr;

if( start == NULL || prit < start->pri[3] )

{

temp[3]->link[3] = start;

start = temp[3];

}

else

{ 

q = start;

while( q->link[3] != NULL && q->link[3]->pri[3] <= prit ) q=q->link[3];

temp[3]->link[3] = q->link[3];

q->link[3] = temp[3];

}

 

break;

case 1257 :

temp[4]=(struct seat *)malloc(sizeof(struct seat));

strcpy(temp[4]->p[4].name,nam);

temp[4]->p[4].age=age;

temp[4]->p[4].gender=sex;

temp[4]->pri[4]=prit;

temp[4]->pnr[4]=pnr;

if( start == NULL || prit < start->pri[4] )

{

temp[4]->link[4] = start;

start = temp[4];

}

else

{ 

q = start;

while( q->link[4] != NULL && q->link[4]->pri[4] <= prit ) q=q->link[4];

temp[4]->link[4] = q->link[4];

q->link[4] = temp[4];

}

 

break;

default :

printf("Wrong Choice!");

}

 

 

}

 

void status(int no)

{

int p;

q=start;

printf("Enter pnr no. : ");

scanf("%d",&p);

switch(no)

{

case 3120:

if(start!=NULL)

{

while(q->link[0]!=NULL && q->pnr[0]!=p)

{

q=q->link[0];

}

if(q->pnr[0]==p)

{

printf("Your status is confirmed!");

}

else

{

printf("Your status is not confirmed! (WAITING LIST)");

}

}

break;

case 4250:

if(start!=NULL)

{

while(q->link[1]!=NULL && q->pnr[1]!=p)

{

q=q->link[1];

}

if(q->pnr[1]==p)

{

printf("Your status is confirmed!");

}

else

{

printf("Your status is not confirmed! (WAITING LIST)");

}

}

break;

case 1240:

if(start!=NULL)

{

while(q->link[2]!=NULL && q->pnr[2]!=p)

{

q=q->link[2];

}

if(q->pnr[2]==p)

{

printf("Your status is confirmed!");

}

else

{

printf("Your status is not confirmed! (WAITING LIST)");

}

}

break;

case 6570:

if(start!=NULL)

{

while(q->link[3]!=NULL && q->pnr[3]!=p)

{

q=q->link[3];

}

if(q->pnr[3]==p)

{

printf("Your status is confirmed!");

}

else

{

printf("Your status is not confirmed! (WAITING LIST)");

}

}

break;

case 1257:

if(start!=NULL)

{

while(q->link[4]!=NULL && q->pnr[4]!=p)

{

q=q->link[4];

}

if(q->pnr[4]==p)

{

printf("Your status is confirmed!");

}

else

{

printf("Your status is not confirmed! (WAITING LIST)");

}

}

break;

}

}

 

void display(int no)

{

static int i,j,k,l,m;

// q=start;

switch(no)

{

case 3120:

q=start;

if(start!=NULL)

{

i=1;

printf("LIST OF PASSENGERS ACCORDING TO PRIORITY : ");

printf("\nSEAT NO.   NAME    AGE    GENDER    PNR NO     PRIORITY NO \n");

printf("------------------------------------------------------------------------\n");

while(q!=NULL)

{

// pnr=i+2670;

printf("   %d   %s    %u      %c    %d    %d\n",i,q->p[0].name,q->p[0].age,q->p[0].gender,q->pnr[0],q->pri[0]);

q=q->link[0];

i++;

}

}

else

{

printf("LIST IS EMPTY!");

}

break;

case 4250:

 

temp[1]->pnr[1]=pnr;

q=start->link[1];

if(start!=NULL)

{

j=1;

// pnr=j+3250;

printf("LIST OF PASSENGERS ACCORDING TO PRIORITY : ");

printf("\nSEAT NO.   NAME    AGE    GENDER    PNR NO     PRIORITY NO \n");

printf("------------------------------------------------------------------------\n");

while(q!=NULL)

{

printf("   %d   %s    %u      %c      %d    %d\n",j,q->p[1].name,q->p[1].age,q->p[1].gender,q->pnr[1],q->pri[1]);

q=q->link[1];

j++;

}

}

else

{

printf("LIST IS EMPTY!");

}

break;

case 1240:

temp[2]->pnr[2]=pnr;

q=start->link[2];

if(start!=NULL)

{

k=1;

// pnr=k+4870;

printf("LIST OF PASSENGERS ACCORDING TO PRIORITY : ");

printf("\nSEAT NO.   NAME    AGE    GENDER    PNR NO     PRIORITY NO \n");

printf("------------------------------------------------------------------------\n");

while(q!=NULL)

{

printf("   %d   %s    %u      %c      %d    %d\n",k,q->p[2].name,q->p[2].age,q->p[2].gender,q->pnr[2],q->pri[2]);

q=q->link[2];

k++;

}

}

else

{

printf("LIST IS EMPTY!");

}

break;

case 6570:

 

temp[3]->pnr[3]=pnr;

q=start->link[3];

if(start!=NULL)

{

l=1;

// pnr=l+5670;

printf("LIST OF PASSENGERS ACCORDING TO PRIORITY : ");

printf("\nSEAT NO.   NAME    AGE    GENDER    PNR NO     PRIORITY NO \n");

printf("------------------------------------------------------------------------\n");

while(q!=NULL)

{

printf("   %d   %s    %u      %c      %d    %d\n",l,q->p[3].name,q->p[3].age,q->p[3].gender,q->pnr[3],q->pri[3]);

q=q->link[3];

l++;

}

}

else

{

printf("LIST IS EMPTY!");

}

break;

case 1257:

 

 

temp[4]->pnr[4]=pnr;

q=start->link[4];

if(start!=NULL)

{m=1;

// pnr=m+7600;

printf("LIST OF PASSENGERS ACCORDING TO PRIORITY : ");

printf("\nSEAT NO.   NAME    AGE    GENDER    PNR NO     PRIORITY NO \n");

printf("------------------------------------------------------------------------\n");

while(q!=NULL)

{

printf("   %d   %s    %u      %c      %d    %d\n",m,q->p[4].name,q->p[4].age,q->p[4].gender,q->pnr[4],q->pri[4]);

q=q->link[4];

m++;

}

}

else

{

printf("LIST IS EMPTY!");

}

break;

}//pnr++;

}

 

void cancel(int no)

{

int p;

q=start;

printf("Enter pnr no. : ");

scanf("%d",&p);

switch(no)

{

 

case 3120:

if(start==NULL)

{

printf("Empty List of passengers!");

}

else{

while(q!=NULL && q->pnr[0]!=p)

{

tem=q;

q=q->link[0];

}

 

tem->link[0]=q->link[0];

free(q);

/* if(start==NULL)

{

printf("LIST IS EMPTY!");

}*/

}

printf("UPDATED LIST :- \n");

display(3120);

 

break;

case 4250:

if(start==NULL)

{

printf("Empty List of passengers!");

}

else{

while(q!=NULL && q->pnr[1]!=p)

{

tem=q;

q=q->link[1];

}

 

tem->link[1]=q->link[1];

free(q);

}

printf("UPDATED LIST :- \n");

display(4250);

break;

case 1240:

if(start==NULL)

{

printf("Empty List of passengers!");

}

else{

while(q!=NULL && q->pnr[2]!=p)

{

tem=q;

q=q->link[2];

}

 

tem->link[2]=q->link[2];

free(q);

}

printf("UPDATED LIST :- \n");

display(1240);

break;

case 6570:

if(start==NULL)

{

printf("Empty List of passengers!");

}

else{

while(q!=NULL && q->pnr[3]!=p)

{

tem=q;

q=q->link[3];

}

 

tem->link[3]=q->link[3];

free(q);

}

printf("UPDATED LIST :- \n");

display(6570);

break;

case 1257:

if(start==NULL)

{

printf("Empty List of passengers!");

}

else{

while(q!=NULL && q->pnr[4]!=p)

{

tem=q;

q=q->link[4];

}

 

tem->link[4]=q->link[4];

free(q);

}

break;

printf("UPDATED LIST :- \n");

display(1257);

default  :

printf("Enter valid train no.!");

}

}

void main()

{

struct seat *q;

n=70;

m=75;

c=65;

f=70;

e=60;

int z,h=1;

 

printf("\n\t\t*** WELCOME TO RAILWAY RESERVATION SYSTEM ***");

while(h!=2)

{

printf("\n\n");

printf("TRAIN NO   |        TRAIN         |    SOURCE STATION    |      DESTINATION STATION \n"); 

printf("-----------|----------------------|----------------------|--------------------------\n");

printf("  3120     |  RAJDHANI EXPRESS    |      NEW DELHI       |       MUMBAI CENTRAL\n");

printf("  4250     |   SHATABADI EXPRESS  |      AMRITSAR        |         NEW DELHI\n");

printf("  1240     |     MAIL/EXPRESS     |      BENGALURU       |          KOLKATA\n");

printf("  6570     |    SUPERFAST/YUVA    |      LUCKNOW         |           SHIMLA\n");

printf("  1257     |      GARIBRATH       |       AGRA           |           GWALIOR\n");

 

printf("Enter train no. : ");

scanf("%d",&no);

 

switch(no)

{

case 3120 :

fare=1320;

printf("\n1. ENQUIRE \n2. RESERVE SEAT \n3. CHECK STATUS \n4. CANCEL TICKET \n5. DISPLAY \n6. EXIT");

printf("\n  ENTER YOUR CHOICE : ");

scanf("%d",&z);

switch(z)

{

case 1 : 

enquire(3120);

break;

case 2:

reserve(3120);

n--;

break;

case 3 :

status(3120);

break;

case 4 :

cancel(3120);

break;

case 5:

display(3120);

break;

case 6 :

exit(0);

default :

printf("Wrong Choice !");

return main();

}

break;

case 4250:

fare=1670; 

printf("\n1. ENQUIRE \n2. RESERVE SEAT \n3. CHECK STATUS \n4. CANCEL TICKET \n5. DISPLAY \n6. EXIT");

printf("\n   ENTER YOUR CHOICE : ");

scanf("%d",&z);

switch(z)

{

case 1 : 

enquire(4250);

break;

case 2:

reserve(4250);

m--;

break;

case 3 :

status(4250);

break;

case 4 :

cancel(4250);

break;

case 5:

display(4250);

break;

case 6 :

exit(0);

default :

printf("Wrong Choice !");

return main();

}

 

break;

case 1240 :

    fare=1530; 

  printf("\n1. ENQUIRE \n2. RESERVE SEAT \n3. CHECK STATUS \n4. CANCEL TICKET \n5. DISPLAY \n6. EXIT");

printf("\n   ENTER YOUR CHOICE : ");

scanf("%d",&z);

switch(z)

{

case 1 : 

enquire(1240);

break;

case 2:

reserve(1240);

c--;

break;

case 3 :

status(1240);

break;

case 4 :

cancel(1240);

break;

case 5:

display(1240);

break;

case 6 :

exit(0);

default :

printf("Wrong Choice !");

return main();

}

 

   break;

case 6570 :

   fare=1140;

printf("\n1. ENQUIRE \n2. RESERVE SEAT \n3. CHECK STATUS \n4. CANCEL TICKET \n5. DISPLAY \n6. EXIT");

printf("\n   ENTER YOUR CHOICE : ");

scanf("%d",&z);

switch(z)

{

case 1 : 

enquire(6570);

break;

case 2:

reserve(6570);

f--;

break;

case 3 :

status(6570);

break;

case 4 :

cancel(6570);

break;

case 5:

display(6570);

break;

case 6 :

exit(0);

default :

printf("Wrong Choice !");

return main();

}

 

   break;

case 1257 :

   fare=1200;

printf("\n1. ENQUIRE \n2. RESERVE SEAT \n3. CHECK STATUS \n4. CANCEL TICKET \n5. DISPLAY \n6. EXIT");

printf("\n   ENTER YOUR CHOICE : ");

scanf("%d",&z);

switch(z)

{

case 1 : 

enquire(1257);

break;

case 2:

reserve(1257);

e--;

break;

case 3 :

status(1257);

break;

case 4 :

cancel(1257);

break;

case 5:

display(1257);

break;

case 6 :

exit(0);

default :

printf("Wrong Choice !");

return main();

}

 

   break;

   default :

    printf("Enter valid train no. ! ");

   

}

 

printf("\n\n\tDo you wish to continue ? 1. YES 2. NO");

scanf("%d",&h);

}

}

 

 


