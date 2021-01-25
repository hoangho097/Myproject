#ifndef _PROJECT_H_
#define _PROJECT_H_
#include <string>
#include "../libs/json.hpp"
#include "Company.h"

using json = nlohmann::json;
using namespace std;

class Project : public Company
{
    int Id;
    string PName;
    int PNumber;
    string PLocation;
    int DNum;

public:
    friend class ProjectData;
    // Default Contructor
    Project();
    // Contructor with paramaters
    Project(int , string ,string ,int ,int );
    /** @brief Function convert all attribute like Id, PName... to 1 string
     *  @return return a string of attribute 
     */
    string ToString();
    /** @brief Function convert all attribute like Id, PName... to json with key and value
     *  @return return a string of attribute 
     */
    json ToJson();
    friend Project EnterProjectInfor(Project &project);
};
#endif