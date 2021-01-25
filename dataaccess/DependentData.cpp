#include "DependentData.h"
#include <string>
#include <fstream>
using namespace std;

DependentData::DependentData()
{
    _maxId = 0;
    //Resizes the vector to the specified number of elements.
    _data.resize(0);
}
DependentData::DependentData(string filename)
{
    _maxId = 0;
    _data.resize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize]; 
    while (inFile.getline(buff,maxSize)){
        json j = json::parse(buff);
        Dependent d(
            j["Id"],
            j["ESSN"],
            j["DependentName"], 
            ((string)j["Sex"])[0],
            j["BDate"], 
            j["Relationship"]
        );
        _data.push_back(d);
        _maxId ++;
    }
    inFile.close();
}

int DependentData::GetMaxId(){
    return _maxId;
}
int DependentData::PushBack(Dependent d)
{   
    //Compare the Max ID with the Id of the object added to the vector
    //if the MaxID is less than the Id of the object added, then MaxId is equal to Id of object
    if (_maxId < d.GetId())
    {
        _maxId = d.GetId();
    }
    //add an Dependent object to list of Dependents
    _data.push_back(d);
    return _maxId;
}

int DependentData :: GetSize()
{   //returns the size of the Employee vector
    return _data.size();
}

Dependent DependentData:: Get(int i)
{
    string s("index out of bound");
    if(i<0) throw s;
    if(i> _data.size()) throw s;
    return _data [i];
}


void DependentData :: Edit_Table()
{
    Ui ui;
    int Id;
    Dependent dependent;
    DependentData dependentData("Dependent.data");
    //Select the Dependent object that wants to change the attribute value in the table
    Id = ui.ChooseToEdit();
    // Get the Dependent object by index Id
    dependent = dependentData._data[Id];
    // Enter the property value to change, reassign the object according to Id into the vector
    dependentData._data[Id] = EnterDependentInfor(dependent);
      // Save Dependent object list to file
    dependentData.ExportToFile("Dependent.data");
}

int DependentData::ExportToFile(string filename){
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Dependent e:_data)
    {
        outFile << e.ToJson() << endl;
    }
    outFile.close();
    return 1;
}

 bool DependentData::AddMember(Company* company){
      //assume: there is 7 employees, _maxId = 7
    _maxId++;//_maxId = 8
    //from Company pointer type casting to Department pointer type
    Dependent* dependent = (Dependent*)company;
    dependent->Id = _maxId;//assign Id of an object to _maxId
    _data.push_back(*dependent);
    return true;
}

bool DependentData::DeleteMember(int i){
    //If out of bound of vector named _data retun false
    if(i < 0){
        return false;
    }else{//If in bound, 
        // Reposition by using after element equalling the present element  and id decreasing value by 1
        for(int index=i; index<_data.size()-1; ++index){
            _data[index].Id = _data[index+1].Id - 1;
            _data[index].ESSN = _data[index+1].ESSN;
            _data[index].DependentName = _data[index+1].DependentName;
            _data[index].Sex = _data[index+1].Sex;
            _data[index].BDate = _data[index+1].BDate;
            _data[index].Relationship = _data[index+1].Relationship;
        }
        _data.pop_back();
    return true;   
    }
}

Dependent* DependentData::GetPointer(int i){
    Dependent* e = nullptr;
    if (i >= 0 && i<_data.size())
        e = &_data[i];
    return e;
}



