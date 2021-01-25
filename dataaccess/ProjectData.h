#ifndef _dataaccess_Project_Data_H_
#define _dataaccess_Project_Data_H_
#include <string>
#include <vector>
#include <iostream>
#include "CompanyData.h"
#include "../businessobject/Project.h"
#include "../ui/ui.h" 

using namespace std;

class ProjectData : public CompanyData{
private:
    vector<Project> _data;
    int _maxId;
public:
    //No parameter constructor
    ProjectData();
    ProjectData(string fileName);

    /** @brief The function returns the MaxID of the last element of the vector
     *  
     *  The function returns the MaxID of the last element of the vector
     *  @return return Project Max Id
     *  if fail, return -1;
     */
    int GetMaxId();

    /** @brief Function add an Project object to list of Projects
     *  
     *  Function add an Project object to list of Projects
     *  @return return Project id
     *  if fail, return -1;
     */
    int PushBack(Project);

    /** @brief The function returns the size of the vector
     *  
     *  The function returns the size of the vector
     *  @return return Size of vector.
     *  if fail, return -1;
     */
    int GetSize();

    /** @brief function takes object in Project vector 
     *  
     *  function takes object in Project vector 
     *  @return return Project Object
     */
    Project Get(int i);

    /** @brief Function edit contents in the Project table
     ** The function allows to edit the value of attributes in the Project Object.
     */
    void Edit_Table();

    /** @brief Function add an Project object to list of Projects
     *  
     *  Function add an Project object to list of Projects
     *  @return return true 
     *  
     */
    bool AddMember(Company* ) override;

    /** @brief Function delete an Project object to list of Projects
     *  
     *  Function delete an Project object to list of Projects
     *  @return return true 
     *  if fail, return false
     */
    bool DeleteMember(int ) override;// overriding root class CompanyData

    /** @brief Function to get Projects name with project number insert
     *  @return return the project name if throw project number  
     *  if fail, return blank string
     */
    string GetProjectName(int );

    /** @brief Function overloading with to get Projects name with project number  and department number insert
     *  @return return the project name if throw project number  
     *  if fail, return blank string
     */
    string GetProjectName(int , int );
    
    Project* GetPointer(int i);
    int ExportToFile(string );
};
#endif