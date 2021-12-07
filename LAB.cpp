#include<iostream>
#include "classes.h"
#include "LAB.h"

using namespace std;

int Lab::getComputers()
{
    return computers;
}

void Lab::operator ++()
{
    int n;
    cout<<"How many computers do you want to add?\n";
    cin>>n;
    computers=computers+n;
}

void Lab::setComputers(int n)
{
    computers+=n;
}
  void Lab::addLab(string name1,float area1,int doors1,int x1,int y1,int computers1)
   {
    name=name1;
    area=area1;
    doors=doors1;
    x=x1;
    y=y1;
    computers=computers1;
  }

void Lab::show()
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

void Lab::showLab()
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
/*
void Lab::show()
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
*/
