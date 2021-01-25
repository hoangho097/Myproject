#ifndef _dataaccess_Dependent_Data_H_
#define _dataaccess_Dependent_Data_H_
#include <vector>
#include <string>
#include "CompanyData.h"
#include "../ui/ui.h"

#include "../businessobject/Dependent.h"
#include "../businessobject/Company.h"
using namespace std;

class DependentData : public CompanyData{
private:
    vector<Dependent> _data;
    int _maxId;
public:

    //No parameter constructor
    DependentData();
    DependentData(string);

    /** @brief The function returns the MaxID of the last element of the vector
     *  
     *  The function returns the MaxID of the last element of the vector
     *  @return return Dependent Max Id
     *  if fail, return -1;
     */
    int GetMaxId();

    /** @brief Function add an Dependent object to list of Dependent
     *  
     *  Function add an Dependent object to list of Dependent
     *  @return return Dependent id
     *  if fail, return -1;
     */
    int PushBack(Dependent);

    /** @brief The function returns the size of the vector
     *  
     *  The function returns the size of the vector
     *  @return return Size of vector.
     *  if fail, return -1;
     */
    int GetSize();

    /** @brief function takes object in Dependent vector 
     *  
     *  function takes object in Dependent vector 
     *  @return return Dependent Object
     */
    Dependent Get(int);

    /** @brief Function edit contents in the Dependent table
     ** The function allows to edit the value of attributes in the Dependent Object.
     */
    void Edit_Table();

    /** @brief Function add an Dependent object to list of Dependents
     *  
     *  Function add an Dependent object to list of Dependents
     *  @return return true 
     *  
     */ 
    bool AddMember(Company* ) override;

    /** @brief Function delete an Dependent object to list of Dependents
     *  
     *  Function delete an Dependent object to list of Dependents
     *  @return return true 
     *  if fail, return false
     */
    bool DeleteMember(int ) override;

    
    Dependent* GetPointer(int i);
    int ExportToFile(string filename);
};
#endif