#include<iostream>
#include<fstream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include "classes.h"
#include "room.h"
#include "LAB.h"
#include "LECTURE.h"

using namespace std;

main()
{
  string name1;
  float area1;
  int doors1;
  int x1;
  int y1;
  int Status1;
  int chairs1;
  int computers1;
  int n;
  float min1,sum;
  int i=0,j,x,b=0,c=0;
  int person=0;
vector<room*> A;
vector<Lab*> B;
vector<Lecture*> C;
room *P;
Lab *Q;
Lecture *R;

ofstream fout;
ifstream fin;

fin.open("ROOM.txt");
if(!fin)
{
    cout<<"Cannot open file\n"<<endl;
        exit(1);
}

else{

while(1)

{
 
     fin>>name1>>area1>>doors1>>x1>>y1;
       room* P1=new room;
       if(fin.eof())
	 break;
  A.push_back(P1);
  A[i]->add(name1,area1,doors1,x1,y1);
  //A[i]->setStatus(0);
i++;
}
fin.close();
}

for(j=0;j<i;j++)
    A[j]->show();

 
fin.open("LAB.txt");
if(!fin)
{
    cout<<"Cannot open file\n"<<endl;
        exit(1);
}

else{
  while(1)

{
  
  fin>>name1>>area1>>doors1>>x1>>y1>>computers1;
  Lab* Q1=new Lab;
      if(fin.eof())
	break;
  B.push_back(Q1);
  B[b]->addLab(name1,area1,doors1,x1,y1,computers1);
b++;

}
fin.close();
}

for(j=0;j<b;j++)
    B[j]->showLab();

fin;
fin.open("LEC.txt");
if(!fin)
{
    cout<<"Cannot open file\n"<<endl;
        exit(1);
}

else{

while(1)

  {
    fin>>name1>>area1>>doors1>>x1>>y1>>chairs1;
    Lecture* R1=new Lecture;
    if(fin.eof())
    break;
    C.push_back(R1);

    C[c]->addLecture(name1,area1,doors1,x1,y1,chairs1);
    c++;


}
fin.close();
}

for(j=0;j<c;j++)
C[j]->showLecture();

char ch;
int p,q;
do{

cout<<"Enter your choice:\n";
cout<<"1.ROOM\n";
cout<<"2.LAB\n";
cout<<"3.LECTURE HALL\n";
cin>>p;

switch(p)
{

case 1: cout<<"Enter any option:\n";
        cout<<"1.ADD ROOM\n";
        cout<<"2.REMOVE ROOM\n";
        cout<<"3.BOOK ROOM\n";
        cout<<"4.MINIMUM ROOMS TO ACCOMODATE THE GIVEN NUMBER OF STUDENTS\n";
        cout<<"5.NEAREST ROOM TO A GIVEN LOCATION\n";
        cout<<"6.BOOK OR UN-BOOK ROOM\n";
        cout<<"7.PRINT THE DETAILS OF ROOM\n";
        cout<<"8.EXIT\n";
        cout<<"9.PRINT DETAILS OF ALL ROOMS\n";
        cin>>q;


switch(q)
{
 case 1:cout<<"Enter room details:\n";
       cout<<"Enter name:\n";
       cin>>name1;
       cout<<"Enter area:\n";
       cin>>area1;
       cout<<"Enter number of doors\n";
       cin>>doors1;
       cout<<"Enter x coordinate\n";
       cin>>x1;
       cout<<"Enter y coordinate\n";
       cin>>y1;


	 P=new room;
       A.push_back(P);
       A[i]->add(name1,area1,doors1,x1,y1);
       A[i]->setStatus(0);
       i++;

       break;

case 2:cout<<"Enter the room name you want to delete\n";
       cin>>name1;
       for(j=0;j<i;j++)
       {
           if(name1.compare(A[j]->getName())==0)
            break;
       }
       if(j>=i){
        cout<<"Room not found\n";
       }
       else{
       n=j;
       for(j=n;j<i-1;j++)
	   A[j]=A[j+1];
       A.erase(A.begin()+i-1);
       i--;
       }

	 for(j=0;j<i;j++){
	     A[j]->show();
	   }
       break;

case 3:cout<<"Enter the room name you want to book\n";
       cin>>name1;
       for(j=0;j<i;j++)
       {
        if(name1.compare(A[j]->getName())==0)
            break;
       }
       if(j>=i){
        cout<<"Room not found\n";
       }
else{
       n=j;
       if(A[n]->getStatus()==1)
                cout<<"SORRY! The room is already booked\n";
       else

        A[n]->setStatus(1);
}

       break;

case 4:cout<<"Enter the number of persons\n";
       cin>>n;
       sum=0;
       for(j=0;j<i;j++)
       for(x=0;x<i;x++){
            if((A[x]->getArea())>(A[j]->getArea()))
           {
            room* temp=A[j];
            A[j]=A[x];
            A[x]=temp;
           }
           }
           for(j=0;j<i;j++)
            A[j]->show();
           j=i-1,person=0;
	   while(j>=0&&person<n)
	     {
               person=person+(A[j]->getArea()/30);
	       j--;
	     }
	 
           cout<<"The minimum number of rooms required is:"<<i-j-1<<endl;
           break;

case 5:cout<<"Enter the location of the room(x and y)\n";
       cin>>x1>>y1;
       min1=A[0]->getDistance(x1,y1);
       for(j=1;j<i;j++)
       {
           if((A[j]->getDistance(x1,y1))<min1)
           {
           min1=A[j]->getDistance(x1,y1);
           name1=A[j]->getName();
           }
       }
       cout<<"The room nearest to the given location is:\n";
       cout<<name1;
       break;

case 6:cout<<"Enter your choice:(book-1 & un-book-0)\n";
       cin>>Status1;
       cout<<"Enter the room name\n";
       cin>>name1;
       for(j=0;j<i;j++)
       {
           if(name1.compare(A[j]->getName())==0)
            break;
       }
       if(j>=i){
        cout<<"Room not found\n";
       }
       else{
       n=j;
       if(Status1==1)
	 {
	   if(A[n]->getStatus()==1)

	     {
	       cout<<"The room is already booked\n";
	     }
	   else
                  A[n]->setStatus(Status1);
	 }
       else if(Status1==0)
	 {
             if(A[n]->getStatus()==0)
	     {
	       cout<<"The room is already un-booked\n";
	     }
	   else
                  A[n]->setStatus(Status1);
	 }
       }
         break;

case 7:cout<<"Enter the room name\n";
       cin>>name1;
       for(j=0;j<i;j++)
       {
           if(name1.compare(A[j]->getName())==0)
            break;
       }
       if(j>=i){
        cout<<"Room not found\n";
       }
       else{
       n=j;
       cout<<"The details of the room are:\n";
       A[n]->show();
       }
       break;

case 8: fout.open("ROOM.txt");
         for(j=0;j<i;j++)
         fout<<A[j]->getName()<<" "<<A[j]->getArea()<<" "<<A[j]->getDoors()<<" "<<A[j]->getX()<<" "<<A[j]->getY()<<" "<<A[j]->getStatus()<<endl;
         fout.close();
         break;

case 9: cout<<"The details of all the rooms are:\n";
         for(j=0;j<i;j++)
         A[j]->show();
         break;

default:cout<<"Wrong Option!!\n";
}
  break;


case 2:cout<<"Enter any option:\n";
cout<<"1.ADD LAB\n";
cout<<"2.REMOVE LAB\n";
cout<<"3.BOOK LAB\n";
cout<<"4.LAB WITH LEAST EQUIPMENT DENSITY\n";
cout<<"5.BOOK OR UN-BOOK LAB\n";
cout<<"6.PRINT THE DETAILS OF LAB\n";
cout<<"7.EXIT\n";
cout<<"8.PRINT DETAILS OF ALL LABS\n";
 cin>>q;

switch(q)
{
 case 1:cout<<"Enter lab details:\n";
       cout<<"Enter name:\n";
       cin>>name1;
       cout<<"Enter area:\n";
       cin>>area1;
       cout<<"Enter number of doors\n";
       cin>>doors1;
       cout<<"Enter x coordinate\n";
       cin>>x1;
       cout<<"Enter y coordinate\n";
       cin>>y1;
       cout<<"Enter number of computers\n";
       cin>>computers1;

	 Q=new Lab;
       B.push_back(Q);
       B[b]->addLab(name1,area1,doors1,x1,y1,computers1);
       B[b]->setStatus(0);
       b++;

       break;

case 2:cout<<"Enter the lab name you want to delete\n";
       cin>>name1;

       for(j=0;j<b;j++)
       {
           if(name1.compare(B[j]->getName())==0)
            break;
       }
       if(j>=b){
        cout<<"Lab not found\n";
       }
       else{

       n=j;
       for(j=n;j<b-1;j++)
	   B[j]=B[j+1];
              B.erase(B.begin()+b-1);
       b--;
       }
       for(j=0;j<b;j++)
	 {
	
        B[j]->showLab();
	 }
       break;


case 3:cout<<"Enter the Lab name you want to book\n";
       cin>>name1;
       for(j=0;j<b;j++)
       {
        if(name1.compare(B[j]->getName())==0)
            break;
       }
       if(j>=b){
        cout<<"Lab not found\n";
       }
else{
       n=j;
       if(B[n]->getStatus()==1)
                cout<<"SORRY! The room is already booked\n";
       else

        B[n]->setStatus(1);
}

       break;


case 4:min1=B[0]->getComputers()/B[0]->getArea();
cout<<min1<<endl;
       for(j=1;j<b;j++)
{
    cout<<B[j]->getName()<<" "<<B[j]->getComputers()/B[j]->getArea()<<endl;

    if((B[j]->getComputers()/B[j]->getArea())<min1)
       {
           min1=B[j]->getComputers()/B[j]->getArea();
           name1=B[j]->getName();
       }
}
	 cout<<"The Lab with least equipment density is  "<<name1<<endl;
cout<<"Enter the lab name to increase  the number of equipments\n";
    cin>>name1;
    for(j=0;j<b;j++)
    if(name1.compare(B[j]->getName())==0)
        break;

        if(j<b)
     ++(*B[j]);
	else
	  cout<<"Lab not found\n";
	//B[j]->setComputers(n);

           break;


case 5:cout<<"Enter your choice:(book-1 & un-book-0)\n";
       cin>>Status1;
       cout<<"Enter the Lab name\n";
       cin>>name1;
       for(j=0;j<b;j++)
       {
           if(name1.compare(B[j]->getName())==0)
            break;
       }
       if(j>=b){
        cout<<"Room not found\n";
       }
       else{
       n=j;
       if(Status1==1)
	 {
	   if(B[n]->getStatus()==1)

	     {
	       cout<<"The Lab is already booked\n";
	     }
	   else
                  B[n]->setStatus(Status1);
	 }
       else if(Status1==0)
	 {
             if(B[n]->getStatus()==0)
	     {
	       cout<<"The Lab is already un-booked\n";
	     }
	   else
                  B[n]->setStatus(Status1);
	 }
       }
         break;

case 6:cout<<"Enter the Lab name\n";
       cin>>name1;
       for(j=0;j<b;j++)
       {
           if(name1.compare(B[j]->getName())==0)
            break;
       }
       if(j>=b){

        cout<<"Lab not found\n";
       }
       else{
       n=j;
       cout<<"The details of the Lab are:\n";
       P=B[n];
       P->show();
       // B[n]->showLab();
       }
       break;

case 7: fout.open("LAB.txt");
         for(j=0;j<b;j++)
         fout<<B[j]->getName()<<" "<<B[j]->getArea()<<" "<<B[j]->getDoors()<<" "<<B[j]->getX()<<" "<<B[j]->getY()<<" "<<B[j]->getStatus()<<" "<<B[j]->getComputers()<<endl;
         fout.close();
         break;


case 8: cout<<"The details of all the labs are:\n";
         for(j=0;j<b;j++)
         B[j]->showLab();
         break;

default:cout<<"Wrong Option!!\n";
}

break;

case 3:cout<<"Enter any option:\n";
cout<<"1.ADD LECTURE HALL\n";
cout<<"2.REMOVE LECTURE HALL\n";
cout<<"3.BOOK A LECTURE HALL\n";
cout<<"4.SMALLEST LECTURE HALL TO ACCOMODATE GIVEN NUMBER OF STUDENTS \n";
cout<<"5.BOOK OR UN-BOOK\n";
cout<<"6.PRINT THE DETAILS OF LECTURE HALL\n";
cout<<"7.EXIT\n";
cout<<"8.PRINT DETAILS OF ALL LECTURE HALLS\n";
 cin>>q;

switch(q)
{
 case 1:R=new Lecture;

   /* cout<<"Enter Lecture Hall details:\n";
       cout<<"Enter name:\n";
       cin>>name1;
       cout<<"Enter area:\n";
       cin>>area1;
       cout<<"Enter number of doors\n";
       cin>>doors1;
       cout<<"Enter x coordinate\n";
       cin>>x1;
       cout<<"Enter y coordinate\n";
       cin>>y1;
       cout<<"Enter number of chairs\n";
       cin>>chairs1;
       */
	        C.push_back(R);
		C[c]->addLecture(C,c);
		// C[c]->setStatus(0);
       c++;

       break;

case 2:cout<<"Enter the Lecture Hall name you want to delete\n";
       cin>>name1;

       for(j=0;j<c;j++)
       {
           if(name1.compare(C[j]->getName())==0)
            break;
       }
       if(j>=c){
        cout<<"Lecture Hall not found\n";
       }
       else{

       n=j;
       for(j=n;j<c-1;j++)
	   C[j]=C[j+1];
              C.erase(C.begin()+c-1);

       c--;
       }
       for(j=0;j<c;j++)
       C[j]->showLecture();
       break;

case 3:cout<<"Enter the Lecture Hall name you want to book\n";
       cin>>name1;

       for(j=0;j<c;j++)
       {
        if(name1.compare(C[j]->getName())==0)
            break;
       }
       if(j>=c){
        cout<<"Lecture Hall not found\n";
       }
else{
       n=j;
       if(C[n]->getStatus()==1)
                cout<<"SORRY! The Lecture Hall is already booked\n";
       else

        C[n]->setStatus(1);
}
       break;

case 4:cout<<"Enter the number of students\n";
       cin>>n;

       for(j=0;j<c;j++)
       for(x=0;x<c;x++){
            if((C[x]->getChairs())>(C[j]->getChairs()))
           {
            Lecture* temp=C[j];
            C[j]=C[x];
            C[x]=temp;
           }
           }
           for(j=0;j<c;j++)
            cout<<C[j]->getName()<<" "<<C[j]->getChairs()<<endl;
           j=0;
           while(C[j]->getChairs()<n&&j<c)
               j++;
	   if(j<c)
	   cout<<"The smallest Lecture Hall to accomodate the given number of students is:"<<C[j]->getName()<<endl;

       break;

case 5:cout<<"Enter your choice:(book-1 & un-book-0)\n";
       cin>>Status1;
       cout<<"Enter the Lecture Hall name\n";
       cin>>name1;
       for(j=0;j<c;j++)
       {
           if(name1.compare(C[j]->getName())==0)
            break;
       }
       if(j>=c){
        cout<<"Lecture Hall not found\n";
       }
       else{
       n=j;
       if(Status1==1)
	 {
	   if(C[n]->getStatus()==1)

	     {
	       cout<<"The Lecture Hall is already booked\n";
	     }
	   else
                  C[n]->setStatus(Status1);
	 }
       else if(Status1==0)
	 {
             if(C[n]->getStatus()==0)
	     {
	       cout<<"The Lecture Hall is already un-booked\n";
	     }
	   else
                  C[n]->setStatus(Status1);
	 }
       }
         break;

case 6:cout<<"Enter the Lecture Hall name\n";
       cin>>name1;
       for(j=0;j<c;j++)
       {
           if(name1.compare(C[j]->getName())==0)
            break;
       }
       if(j>=c){
        cout<<"Lecture hall not found\n";
       }
       else{
       n=j;
       cout<<"The details of the Lecture Hall are:\n";
       C[n]->showLecture();
       }
       break;

case 7: fout.open("LEC.txt");
         for(j=0;j<c;j++)
         fout<<C[j]->getName()<<" "<<C[j]->getArea()<<" "<<C[j]->getDoors()<<" "<<C[j]->getX()<<" "<<C[j]->getY()<<" "<<C[j]->getStatus()<<" "<<C[j]->getChairs()<<endl;
         fout.close();
         break;


case 8: cout<<"The details of all the Lecture Halls are:\n";
         for(j=0;j<c;j++)
         C[j]->showLecture();
         break;

default:cout<<"Wrong Option!!\n";
}
break;

default:cout<<"Wrong Option!!\n";
}
cout<<"Want to enter more?(y/n)\n";
cin>>ch;
}while(ch=='Y'||ch=='y');

 return 0;
}

