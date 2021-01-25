#include "Employee.h"

Employee::Employee(){}
Employee::Employee(int id, string fName, string mInit, string lName, long ssn, string bDate, string address, char sex, int salary, long superSSN, int dno){
    Id = id;
    FName = fName;
    MInit = mInit;
    LName = lName;
    SSN = ssn;
    BDate = bDate;
    Address = address;
    Sex = sex;
    Salary = salary;
    SuperSSN = superSSN;
    DNO = dno;
}

int Employee::GetId(){
    return Id;

}

/** brief funtion converts this project 
**
*funtion converts this object 
*/
string Employee::ToString ()
{
    string s;
    s += "{";
    s += to_string(Id) + ", ";
    s += FName + ", ";
    s += MInit + ", ";
    s += LName + ", ";
    s += to_string(SSN) + ", ";
    s += BDate + ", ";
    s += Address + ", ";
    string str = string(1,Sex);
    s+= str + ",";
    s += to_string(Salary) + ", ";
    s += to_string(SuperSSN) + ", ";
    s += to_string(DNO) + ", ";
    s += "}";
    return s;
}

json Employee :: ToJson()
{
    json j;
    j["Id"] = Id;
    j["FName"] = FName;
    j["MInit"] = MInit;
    j["LName"] = LName;
    j["SSN"] = SSN;
    j["BDate"] = BDate;
    j["Address"] = Address;
    j["Sex"]= string(1,Sex);
    j["Salary"] = Salary;
    j["SuperSSN"] = SuperSSN;
    j["DNO"] = DNO;
    return j;
}

long Employee :: GetSSN()
{
    return SSN;
}

char Employee :: GetSex()
{
    return Sex ;
}

int Employee :: GetSalary()
{
    return Salary;
}

string Employee :: GetLName()
{
    return LName;
}

string Employee::GetName()
{
    return (FName + LName);
}
// void Employee:: SetFname(string s)
// {
//     FName = s;
// }

// string Employee::GetFName()
// {
//     return FName;
// }

// void Employee :: SetAddress(string s)
// {
//     Address = s;
// }