/*****************************************************************************************
 * * FILE NAME        : main.cpp
 *
 * * DESCRIPTION      : This file consists of  main menu and displays the functions in it
 *
 * * REVISION HISTORY : 
 *
 * 	DATE		NAME 		REASON
 *
 * 	----		----		-------
 *
 ******************************************************************************************/	

#include <iostream>
#include<cstdlib>
#include<iomanip>
#include<bits/stdc++.h>
#include <thread>
#include <mutex>
#include "personnel.hpp"
using namespace std;

struct emp_details empdetail;
struct temp tmp;

list <SALARY> empsal_list;// Salary list Declaration
SALARY obj;
list <PROJECT> pr_list;
PROJECT pr_obj;

/*****************************************************************
 * * FUNCTION NAME   : main.cpp
 *
 * * DESCRIPTION     : This function consists of various sub options for main menu
 * 		       for performing various functions
 *
 * * RETURN 	     : 1. Employee Details
 * 		       2. Project Details
 * 		       3. Employee list with salary
 * 		       4. Query
 * 		       5. Pay Report
 * 		       6. Employee with 3 Projects
 * 		       7. View Employee
 ******************************************************************/
enum
{
    Max=10,
    Maximum,
};
int main()
{
	system("read");
	system("clear");
	obj.employee_file_to_list();
	pr_obj.project_file_to_list();

	string choice1="";
	int ch,i;
	int (*choice[Max])()={project,employee,emp_salary_list,query,emp_with_3_proj_report};
	while(ch!=Maximum)
	{
		cout<<endl<<endl<<"-----------------------  WELCOME TO EMPLOYEE MANAGEMENT SYSTEM  ----------------------"<<endl;
		cout<<"\n\n---------------  Main Menu  ---------------\n\n";
		cout<<"\n1.Project Details Maintenance\n2.Employee Details Maintenance\n3.Employee list with salary\n4.Query - Projects with highest no. of team members\n5.Employee with 3 projects\n6.Pay report\n7.Show employee details\n8.Exit\n"; //Main menu of Personnel Management system
		cout<<"\nEnter choice: ";
		cin>>choice1;
		try
		{
			for(i=0;i<choice1.length();i++)
			{
				if(!isdigit(choice1[i]))  // checking entered choice is digit or not
				{
					throw choice1;
				}
			}
		}
		catch(string a)
		{
			cout<<"\n\n!!!!! choice should a digit!!!!!\n \n";
			continue;
		}
		ch=stoi(choice1); // converting the entered choice into integer
		if(ch>0 && ch<Max)
		{
			choice[ch-1]();
		} 
		else if(ch==Max)
		{
			thread pay_rec(payreport); //Applying thread to avoid concurrency issues
			pay_rec.join();
		}

		else if(ch==Max)
		{
			thread emp_rec(view_emp_record);//Applying thread to avoid concurrency issues
			emp_rec.join();
		}

		else if(ch==Max)
		{
			break;
		}
		else
		{
			cout<<endl<<"\n\n*******INVALID CHOICE********\n\n"<<endl;	
		}

		// }
}
system("read");
system("clear");
obj.list_to_employee_file();
pr_obj.list_to_project_file();
}
