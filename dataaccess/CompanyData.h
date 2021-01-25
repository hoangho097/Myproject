#ifndef _dataaccess_Company_Data_H_
#define _dataaccess_Company_Data_H_
#include "../businessobject/Employee.h"
#include "../businessobject/Company.h"
#include<vector>
using namespace std;


class CompanyData
{
     public:
          virtual void Edit_Table() = 0;
          virtual int ExportToFile(string filename) = 0;
          //Create a member of the table
          virtual bool AddMember(Company* ) = 0;
          //D a member of the table by Id 
          virtual bool DeleteMember(int ) = 0;
};

#endif