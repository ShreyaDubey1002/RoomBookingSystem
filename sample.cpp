#include<iostream>
#include<fstream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>

using namespace std;

class room
{
string name;
float area;
int doors;
int x;
int y;
int Status;

public:

string getName()
{
    return name;
}

void setName(string name1)
{
    name=name1;
}

float getArea()
{
    return area;
}

void setArea(float area1)
{
   area=area1;
}

int getDoors()
{
    return doors;
}

void setDoors(int doors1)
{
    doors=doors1;
}


void setX(int x1)
{
   x=x1;
}

int getX()
{
    return x;
}

int getY()
{
    return y;
}

void setY(int y1)
{
    y=y1;
}

int getStatus()
{
    return Status;
}
void setStatus(int k)
{
    Status=k;
}


float getDistance(int x2,int y2)
{
    float distance=sqrt(((x2-x)*(x2-x))+((y2-y)*(y2-y)));
    return distance;
}

  void add(string name1,float area1,int doors1,int x1,int y1)
   {
    name=name1;
    area=area1;
    doors=doors1;
    x=x1;
    y=y1;
  }

virtual void show()
{
  cout<<name<<" ";
  cout<<area<<" ";
  cout<<doors<<" ";
  cout<<x<<" ";
  cout<<y<<" ";
  cout<<Status<<" ";
  cout<<endl;
  }
friend class Lab;
friend class Lecture;
room()
{
Status=0;

}
~room();
};

class Lab:public room{
    int computers;

    public:

int getComputers()
{
    return computers;
}



void operator ++()
{
    int n;
    cout<<"How many computers do you want to add?\n";
    cin>>n;
    computers=computers+n;
}

void setComputers(int n)
{
    computers+=n;
}
  void addLab(string name1,float area1,int doors1,int x1,int y1,int computers1)
   {
    name=name1;
    area=area1;
    doors=doors1;
    x=x1;
    y=y1;
    computers=computers1;
  }

void show()
{
 cout<<name<<" ";
  cout<<area<<" ";
  cout<<doors<<" ";
  cout<<x<<" ";
  cout<<y<<" ";
  cout<<Status<<" ";
  cout<<computers<<" ";
  cout<<endl;
}
void showLab()
{
  cout<<name<<" ";
  cout<<area<<" ";
  cout<<doors<<" ";
  cout<<x<<" ";
  cout<<y<<" ";
  cout<<Status<<" ";
  cout<<computers<<" ";
  cout<<endl;
}

};

class Lecture:public room{
int chairs;
public:

template <typename T>
void output(T s)
  {
    cout<<s<<" ";
  }


int getChairs()
{
    return chairs;
}

void setChairs(int chairs1)
{
    chairs=chairs1;
}

void addLecture(vector<Lecture*>R,int c)
   {
  string name1;
  float area1;
  int doors1;
  int x1;
  int y1;
  int chairs1;

       cout<<"Enter Lecture Hall details:\n";
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
R[c]->setName(name1);
R[c]->setArea(area1);
R[c]->setDoors(doors1);
R[c]->setX(x1);
R[c]->setY(y1);
R[c]->setChairs(chairs1);
R[c]->setStatus(0);

  }

  void addLecture(string name1,float area1,int doors1,int x1,int y1,int chairs1)
   {
    name=name1;
    area=area1;
    doors=doors1;
    x=x1;
    y=y1;
    chairs=chairs1;
  }

void showLecture()
{
  //cout<<name<<" ";
  output(name);
  //cout<<area<<" ";
output(area);
// cout<<doors<<" ";
output(doors);
//cout<<x<<" ";
output(x);
//cout<<y<<" ";
output(y);
//cout<<Status<<" ";
output(Status);
//cout<<chairs<<" ";
output(chairs);
 cout<<endl;
  }

};

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
    cout<<"Cannot open file"<<endl;
        exit(1);
}

else{

while(1)

{
 room* P1=new room;
     fin>>name1>>area1>>doors1>>x1>>y1;
       if(fin.eof())
	 break;
  A.push_back(P1);
  A[i]->add(name1,area1,doors1,x1,y1);
  A[i]->setStatus(0);
i++;
}
fin.close();
}

for(j=0;j<i;j++)
    A[j]->show();


fin.open("LAB.txt");
if(!fin)
{
    cout<<"Cannot open file"<<endl;
        exit(1);
}

else{
  while(1)

{
  Lab* Q1=new Lab;
  fin>>name1>>area1>>doors1>>x1>>y1>>computers1;
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
    cout<<"Cannot open file"<<endl;
        exit(1);
}

else{

while(1)

{
 Lecture* R1=new Lecture;
  fin>>name1>>area1>>doors1>>x1>>y1>>chairs1;
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
        cout<<"4.MINIMUM ROOMS FOR ACCOMODATION\n";
        cout<<"5.NEAREST ROOM TO A GIVEN LOCATION\n";
        cout<<"6.BOOK OR UN-BOOK ROOM\n";
        cout<<"7.PRINT THE DETAILS OF ROOM\n";
        cout<<"8.EXIT\n";
        cout<<"9.PRINT DETAILS OF ALL ROOMS\n";
        cin>>q;


switch(q)
{
 case 1:P=new room;
       cout<<"Enter room details:\n";
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

       A.push_back(P);
       A[i]->add(name1,area1,doors1,x1,y1);
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

	 for(j=0;j<i;j++)
{
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
           j=i-1;
           while(sum<(n*30))
           {
               sum+=A[j]->getArea();
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

case 8:  fout.open("ROOM.txt");
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
cout<<"4.LAB WITH LEAST EQUIPMENT DENSITY AND ADD EQUIPMENTS IN A LAB\n";
cout<<"5.BOOK OR UN-BOOK LAB\n";
cout<<"6.PRINT THE DETAILS OF LAB\n";
cout<<"7.EXIT\n";
cout<<"8.PRINT DETAILS OF ALL LABS\n";
 cin>>q;

switch(q)
{
 case 1:Q=new Lab;
       cout<<"Enter lab details:\n";
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

       B.push_back(Q);
       B[b]->addLab(name1,area1,doors1,x1,y1,computers1);
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
       B[j]->showLab();
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
cout<<"4.SMALLEST LECTURE HALL FOR ACCOMODATION\n";
cout<<"5.BOOK OR UN-BOOK\n";
cout<<"6.PRINT THE DETAILS OF LECTURE HALL\n";
cout<<"7.EXIT\n";
cout<<"8.PRINT DETAILS OF ALL LECTURE HALLS\n";
 cin>>q;

switch(q)
{
 case 1:R=new Lecture;
       /*cout<<"Enter Lecture Hall details:\n";
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
       //C[c]->addLecture(name1,area1,doors1,x1,y1,chairs1);
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
            if((C[x]->getArea())>(C[j]->getArea()))
           {
            Lecture* temp=C[j];
            C[j]=C[x];
            C[x]=temp;
           }
           }
           for(j=0;j<c;j++)
            cout<<C[j]->getName()<<" "<<C[j]->getArea()<<" "<<C[j]->getChairs()<<endl;
           j=0;
           while(C[j]->getChairs()<n)
               j++;
cout<<"The smallest Lecture Hall is:"<<C[j]->getName();

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


case 7:  fout.open("LEC.txt");
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



