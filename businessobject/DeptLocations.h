#ifndef _businessobject_DeptLocations_H_
#define _businessobject_DeptLocations_H_
#include <string>
#include<iostream>
#include "../libs/json.hpp"
#include "Company.h"
#include "../dataaccess/CompanyData.h"
using json = nlohmann::json;
using namespace std;

class DeptLocations : public Company{
    int Id;
    int DNumber;
    string DLocation;

public:
    friend class DeptLocationsData;
    // Default Contructor
    DeptLocations();
    // Contructor with paramaters
    DeptLocations(int id, int dNumber, string dLocation);
    /** @brief Function convert all attribute like Id, DNumber... to 1 string
     *  @return return a string of attribute 
     */ 
    string ToString();
    /** @brief Function convert all attribute like Id, DNumber... to json with key and value
     *  @return return a string of attribute 
     */
    json ToJson();
    friend DeptLocations EnterDeptLocationInfor(DeptLocations &deptLocations);
};

#endif