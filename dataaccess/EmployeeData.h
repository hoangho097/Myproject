#ifndef _dataaccess_Employee_Data_H_
#define _dataaccess_Employee_Data_H_
#include <string>
#include <vector>
#include "CompanyData.h"
#include "../businessobject/Employee.h"
#include "../businessobject/Company.h"
#include "../ui/ui.h"
using namespace std;

class EmployeeData: public CompanyData{
private:
    vector <Employee> _data;
    int _maxId;
public:
    //No parameter constructor
    EmployeeData();
    
    EmployeeData(string);

    /** @brief The function returns the MaxID of the last element of the vector
     *  
     *  The function returns the MaxID of the last element of the vector
     *  @return return employee Max Id
     *  if fail, return -1;
     */
    int GetMaxId();

    /** @brief Function add an employee object to list of employees
     *  
     *  Function add an employee object to list of employees
     *  @return return employee id
     *  if fail, return -1;
     */
    int PushBack(Employee);

    /** @brief The function returns the size of the vector
     *  
     *  The function returns the size of the vector
     *  @return return Size of vector.
     *  if fail, return -1;
     */
    int GetSize();

    /** @brief function takes object in Employee vector 
     *  
     *  function takes object in Employee vector 
     *  @return return Employee Object
     */
    Employee Get (int);

    /** @brief Function edit contents in the employee table
     ** The function allows to edit the value of attributes in the employee Object.
     */
    void Edit_Table();

    /** @brief Function add an Employee object to list of Employees
     *  
     *  Function add an Employee object to list of Employees
     *  @return return true 
     *  
     */
    bool AddMember(Company* ) override; // Q1

    /** @brief Function delete an Employee object to list of Employees
     *  
     *  Function delete an Employee object to list of Employees
     *  @return return true 
     *  if fail, return false
     */
    bool DeleteMember(int ); // Q2

    /** @brief Function to do question 2, insert the name of supervisor and you have the list of employees
     *   
     *  if not find supervisor name, return empty string
     *  @return return a string name of employees 
     */
    string Restructure(string supervisorName);

    /** @brief Function to do question 6, insert the mgrSSN than you have the list of employees
     *   
     *  if not find supervisor name, return empty string
     *  @return return a string name of employees 
     */
    float CalculateSalary(long );

    /** @brief Function to do question 9, insert the department number than you have the list of employees
     *  in department 
     *  if not find supervisor name, return empty string
     *  @return return a vector employee type of employees 
     */
    vector<Employee> FindEmployeeDepartment(int );

    Employee* GetPointer(int i);
    int ExportToFile(string filename) override;
    void Read_From_File();
};
#endif