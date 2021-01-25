#include "Work_on.h"

// Default Contructor
Work_on::Work_on(){}
// Contructor with paramaters
Work_on:: Work_on(int id, long eSSN,int pno,float hours)
{
  Id = id;
  ESSN = eSSN;
  PNO = pno;
  Hours = hours;
}

int Work_on::GetId(){
    return Id;
}

/** brief funtion converts this project 
**
*funtion converts this object 
*/
string Work_on::ToString ()
{
    string s;
    s += "{";
    s += to_string(Id) + ", ";
     s += to_string(ESSN) + ", ";
    s += to_string(PNO) + ", ";
    s += to_string(Hours) + ", ";
    s += "}";
    return s;
}

json Work_on :: ToJson()
{
    json j;
    j["Id"] = Id;
    j["ESSN"] = ESSN;
    j["PNO"] = PNO;
    j["Hours"] = Hours;
    return j;
}

long Work_on :: GetESSN()
{
    return ESSN;
}

float Work_on::GetHours()
{
    return Hours;
}