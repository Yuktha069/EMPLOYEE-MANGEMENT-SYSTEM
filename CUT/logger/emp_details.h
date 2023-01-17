#ifndef __EMP_H__
#define __EMP_H__
#include<iostream>

#endif

using namespace std;

//base clas of heirarchy

class Employee
{
public:
Employee();
Employee(int,int,string);
void accept();
void display();


private:

int emp_id,age;

string name;

};
