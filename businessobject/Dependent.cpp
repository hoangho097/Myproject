
#include "Dependent.h"

Dependent::Dependent(){}
Dependent::Dependent(int id ,long eSSN,std::string dependentName,char sex,std::string bDate,std::string relationship){
    Id = id ;
    ESSN = eSSN;
    DependentName = dependentName;
    Sex = sex;
    BDate = bDate;
    Relationship = relationship;
}

int Dependent::GetId(){
    return Id;
}

/** brief funtion converts this project 
**
*funtion converts this object 
*/
string Dependent::ToString ()
{
    string s;
    s += "{";
    s += to_string(Id) + ", ";
    s += to_string(ESSN) + ", ";
    s += DependentName + ", ";
    string str = string(1,Sex);
    s+= str + ",";
    s += BDate + ", ";
    s += Relationship + ", ";
    s += "}";
    return s;
}

json Dependent :: ToJson()
{
    json j;
    j["Id"] = Id;
    j["ESSN"] = ESSN;
    j["DependentName"] = DependentName;
    j["Sex"] = Sex;
    j["BDate"] = BDate;
    j["Relationship"] = Relationship;
    return j;
}

string Dependent :: GetRelationship()
{
    return Relationship;
}

long Dependent :: GetESSN()
{
    return ESSN ;
}