#include "Work_onData.h"
#include <string>
#include <fstream>
using namespace std;

Work_onData::Work_onData()
{
    _maxId = 0;
    //Resizes the vector to the specified number of elements.
    _data.resize(0);
}

Work_onData :: Work_onData(string filename)
{
    _maxId = 0;
    _data.resize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize]; 
    while (inFile.getline(buff,maxSize)){
        json j = json::parse(buff);
        Work_on w(
            j["Id"],
            j["ESSN"],
            j["PNO"], 
            j["Hours"]
        );
        _data.push_back(w);
        _maxId ++;

    }
    inFile.close();
}

int Work_onData::GetMaxId()
{
    return _maxId;
}

int Work_onData::PushBack(Work_on w)
{   
    //Compare the Max ID with the Id of the object added to the vector
    //if the MaxID is less than the Id of the object added, then MaxId is equal to Id of object
    if (_maxId < w.GetId()){
        _maxId = w.GetId();
    }
    //add an Work_on object to list of  Work_on
    _data.push_back(w);
    return _maxId;
}


Work_on* Work_onData::GetPointer(int i)
{
    Work_on* w = nullptr;
    if (i >= 0 && i<_data.size())
        w = &_data[i];
    return w;
}

int Work_onData :: GetSize()
{   
    //returns the size of the  Work_on vector
    return _data.size();
}

Work_on Work_onData :: Get(int i)
{
    string s("index out of bound");
    if(i<0) throw s;
    if(i> _data.size()) throw s;
    return _data [i];
}

int Work_onData :: ExportToFile(string filename)
{
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Work_on e:_data)
    {
        outFile << e.ToJson() << endl;
    }
    outFile.close();
    return 1;
}

bool Work_onData::AddMember(Company* company){
    //assume: there is 5 employees, _maxId =5    
    _maxId++; //_maxId = 6
    //from Company pointer type casting to Department pointer type
    Work_on* work_on = (Work_on*)company;
    work_on->Id = _maxId; //assign Id of an object to _maxId
    _data.push_back(*work_on);
    return true;
}

bool Work_onData::DeleteMember(int i){
    //If out of bound of vector named _data retun false
    if(i < 0){
        return false;
    }else{//If in bound,
        // Reposition by using after element equalling the present element  and id decreasing value by 1
        for(int index=i; index < _data.size()-1; ++index){
            _data[index].Id    = _data[index].Id-1;
            _data[index].ESSN  = _data[index+1].ESSN;
            _data[index].PNO   = _data[index+1].PNO;
            _data[index].Hours = _data[index+1].Hours ;

        }
        _data.pop_back();
        return true;
    }
}

void Work_onData ::Edit_Table()
{
    Ui ui;
    int i;
    Work_on work_on;
    Work_onData work_onData("Work_on.data");
    //Select the Work_on object that wants to change the attribute value in the table
    i = ui.ChooseToEdit();
    // Get the Work_on object by index Id
    work_on = work_onData._data[i];
    // Enter the property value to change, reassign the object according to Id into the vector
    work_onData._data[i] = EnterWork_onInfor(work_on);
    // Save  Work_on object list to file
    work_onData.ExportToFile("Work_on.data");
}

float Work_onData::GetHoursProject(int projectNumber){
    float hoursProject = 0.0;
    for(int i = 0; i < _data.size(); ++i){
        if(_data[i].PNO == projectNumber){
            hoursProject += _data[i].Hours; 
        }
    }
    return hoursProject;// Total hous to do project
}

vector<Work_on> Work_onData::GetHoursProjectMin(int pno)
{
    vector<Work_on> employeeProject;
    employeeProject.resize(0);

    for(int i = 0; i < _data.size(); ++i)
    {
        if(_data[i].PNO == pno) employeeProject.push_back(_data[i]); 
    }


    //Sort following the value of hours column
    Work_on temp;
    for(int i = employeeProject.size()-1; i > 0 ; --i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(employeeProject[j].Hours > employeeProject[j+1].Hours)
            {
                temp = employeeProject[j+1];
                employeeProject[j+1] = employeeProject[j];
                employeeProject[j] = temp;
            }
        }
    }
    return employeeProject;
}