#ifndef _DEPARTRMENT_H_
#define _DEPARTRMENT_H_
#include <string>
#include "../libs/json.hpp"
#include "Company.h"
#include<iostream>
#include "../dataaccess/CompanyData.h"

using json = nlohmann::json;
using namespace std;

class Department : public Company{
    int Id;
    string DName;
    long MgrSSN;
    string MgrStartDate;
    int Dnumber;

public:
    friend class DepartmentData;

    //Default Contructor
    Department();
    // Contructor with paramaters
    Department(int id, string dName, long mgrSSN, string mgrStartDate,int dNumber);
    /** @brief Function convert all attribute like id, dname... to 1 string
     *  @return return a string of attribute 
     */
    string ToString();

    /** @brief Function convert all attribute like id, dname... to json with key and value
     *  @return return a string of attribute 
     */
    json ToJson();

    /** @brief Function to get value MgrSSN
     *  @return return MgrSSN 
     */
    long GetMgrSSN();

    /** @brief Function to get value DName
     *  @return return DName 
     */
    string GetDName();

    /** @brief Function to get value Dnumber
     *  @return return Dnumber 
     */
    int GetDnumber();

    //funtion Enter Information for Department Object.
    friend Department EnterDepartmentInfor(Department &department);
    
};

#endif 