#include<iostream>
#include "classes.h"
#include "LECTURE.h"
#include<vector>

using namespace std;


template <typename T>
void Lecture::output(T s)
  {
    cout<<s<<" ";
  }

int Lecture::getChairs()
{
    return chairs;
}

void Lecture::setChairs(int chairs1)
{
    chairs=chairs1;
}

void Lecture::addLecture(vector<Lecture*>R,int c)
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

  void Lecture::addLecture(string name1,float area1,int doors1,int x1,int y1,int chairs1)
   {
    name=name1;
    area=area1;
    doors=doors1;
    x=x1;
    y=y1;
    chairs=chairs1;
  }



  void Lecture::showLecture()
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
/*
{
  cout<<name<<" ";
  cout<<area<<" ";
  cout<<doors<<" ";
  cout<<x<<" ";
  cout<<y<<" ";
  cout<<Status<<" ";
  cout<<chairs<<" ";
  cout<<endl;
  }
			   */
