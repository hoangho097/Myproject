#include "DeptLocationsData.h"
#include <fstream>
#include "../libs/json.hpp"

using json = nlohmann::json;

DeptLocationsData::DeptLocationsData(){
    _maxId = 0;
    //Resizes the vector to the specified number of elements.
    _data.resize(0);
}

DeptLocationsData::DeptLocationsData(string fileName){
    _maxId = 0;
    _data.resize(0);
    ifstream inFile(fileName);
    const int maxSize = 255;
    char buff[maxSize];
    while(inFile.getline(buff, maxSize)){
        json j = json::parse(buff);
        DeptLocations p(
            j["Id"],
            j["DNumber"],
            j["DLocation"]
            );
        _data.push_back(p);
        ++_maxId;
    }
    inFile.close();
}

int DeptLocationsData::GetMaxId(){
    return _maxId;
}

int DeptLocationsData::PushBack(DeptLocations deptLocations){
    _maxId++;
    deptLocations.Id = _maxId;
    _data.push_back(deptLocations);
    return _maxId;
}


int DeptLocationsData::GetSize()
{   //returns the size of the Employee vector
    return _data.size();
}

DeptLocations DeptLocationsData::Get(int i){
    string s("index out bound");
    if(i < 0) throw s;
    if( i >= _data.size() ) throw s;
    return _data[i];
}

void DeptLocationsData :: Edit_Table ()
{
    Ui ui;
    int Id;
    DeptLocations deptLocations;
    DeptLocationsData deptLocationsData("DeptLocations.data");
    //Select the Employee object that wants to change the attribute value in the table
    Id = ui.ChooseToEdit();
    // Get the employee object by index Id
    deptLocations = deptLocationsData._data[Id];
    // Enter the property value to change, reassign the object according to Id into the vector
    deptLocationsData._data[Id] = EnterDeptLocationInfor(deptLocations);
    // Save employee object list to file
    deptLocationsData.ExportToFile("DeptLocations.data");
}

int DeptLocationsData::ExportToFile(string fileName ){
    ofstream outFile(fileName, ios::out);
    if(!outFile){
        return 0;
    }
    for(DeptLocations p:_data){
        outFile<<p.ToJson()<<endl;
    }
    outFile.close();
    return 1;
}

DeptLocations* DeptLocationsData::GetPointer(int i){
    DeptLocations* deptLocations = nullptr;
    if( i >= 0 && (_data.size()) ) deptLocations = &_data[i];
    return deptLocations;
}

bool DeptLocationsData::AddMember(Company* company){
    //If out of bound of vector named _data retun false
    _maxId++;
    DeptLocations* deptLocations = (DeptLocations*)company;
    deptLocations->Id = _maxId;
    _data.push_back(*deptLocations);
    return true;
}

bool DeptLocationsData::DeleteMember(int i){
    if(i < 0){//If in bound,
        return false;
    }else{// Reposition by using after element equalling the present element  and id decreasing value by 1    
        for(int index=i; index<_data.size()-1; ++index){
            _data[index].Id = _data[index+1].Id - 1;
            _data[index].DNumber = _data[index+1].DNumber;
            _data[index].DLocation = _data[index+1].DLocation;
        }
        _data.pop_back();
    return true;   
    }
}


