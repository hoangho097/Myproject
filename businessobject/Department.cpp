#include "Department.h"

using namespace std;

// Default Contructor
Department::Department(){}
// Contructor with paramaters
Department::Department(int id, string dName, long mgrSSN, string mgrStartDate,int dNumber){
    Id = id;
    DName = dName;
    MgrSSN = mgrSSN;
    MgrStartDate = mgrStartDate;
    Dnumber = dNumber;
}

string Department::ToString(){
    string s;
    s += "{";
    s += to_string(Id) + " ";
    s += DName + " ";
    s += to_string(MgrSSN) + " ";
    s += MgrStartDate + " ";
    s += to_string(Dnumber) + " ";
    s += "}";
    return s;
}

json Department::ToJson(){
    json j;
    j["Id"] = Id;
    j["DName"] = DName;
    j["MgrSSN"] = MgrSSN;
    j["MgrStartDate"] = MgrStartDate;
    j["Dnumber"] = Dnumber;
    return j;
}

long Department :: GetMgrSSN()
{
    return MgrSSN;
}

string Department::GetDName()
{
    return DName;
}
int Department::GetDnumber()
{
    return Dnumber;
}

