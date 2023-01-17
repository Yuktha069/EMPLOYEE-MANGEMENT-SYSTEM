/********************************************************************************************
 * * FILE NAME           : personnel.hpp
 *
 * * DESCRIPTION         : This file consists of function declarations used in various functions
 *
 *
 *******************************************************************************************/
#ifndef H_PERSONNEL
#define H_PERSONNEL
#include <iostream>
#include <vector>
#include <string>
#include <list>

#define NAME 20
#define DEPT 10
#define CONTNO 15
#define PROID 3
#define HOUR 3
#define PNAME 20
#define ID 100
#define NUM 0
#define PRO 6
#define CHOICE 1
#define MAXIMUM 8
#define FLAG1 0
#define FLAG2 1
#define PROJECTID 2000 //project id in project fucntion

//SWITCH CASES for edit function
#define EMP 1
#define DEPART 2
#define CONTACT 3
#define PROID1 4
#define PROID2 5
#define PROID3 6
#define SAL 7
#define INVALID 8

//switch cases for project function
#define N_NAME 1
#define N_MEMBER 2
#define BREAK 3

using namespace std;

   

int employee();
int project();
int emp_salary_list();
int query();
int payreport();
int emp_with_3_proj_report();
int addemp();
int editemp();
int delemp();
int viewemp();
int addproj();
int editproj();
int delproj();
int viewproj();
int view_emp_record();

struct emp_details
{
	int employee_id;
	char employee_name[NAME];
	char department[DEPT];
	double basic_salary;
	char contact_number[CONTNO];
	int project_id[PROID];
	int no_hrs[HOUR];
	int pr_count;
	double incentive;
	double epfdeduct;
	double income_deduct;
	double total_salary;
	double gross_salary;
};

/******************************************************************************************
 * CLASS NAME  : EMPLOYEE
 *
 * DESCRIPTION : This is the base class and consists of various variable
 *               initializations used in the employee function
 *
 *****************************************************************************************/               

class EMPLOYEE
{
	public:
		EMPLOYEE()
		{
			int emp_id=ID;
			double salary= NUM;
		}
		void getdata();
	protected:
		int emp_id;
		char emp_name[NAME];
		char dept[DEPT];
		double salary;
		char contact[CONTNO];
		double ctc;
};

/***********************************************************************************************************
 * CLASS NAME  : EMPLOYEE_PROJECT
 *
 * DESCRIPTION : This is the derived class and inheriting from the base class EMPLOYEE
 *               and  consists of various variable initializations used in the project function
 *
 ***********************************************************************************************************/		 

class EMPLOYEE_PROJECT:public EMPLOYEE
{
	public:
		EMPLOYEE_PROJECT()
		{
			project_counter=NUM;
		}
	protected:
		int pr_no_prid[PROID];
		int pr_no_hrs[HOUR];
		int project_counter;
};
/***********************************************************************************************************
 * CLASS NAME  : SALARY
 *
 * DESCRIPTION : This is the multi level derived class and inheriting from the  class EMPLOYEE_PROJECT 
 *               and  consists of various variable initializations used in the employee function
 * 
 **********************************************************************************************************/		 

class SALARY: public EMPLOYEE_PROJECT
{
	public:
		SALARY()
		{
			double epf=NUM;
			double income_tax=NUM;
			double fi_salary=NUM;
		}
		void calc_fi_salary();
		void add_employee();
		void view1();
		void view_employee();
		void editdata();
		void deldata();
		void salary_view();
		void view_emp_record();
		void emp_list_with_3_projects();
		void employee_file_to_list();
		void list_to_employee_file();
		void view_emp_project_detail();
	protected:
		double pr_bonus;
		double epf;
		double income_tax;
		double fi_salary;
};

/******************************************************************************************
 * CLASS NAME  : PROJECT
 *
 * DESCRIPTION : This is the base class and consists of various variable
 *                initializations used in the project function
 *
 ******************************************************************************************/

struct temp
{
	char project_name[PNAME];
	int t_members;
	int project_id;
};

class PROJECT
{
	public:
		int team_mem;
		int pr_id;
		void getdata();
		void view();
		void edit();
		void del_project();
		void project_query();
		void project_file_to_list();
		void list_to_project_file();
	protected:
		char pr_name[PNAME];
};

#endif
