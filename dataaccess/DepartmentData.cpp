#include "DepartmentData.h"
#include<fstream>
#include "../libs/json.hpp"

using json = nlohmann::json;

DepartmentData::DepartmentData(){
    _maxId = 0;
    //Resizes the vector to the specified number of elements.
    _data.resize(0);
}

DepartmentData::DepartmentData(string fileName){
    _maxId = 0;
    _data.resize(0);
    ifstream inFile(fileName);
    const int maxSize = 255;
    char buff[maxSize];
    while(inFile.getline(buff, maxSize)){
        json j = json::parse(buff);
        Department p(
            j["Id"],
            j["DName"],
            j["MgrSSN"],
            j["MgrStartDate"],
            j["Dnumber"]
        );
        _data.push_back(p);
        ++_maxId;
    }
    inFile.close();
}

int DepartmentData::GetMaxId()
{
    return _maxId;
}

int DepartmentData::PushBack(Department department)
{
    _maxId++;
    department.Id = _maxId;
    //add an employee object to list of employees
    _data.push_back(department);
    return _maxId;
}

Department DepartmentData::Get(int i)
{
    string s("index out bound");
    if(i < 0) throw s;
    if( i >= _data.size() ) throw s;
    return _data[i];
}


int DepartmentData::GetSize()
{   //returns the size of the Department vector
    return _data.size();
}


void DepartmentData :: Edit_Table ()
{
    Ui ui;
    int Id;
    Department department;
    DepartmentData departmentData("Department.data");
    //Select the Department object that wants to change the attribute value in the table
    Id = ui.ChooseToEdit();
    // Get the Department object by index Id
    department = departmentData._data[Id];
    // Enter the property value to change, reassign the object according to Id into the vector
    departmentData._data[Id] = EnterDepartmentInfor(department);
    // Save Department object list to file
    departmentData.ExportToFile("Department.data");
}

Department* DepartmentData::GetPointer(int i)
{
    Department* department = nullptr;
    if( i >= 0 && (_data.size()) ) department = &_data[i];
    return department;
}

int DepartmentData::ExportToFile(string fileName )
{
    ofstream outFile(fileName, ios::out);
    if(!outFile){
        return 0;
    }
    for(Department p:_data){
        outFile<<p.ToJson()<<endl;
    }
    outFile.close();
    return 1;
}


bool DepartmentData::AddMember(Company* company){
    //assume: there is 5 employees, _maxId =5
    _maxId++;//_maxId = 6
    //from Company pointer type casting to Department pointer type
    Department* department = (Department*)company;
    department->Id = _maxId; //assign Id of an object to _maxId
    _data.push_back(*department);
    return true;
}

bool DepartmentData::DeleteMember(int i){
    //If out of bound of vector named _data retun false
    if(i < 0){
        return false;
    }else{//If in bound, 
        // Reposition by using after element equalling the present element  and id decreasing value by 1
        for(int index=i; index<_data.size()-1; ++index){
            _data[index].Id = _data[index+1].Id - 1;// Id decreasing by 1
            _data[index].DName = _data[index+1].DName;
            _data[index].MgrSSN = _data[index+1].MgrSSN;
            _data[index].MgrStartDate = _data[index+1].MgrStartDate;
            _data[index].Dnumber = _data[index+1].Dnumber;
        }
        _data.pop_back();
    return true;   
    }
}
