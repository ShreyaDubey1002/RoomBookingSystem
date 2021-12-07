#include<string.h>
#include<iostream>
#include "classes.h"
#pragma once

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

string getName();

void setName(string name1);

float getArea();

void setArea(float area1);

int getDoors();

void setDoors(int doors1);

void setX(int x1);

int getX();

int getY();

void setY(int y1);

int getStatus();

void setStatus(int k);

float getDistance(int x2,int y2);

void add(string name1,float area1,int doors1,int x1,int y1);

virtual void show();

friend class Lab;
friend class Lecture;
room();

~room();
};
