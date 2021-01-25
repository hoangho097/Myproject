#ifndef _businessobject_Dependent_h_
#define _businessobject_Dependent_h_
#include <string>
#include<iostream>
#include "../libs/json.hpp"
#include "Company.h"
#include "../dataaccess/CompanyData.h"

using namespace std;
using nlohmann::json;

class Dependent : public Company{
    int Id;
    long ESSN;
    std::string DependentName;
    char Sex;
    std::string BDate;
    std::string Relationship;

public:
    friend class DependentData;
    //Default Contructor
    Dependent();
    // Contructor with paramaters
    Dependent(int Id, long eSSN,std::string dependentName,char sex,std::string bDate,std::string relationship);
    int GetId();
    /** @brief Function convert all attribute like Id, ESSN... to 1 string
     *  @return return a string of attribute 
     */
    string ToString();
    /** @brief Function convert all attribute like Id, ESSN... to json with key and value
     *  @return return a string of attribute 
     */
    json ToJson();

    // Funtion Enter Information for Dependent Object.
    friend Dependent EnterDependentInfor(Dependent &dependent);
    
    string GetRelationship();
    /** @brief Function to get value ESSN
     *  @return return ESSN 
     */
    long GetESSN();
};
#endif