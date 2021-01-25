#include <iostream>
#include "businessobject/Employee.h"
#include "dataaccess/EmployeeData.h"
#include "libs/json.hpp"
#include <fstream>
#include <stdio.h>
#include "dataaccess/CompanyData.h"
#include "ui/ui.h"
#include<vector>
using namespace std;
using json = nlohmann::json;


int main()
{   
    Ui ui;
    ui.MainInterface();
    return 0;
}


