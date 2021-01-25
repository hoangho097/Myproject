#include "ProjectData.h"
#include <fstream>

using json = nlohmann::json;

ProjectData::ProjectData()
{
    _maxId = 0;
    //Resizes the vector to the specified number of elements.
    _data.resize(0);
}

ProjectData::ProjectData(string fileName)
{
    _maxId = 0;
    _data.resize(0);
    ifstream inFile(fileName);
    const int maxSize = 255;
    char buff[maxSize];
    while(inFile.getline(buff, maxSize)){
        json j = json::parse(buff);
        Project p(
            j["Id"],
            j["PName"],
            j["PLocation"],
            j["PNumber"],
            j["DNum"]
        );
        _data.push_back(p);
        ++_maxId;
    }
    inFile.close();
}

int ProjectData::GetMaxId()
{
    return _maxId;
}

int ProjectData::PushBack(Project project)
{
    _maxId++;
    project.Id = _maxId;
    //add an project object to list of Projects
    _data.push_back(project);
    return _maxId;
}


int ProjectData::GetSize()
{   
    //returns the size of the Project vector
    return _data.size();
}

Project ProjectData::Get(int i)
{
    string s("index out bound");
    if(i < 0) throw s;
    if( i >= _data.size() ) throw s;
    return _data[i];
}

int ProjectData::ExportToFile(string fileName)
{
    ofstream outFile(fileName, ios::out);
    if(!outFile){
        return 0;
    }
    for(Project p:_data){
        outFile<<p.ToJson()<<endl;
    }
    outFile.close();
    return 1;
}

void ProjectData::Edit_Table()
{
    Ui ui;
    int Id;
    Project project;
    ProjectData projectData("Project.data");
    //Select the project object that wants to change the attribute value in the table
    Id = ui.ChooseToEdit();
    // Get the project object by index Id
    project = projectData._data[Id];
    // Enter the property value to change, reassign the object according to Id into the vector
    projectData._data[Id] = EnterProjectInfor(project);
    // Save project object list to file
    projectData.ExportToFile("Project.data");
}

bool ProjectData::AddMember(Company* company)
{   
    //assume: there is 5 employees, _maxId =5
    _maxId++; //_maxId = 6
    //from Company pointer type casting to Department pointer type
    Project* project = (Project*)company;
    project->Id = _maxId;  //assign Id of an object to _maxId
    _data.push_back(*project);
    return true;
}
bool ProjectData::DeleteMember(int i)
{
    //If out of bound of vector named _data retun false
    if(i < 0){
        return false;
    }else{//If in bound, 
        // Reposition by using after element equalling the present element  and id decreasing value by 1
        for(int index = i; index < _data.size()-1; ++index){
            _data[index].Id = _data[index+1].Id - 1;
            _data[index].PName = _data[index+1].PName;
            _data[index].PNumber = _data[index+1].PNumber;
            _data[index].PLocation = _data[index+1].PLocation;
            _data[index].DNum = _data[index+1].DNum;
        }
        _data.pop_back();
    return true;   
    }
}

string ProjectData::GetProjectName(int projectNumber){
    for(int i = 0; i < _data.size(); ++i){
        if(_data[i].PNumber == projectNumber){
            return _data[i].PName;
        }
    }
    return " ";
}
//Return the project name if throw project number 
string ProjectData::GetProjectName(int pNumber, int dNum){
    for(int i = 0; i < _data.size(); ++i){
        if(_data[i].PNumber == pNumber && _data[i].DNum == dNum){
            return _data[i].PName;
        }
    }
    return " ";
}
//Return the project name if throw project number and department number
Project* ProjectData::GetPointer(int i)
{
    Project* project = nullptr;
    if( i >= 0 && (_data.size()) ) project = &_data[i];
    return project;
}