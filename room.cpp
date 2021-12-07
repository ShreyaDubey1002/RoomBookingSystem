#include<iostream>
#include<string.h>
#include<math.h>
#include "classes.h"
#include "room.h"

using namespace std;

room::room()
{
  Status=0;
}/*
room::room(string name1,float area1,int doors1,int x1,int y1,int Status1)
  {
    this->name=name1;
    this->area=area1;
    this->doors=doors1;
    this->x=x1;
    this->y=y1;
    this->Status=Status1;

  }
 */

string room::getName()
{
    return name;
}

void room::setName(string name1)
{
    name=name1;
}

float room::getArea()
{
    return area;
}

void room::setArea(float area1)
{
   area=area1;
}

int room::getDoors()
{
    return doors;
}

void room::setDoors(int doors1)
{
    doors=doors1;
}


void room::setX(int x1)
{
   x=x1;
}

int room::getX()
{
    return x;
}

int room::getY()
{
    return y;
}

void room::setY(int y1)
{
    y=y1;
}

int room::getStatus()
{
    return Status;
}
void room::setStatus(int k)
{
    Status=k;
}

float room::getDistance(int x2,int y2)
{
    float distance=sqrt(((x2-x)*(x2-x))+((y2-y)*(y2-y)));
    return distance;
}

  void room::add(string name1,float area1,int doors1,int x1,int y1)
   {
    name=name1;
    area=area1;
    doors=doors1;
    x=x1;
    y=y1;
  }

void room::show()
{
  cout<<name<<" ";
  cout<<area<<" ";
  cout<<doors<<" ";
  cout<<x<<" ";
  cout<<y<<" ";
  cout<<Status<<" ";
  cout<<endl;
  }


