#ifndef _dataaccess_Workon_Data_H_
#define _dataaccess_Workon_Data_H_
#include <vector>
#include <string>
#include "CompanyData.h"
#include "../ui/ui.h"
#include "../businessobject/Company.h"
#include "../businessobject/Work_on.h"
using namespace std;

class Work_onData : public CompanyData{
private:
    vector <Work_on> _data;
    int _maxId;
public:
    //No parameter constructor
    Work_onData();
    Work_onData(string);

    /** @brief The function returns the MaxID of the last element of the vector
     *  
     *  The function returns the MaxID of the last element of the vector
     *  @return return Work_on Max Id
     *  if fail, return -1;
     */
    int GetMaxId();

    /** @brief Function add an Work_on object to list of Work_ons
     *  
     *  Function add an Work_on object to list of Work_ons
     *  @return return Work_on id
     *  if fail, return -1;
     */
    int PushBack(Work_on);

    /** @brief The function returns the size of the vector
     *  
     *  The function returns the size of the vector
     *  @return return Size of vector.
     *  if fail, return -1;
     */
    int GetSize();

    /** @brief function takes object in Work_on vector 
     *  
     *  function takes object in Work_on vector 
     *  @return return Work_on Object
     */
    Work_on Get(int);

    /** @brief Function edit contents in the Work_on table
     ** The function allows to edit the value of attributes in the Work_on Object.
     */
    void Edit_Table();
    
    /** @brief Function add an Department object to list of Departments
     *  
     *  Function add an Department object to list of Departments
     *  @return return true 
     *  
     */
    bool AddMember(Company* ) override;

    /** @brief Function delete an Department object to list of Departments
     *  
     *  Function delete an Department object to list of Departments
     *  @return return true 
     *  if fail, return false
     */
    bool DeleteMember(int ) override;

    /** @brief Function get total time to complete project with pno insert
     *  @return return total hours 
     *  if not, return 0
     */
    float GetHoursProject(int );

    /** @brief Function Get employee in a project follow by pno
     *  @return return a vector employee 
     */
    vector<Work_on> GetHoursProjectMin(int );
    
    Work_on* GetPointer(int i);
    int ExportToFile(string filename);
};
#endif