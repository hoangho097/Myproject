#ifndef _businessobject_Employee_h_
#define _businessobject_Employee_h_
#include <string>
#include<iostream>
#include "../libs/json.hpp"
#include "Company.h"
#include "../dataaccess/CompanyData.h"
using namespace std;
using nlohmann::json;

class Employee: public Company{
    int Id; //id is increasing number
    string FName, MInit, LName;
    long SSN;
    string BDate, Address;
    char Sex;
    int Salary;
    long SuperSSN;
    int DNO;

public:
    friend class EmployeeData;
    Employee();
    Employee(int id, string fName, string mInit, string lName, long ssn, string bDate, string address, char sex, int salary, long superSSN, int dno);
    int GetId();

    /** @brief Function convert all attribute like Id, FName... to 1 string
     *  @return return a string of attribute 
     */
    string ToString();

    /** @brief Function convert all attribute like Id, FName... to json with key and value
     *  @return return a string of attribute 
     */
    json ToJson();
    
    friend Employee EnterEmployeeInfor(Employee &employee);
    char GetSex();
    int GetSalary();
    string GetLName();

    string GetName();
    long GetSSN();
    
    
};
#endif