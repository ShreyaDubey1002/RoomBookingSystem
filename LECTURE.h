#include<string.h>
#include "classes.h"
#include "room.h"
#include<vector>

class Lecture:public room{

int chairs;

public:


template <typename T>
void output(T s);

int getChairs();

void setChairs(int chairs1);

void addLecture(vector<Lecture*>R,int c);
   
void addLecture(string name1,float area1,int doors1,int x1,int y1,int chairs1);

void showLecture();

};
