#ifndef _dataaccess_DeptLocations_Data_H_
#define _dataaccess_DeptLocations_Data_H_
#include <string>
#include <vector>
#include <iostream>
#include "CompanyData.h"
#include "../businessobject/Company.h"
#include "../businessobject/DeptLocations.h"
#include "../ui/ui.h"

using namespace std;

class DeptLocationsData : public CompanyData
{
    private:
        vector<DeptLocations> _data;
        int _maxId;
    public:
        //No parameter constructor
        DeptLocationsData();
        DeptLocationsData(string fileName);

        /** @brief The function returns the MaxID of the last element of the vector
         *  
         *  The function returns the MaxID of the last element of the vector
         *  @return return DeptLocations Max Id
         *  if fail, return -1;
         */
        int GetMaxId();

        /** @brief Function add an DeptLocations object to list of DeptLocations
         *  
         *  Function add an DeptLocations object to list of DeptLocations
         *  @return return DeptLocations id
         *  if fail, return -1;
         */
        int PushBack(DeptLocations s);

        /** @brief The function returns the size of the vector
         *  
         *  The function returns the size of the vector
         *  @return return Size of vector.
         *  if fail, return -1;
         */
        int GetSize();

        /** @brief function takes object in DeptLocations vector 
         *  
         *  function takes object in DeptLocations vector 
         *  @return return DeptLocations Object
         */
        DeptLocations Get(int i);

        /** @brief Function edit contents in the DeptLocations table
         ** The function allows to edit the value of attributes in the DeptLocations Object.
        */
        void Edit_Table();

        /** @brief Function add an DeptLocation object to list of DeptLocations
         *  
         *  Function add an DeptLocation object to list of DeptLocations
         *  @return return true 
         *  
         */
        bool AddMember(Company* p ) override;

        /** @brief Function delete an DeptLocation object to list of DeptLocations
         *  
         *  Function delete an DeptLocation object to list of DeptLocations
         *  @return return true 
         *  if fail, return false
         */
        bool DeleteMember(int ) override;
        
        DeptLocations* GetPointer(int i);
        int ExportToFile(string );
};
#endif