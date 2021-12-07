#include<string.h>
#include "classes.h"
#include "room.h"
#include<vector>


class Lab:public room{
    int computers;

    public:

int getComputers();

void operator ++();

void setComputers(int n);

void addLab(string name1,float area1,int doors1,int x1,int y1,int computers1);
void show();
void showLab();
//void show();
};
