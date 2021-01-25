#ifndef Project_dataaccess_Department_Data_H_
#define Project_dataaccess_Department_Data_H_
#include <string>
#include <vector>
#include <iostream>
#include "CompanyData.h"
#include "../businessobject/Company.h"
#include "../businessobject/Department.h"
#include "../ui/ui.h"

using namespace std;

class DepartmentData: public CompanyData{
private:
    vector<Department> _data;
    int _maxId;

public:
    //No parameter constructor
    DepartmentData();
    DepartmentData(string fileName);

    /** @brief The function returns the MaxID of the last element of the vector
     *  
     *  The function returns the MaxID of the last element of the vector
     *  @return return Department Max Id
     *  if fail, return -1;
     */
    int GetMaxId();

    /** @brief The function returns the size of the vector
     *  
     *  The function returns the size of the vector
     *  @return return Size of vector.
     *  if fail, return -1;
     */
    int GetSize();

    /** @brief function takes object in Department vector 
     *  
     *  function takes object in Department vector 
     *  @return return Department Object
     */
    Department Get(int i);

    /** @brief Function add an Department object to list of Department
     *  
     *  Function add an Department object to list of Department
     *  @return return Department id
     *  if fail, return -1;
     */
    int PushBack(Department);

    /** @brief Function edit contents in the employee table
     ** The function allows to edit the value of attributes in the employee Object.
     */
    void Edit_Table ();

    /** @brief Function add an Department object to list of Departments
     *  
     *  Function add an Department object to list of Departments
     *  @return return true 
     *  
     */
    bool AddMember(Company* ) override; // overriding root class CompanyData

    /** @brief Function delete an Department object to list of Departments
     *  
     *  Function delete an Department object to list of Departments
     *  @return return true 
     *  if fail, return false
     */
    bool DeleteMember(int ) override;// overriding root class CompanyData
    
    Department* GetPointer(int i);
    int ExportToFile(string ) override;
    
};
#endif