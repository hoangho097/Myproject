#ifndef _WORK_ON_H_
#define _WORK_ON_H_
#include <string>
#include<iostream>
#include "../libs/json.hpp"
#include "Company.h"
#include "../dataaccess/CompanyData.h"
using namespace std;
using nlohmann::json;

class Work_on : public Company{
    int Id;
    long ESSN;
    int PNO;
    float Hours;
public:
    friend class Work_onData;
    // Default Contructor
    Work_on();
    // Contructor with paramaters
    Work_on(int Id,long eSSN,int pno,float hours);
    int GetId();
    /** @brief Function convert all attribute like Id, ESSN... to 1 string
     *  @return return a string of attribute 
     */
    string ToString();
    /** @brief Function convert all attribute like Id, ESSN... to json with key and value
     *  @return return a string of attribute 
     */
    json ToJson();
    friend Work_on EnterWork_onInfor(Work_on &Work_on);
    long GetESSN();
    float GetHours();
};
#endif