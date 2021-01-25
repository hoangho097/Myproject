#include "EmployeeData.h"
#include <string>
#include <fstream>
using namespace std;

EmployeeData::EmployeeData(){
    _maxId = 0;
    //Resizes the vector to the specified number of elements.
    _data.resize(0); 
}

EmployeeData::EmployeeData(string filename)
{
    _maxId = 0;
    _data.resize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize]; 
    while (inFile.getline(buff,maxSize)){
        json j = json::parse(buff);
        Employee e(

            j["Id"],
            j["FName"],
            j["MInit"], 
            j["LName"],
            j["SSN"],
            j["BDate"], 
            j["Address"],
            ((string)j["Sex"])[0],
            j["Salary"], 
            j["SuperSSN"],
            j["DNO"]

        );
        _data.push_back(e);
        _maxId ++;

    }
    inFile.close();
}
int EmployeeData::GetMaxId(){
    return _maxId;
}

int EmployeeData::PushBack(Employee e){
    //Compare the Max ID with the Id of the object added to the vector
    //if the MaxID is less than the Id of the object added, then MaxId is equal to Id of object
    if (_maxId < e.GetId())
    {
        _maxId = e.GetId();
    }
    //add an employee object to list of employees
    _data.push_back(e);
    return _maxId;
}

int EmployeeData :: GetSize()
{   //returns the size of the Employee vector
    return _data.size();
}

Employee EmployeeData:: Get(int i)
{   
    //
    string s("index out of bound");
    if(i < 0) throw s;
    if(i > _data.size()) throw s;
    //
    return _data [i];
}



int EmployeeData::ExportToFile(string filename)
{
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Employee e:_data)
    {
        outFile << e.ToJson() << endl;
    }
    outFile.close();
    return 1;
}



void EmployeeData ::Edit_Table()
{
    Ui ui;
    int Id;
    Employee employee;
    EmployeeData employeeData("Employee.data");
    //Select the Employee object that wants to change the attribute value in the table
    Id = ui.ChooseToEdit();
    // Get the employee object by index Id
    employee = employeeData._data[Id];
    // Enter the property value to change, reassign the object according to Id into the vector
    employeeData._data[Id] = EnterEmployeeInfor(employee);
    // Save employee object list to file
    employeeData.ExportToFile("Employee.data");
}

Employee* EmployeeData::GetPointer(int i){
    Employee* e = nullptr;
    if (i >= 0 && i<_data.size())
        e = &_data[i];
    return e;
}

bool EmployeeData::AddMember(Company* company){
     //assume: there is 6 employees, _maxId = 6
    _maxId++; // _maxId = 7 
    //from Company pointer type casting to Department pointer type
    Employee* employee =(Employee*) company;
    employee->Id = _maxId;//assign Id of an object to _maxId
    _data.push_back(*employee);
    return true;
}

bool EmployeeData::DeleteMember(int i){
   //If out of bound of vector named _data retun false
    if(i < 0){
        return false;
    }else{//If in bound, 
        // Reposition by using after element equalling the present element  and id decreasing value by 1
        for(int index=i; index<_data.size()-1; ++index){
            _data[index].Id = _data[index+1].Id - 1;
            _data[index].FName = _data[index+1].FName;
            _data[index].MInit = _data[index+1].MInit;
            _data[index].LName = _data[index+1].LName;
            _data[index].SSN = _data[index+1].SSN;
            _data[index].BDate = _data[index+1].BDate;
            _data[index].Address = _data[index+1].Address;
            _data[index].Sex =_data[index+1].Sex;
            _data[index].Salary =_data[index+1].SuperSSN;
            _data[index].SuperSSN = _data[index+1].SuperSSN;
            _data[index].DNO = _data[index+1].DNO;  
        }
        _data.pop_back();
    return true;   
    }
}


string EmployeeData::Restructure(string supervisorName){
    long ssn = -1;
    string employeeList = " "; //begin not have employee
    for(int i = 0; i < _data.size(); ++i){
        string s = ( (_data[i].FName) + (_data[i].LName) ); // FName appending to LName
        if( s == supervisorName ){
            ssn = _data[i].SSN;
            break;
        }
    }
    // if(ssn == -1) return " ";
    for(int i = 0; i < _data.size(); ++i){
        if((_data[i].SuperSSN - ssn) == 0){// insert into employeelist 
            employeeList = employeeList + " ";
            employeeList = employeeList + _data[i].FName;
        }
    }
    return employeeList;
}

float EmployeeData::CalculateSalary(long mgrSSN){
    float averageSalary = 0;
    float countEmployee = 0;
    for(int i = 0; i < _data.size(); ++i){
        if(_data[i].SuperSSN == mgrSSN){
            averageSalary += _data[i].Salary;
            ++countEmployee;
        }
    }
    // The average salary equal an salary of employee divide number of employee in department
    averageSalary /= float(countEmployee);

    return averageSalary;
}

vector<Employee> EmployeeData::FindEmployeeDepartment(int dno){
    //Initial no employee
    vector<Employee> departmentMember;
    departmentMember.resize(0);
    for(int i = 0; i < _data.size(); ++i)
    {
        if(_data[i].DNO == dno)
        {
            departmentMember.push_back(_data[i]);
        }
    }
    
    return departmentMember;
}

void EmployeeData :: Read_From_File()
{
        EmployeeData employeeData("Employee.data");
        for(int i=0; i< employeeData.GetSize(); i++)
        {   
            Employee e = employeeData.Get(i);
            cout<< e.ToString() <<endl;
        }
}


