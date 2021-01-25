#ifndef _ui_ui_H
#define _ui_ui_H
#include<iostream>
#include <algorithm>
#include <string>
#include <direct.h>
#include <ctime>
#include"../businessobject/Employee.h"
#include "../businessobject/Dependent.h"
#include "../businessobject/Work_on.h"
#include "../businessobject/Company.h"

#include "../businessobject/Project.h"
#include "../businessobject/Department.h"
#include "../businessobject/DeptLocations.h"
#include "../dataaccess/EmployeeData.h"
#include "../dataaccess/DependentData.h"
#include "../dataaccess/Work_onData.h"
#include "../dataaccess/ProjectData.h"
#include "../dataaccess/DepartmentData.h"
#include "../dataaccess/DeptLocationsData.h"

using namespace std;

class Ui 
 {   
    public:
        
        void MainInterface();
        void ChooseFuntion(int a);
        void ChooseTable();
        void ChooseOption();
        int ChooseToEdit();

        /** @brief Function display a Employee object from of the list inside EmployeeData.
         *  
         *  Function display a Employee object from of the list inside EmployeeData
         */
        void DisplayEmployee();

        /** @brief Function display a Dependent object from of the list inside DependentData.
         *  
         *  Function display a Dependent object from of the list inside DependentData.
         */
        void DisplayDependent();

        /** @brief Function display a Work_on object from of the list inside Work_onData.
         *  
         *  Function display a Work_on object from of the list inside Work_onData.
         */
        void DisplayWork_on();

        /** @brief Function display a Project object from of the list inside ProjectData.
         *  
         *  Function display a Project object from of the list inside ProjectData.
         */
        void DisplayProject();

        /** @brief Function display a Department object from of the list inside DepartmentData.
         *  
         *  Function display a Department object from of the list inside DepartmentData.
         */
        void DisplayDepartment();

        /** @brief Function display a DeptLocations object from of the list inside DeptLocationsData.
         *  
         *  Function display a DeptLocations object from of the list inside DeptLocationsData.
         */
        void DisplayDeptLocations();

        void CreateEmployee();
        void CreateDepartment();
        void CreateProject();
        void CreateWork_on();
        void CreateDependent();
        void CreateDeptLocations();

        void DeleteEmployee();
        void DeleteProject();
        void DeleteDepartment();
        void DeleteWork_on();
        void DeleteDependent();
        void DeleteDeptLocations();

        /** @brief Function to do question 2, listing a list employees after insert the name of supervisor
         *  
         *  Function listing a list employee 
         *  @return return employees 
         */
        void RestructureCompany(); //cau2

        /** @brief Function to do question 3, listing a list employees have child
         *  
         *  Function listing a list employee 
         */
        void EmployeeHaveChild();// cau3

        /** @brief Function to do question 4, insert the project number from keyboard
         *  and show the total hours of a employee
         *  @return return The total number of hours that all employees have to work on that project. 
         */
        void GetNameProjectHours(); // cau4

        /** @brief Function to do question 5, Display Employee don't have any Project.
         */
        void EmployeeDontHaveProject();//cau 5

        /** @brief Function to do question 6, insert department name and show on the department name(i think a number of department) 
         * and average salary
         *  @return return the department name and average salary. 
         */
        void AverageSalaryOfDeparment(); // cau 6

        /** @brief Function to do question 7, Display Average salaries of all employees by gender
         */
        void AverageSalaryByGender();// cau7

        /** @brief Function to do question 8, Display The Last Name of the department manager is single
         */
        void LastNameOfManager();//cau 8

        /** @brief Function to do question 9, insert department number and project number 
         * and a list of employee in department and minimum in project
         *  @return A list of employee in department and minimum in project. 
         */  
        void GetHoursProjectEmployeeName(); // cau 9

        void DataBackUp();// cau10

        /** @brief Function to converts all the characters in a string to uppercase 
         * 
         *  @return string that uppered. 
         */  
        string UpperString(string s);

};

//enter information for the Employee object
Employee EnterEmployeeInfor(Employee &employee);
//enter information for the Dependent object
Dependent EnterDependentInfor(Dependent &dependent);
//enter information for the Work_on object
Work_on EnterWork_onInfor(Work_on &Work_on);
//enter information for the Project object
Project EnterProjectInfor(Project &project);
//enter information for the Department object
Department EnterDepartmentInfor(Department &department);
//enter information for the DeptLocations object
DeptLocations EnterDeptLocationInfor(DeptLocations &deptLocations);

#endif