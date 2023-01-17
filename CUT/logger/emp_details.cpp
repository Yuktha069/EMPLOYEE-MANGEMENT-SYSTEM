#include"Employee.h"
  
Employee::Employee()

Employee::Employee()
{
cout<<"\nEmployee default constructor invoked";
emp_id=0;
age=0;
name=" ";
}

Employee::Employee(int eid,int age,string nm)
{
cout<<"\nEmplyee parameterized constructor";
emp_id = eid;
this->age=age;
name=nm;
}

void Employee::accept()
{
cout<<"enter emp_id, age, name of employee";
cin>>Emp_id>>age>>name;
}

void Employee::display()
{
cout<<"\n\nDetails";
cout<<"\nEmp_id:"<<emp_id;
cout<<"\nAge:"<<age;
cout<<"\nName:"<<name;
}