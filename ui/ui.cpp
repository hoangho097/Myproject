#include"ui.h"


void Ui::DisplayEmployee()
{
    EmployeeData employeeData("Employee.data");
    for(int i = 0; i < employeeData.GetSize(); i++)
    {
        Employee employee = employeeData.Get(i);
        cout<< employee.ToString()<<endl;
    }
}


void Ui::DisplayDependent()
{
    DependentData dependentData("Dependent.data");
    for(int i = 0; i<dependentData.GetSize() ; i++)
    {
        Dependent dependent = dependentData.Get(i);
        cout<< dependent.ToString()<<endl;
    }
}


void Ui::DisplayProject()
{
    ProjectData projectData("Project.data");
    for(int i = 0; i<projectData.GetSize() ; i++)
    {
        Project project = projectData.Get(i);
        cout<< project.ToString()<<endl;
    }
}


void Ui::DisplayWork_on()
{
    Work_onData work_onData("Work_on.data");
    for(int i =0;i<work_onData.GetSize();i++)
    {
        Work_on work_on = work_onData.Get(i);
        cout<< work_on.ToString()<<endl;
    }
}


void Ui::DisplayDepartment()
{
    DepartmentData departmentData("Department.data");
    for(int i =0;i<departmentData.GetSize();i++)
    {
        Department department = departmentData.Get(i);
        cout<< department.ToString()<<endl;
    }
}


void Ui::DisplayDeptLocations()
{
    DeptLocationsData deptLocationsData("DeptLocations.data");
    for(int i = 0; i<deptLocationsData.GetSize(); i++)
    {
        DeptLocations deptLocations = deptLocationsData.Get(i);
        cout<< deptLocations.ToString()<<endl;
    }
}

// Question 2
void Ui :: RestructureCompany()
{
    EmployeeData employeeArray("Employee.data");
    cout<<"Read file function"<<"\n";
    for(int i=0; i<employeeArray.GetSize(); ++i)
    {
        Employee p = employeeArray.Get(i);
        cout<<p.ToString()<<endl;
    }
    string name;
    cout<<"Please enter an administrator name:  "; cin >> name;
    cout<<"List employee of "<<endl;
    cout<<employeeArray.Restructure(name);
}

// Question 3
void Ui :: EmployeeHaveChild()
{   long a;
    DependentData dependentData("Dependent.data");
    EmployeeData employeeData("Employee.data");
    for(int i = 0 ; i < dependentData.GetSize() ; i++)
    {   
        a = dependentData.Get(i).GetESSN();
        if( UpperString(dependentData.Get(i).GetRelationship()) == "DAUGHTER" || UpperString(dependentData.Get(i).GetRelationship()) == "SON" )
        {
            for( int j = 0 ; j < employeeData.GetSize() ; j++ ) 
            {
                if(employeeData.Get(j).GetSSN() == a)
                {
                    Employee employee = employeeData.Get(j);
                    cout<< employee.ToString() <<endl;
                }
            }
        }
    }
}

//Question 4
void Ui :: GetNameProjectHours()
{
    int projectNumber;
    float projectHour;
    string projectName;
    cout<<" Enter the project number: "; cin>>projectNumber;
    ProjectData projectData("Project.data");
    projectName = projectData.GetProjectName(projectNumber);
    cout<<"The project name is: "<<projectName<<endl;
    Work_onData work_onData("Work_on.data");
    projectHour = work_onData.GetHoursProject(projectNumber);
    cout<<"Total hours is: "<<projectHour<<endl;
}

// Question 5
void Ui :: EmployeeDontHaveProject()
{   
    cout<<"Employees don't have any Project in Employee Table"<<endl;
    int find = 0;
    long ssn;
    Work_onData work_onData("Work_on.data");
    EmployeeData employeeData("Employee.data");
    for (int i = 0 ; i < employeeData.GetSize() ; i++)
    {
        ssn = employeeData.Get(i).GetSSN();
        for(int j = 0; j < work_onData.GetSize(); j++)
        {
            if(ssn == work_onData.Get(j).GetESSN()) 
            {   
                find = 1;
                break;
            }
        }
        if(find == 0)
        {
            Employee employee = employeeData.Get(i);
            cout << employee.ToString()<< endl;
        }
        find = 0;
    }

}

// Question 6
void Ui:: AverageSalaryOfDeparment()
{
    string departmentName;
    cout<<"Please enter department name: "<<endl;
    cin>>departmentName;
    DepartmentData departmentData("Department.data");
    EmployeeData employeeData("Employee.data");
    for(int i = 0; i < departmentData.GetSize(); ++i){
        if(departmentData.Get(i).GetDName() == departmentName){
            cout<<"Department number is: "<<departmentData.Get(i).GetDnumber()<<endl;
            cout<<"Average salary: "<<employeeData.CalculateSalary(departmentData.Get(i).GetMgrSSN())<<endl;
            cout<< endl;
        }
    }
}

//Question 7
void Ui :: AverageSalaryByGender()
{   
    system("cls");
    char c;
    cout <<" Please enter the gender for which you want to see the average salary."<<endl;
    cout << "1. F" <<endl;
    cout << "2. M" <<endl;
    cout<< "Gender: "; cin >> c;
    int Count = 0;
    int SalarySum = 0;
    cout<<"Average salaries of all employees by gender"<<endl;
    cout << endl;
    EmployeeData employeeData("Employee.data");
    if(c == 'F')
    {
        for (int i = 0 ; i < employeeData.GetSize(); i++ )
        {   
            Employee employee = employeeData.Get(i);
            if( employee.GetSex() == 'F')
            {
                SalarySum += employee.GetSalary();
                Count ++;
            }
                
        }
        cout<<"Average salary of female employees: "<< SalarySum/Count<<endl;
        cout<< endl;
    }
    else
    {
        for (int i = 0 ; i < employeeData.GetSize(); i++ )
        {   
            Employee employee = employeeData.Get(i);
            if( employee.GetSex() == 'M')
            {
                SalarySum += employee.GetSalary();
                Count ++;
            }
        }
        cout<<"Average salary of male employees: "<< SalarySum/Count<<endl;
        cout <<endl;
    }
    
}

// Question 8
void Ui::LastNameOfManager()
{
    bool Check = false;
    EmployeeData employeeData("Employee.data");
    DepartmentData departmentData("Department.data");
    DependentData dependentData("Dependent.data");
    cout<<" The Last Name of the department manager is single "<<endl;
    for( int i = 0; i < departmentData.GetSize(); i++)
    {   
        Department department = departmentData.Get(i);
        long ssn = department.GetMgrSSN();
        for(int j = 0; j < dependentData.GetSize(); j++)
        {
            Dependent dependent = dependentData.Get(j);
            if(ssn == dependent.GetESSN())
            {
                Check = true; break;
            } 
        }
        if(Check == false)
        {
            for(int k = 0; k < employeeData.GetSize(); k++)
            {   
                Employee employee = employeeData.Get(k);
                if(ssn == employee.GetSSN())
                {
                    cout<< "Last name : " << employee.GetLName() << endl;
                }
            }
        }
        Check = false;
    }
}

// Quetion 9
void Ui:: GetHoursProjectEmployeeName(){
    int projectNumber;
    int departmentNumber;
    //Get data from file
    ProjectData projectData("Project.data");
    Work_onData work_onData("Work_on.data");
    EmployeeData employeeData("Employee.data");

    cout<<"Insert department number: "; cin>>departmentNumber;
    cout<<"Insert project number: "; cin>>projectNumber;
    //The results
    cout<<"The project is: "<<projectData.GetProjectName(projectNumber, departmentNumber);

    string nameMemberProject;
    float hours = 0;//Initial default value of hours  

    vector<Work_on> employeeProject;
    employeeProject = work_onData.GetHoursProjectMin(projectNumber);
    
    vector<Employee> departmentMember;
    departmentMember = employeeData.FindEmployeeDepartment(departmentNumber); 
    //Find the name of an employee in the project
    for(int i = 0; i < employeeProject.size(); ++i)
    {
        //Find employee in Project table with employee table
        for(int j = 0; j < departmentMember.size(); ++j)
        {
            if(employeeProject[i].GetESSN() == departmentMember[j].GetSSN())
            {
                if(hours == 0) // The first value of employee table match with project table
                {
                    hours = employeeProject[i].GetHours();
                }
                nameMemberProject += departmentMember[j].GetName() + " ";
            }
        }
    }
    cout << "The names are: "<<endl;
    cout << nameMemberProject<<endl;
    cout <<"The hous minimum is: "<< hours<<endl;
    cout << endl;
}

//Question 10
void Ui :: DataBackUp()
{   
    bool Iscontinue = true;
    system("cls"); 
    int Choice;
    string myDir = "DataBase";
    string strLocalDay;
    string strTime;
    const char* dataFolder = myDir.c_str();
    mkdir(dataFolder);

    //Create a day folder
    time_t now =time(0);
    tm *pTime = localtime(&now);
    strLocalDay = "/" + to_string(1900 + pTime->tm_year) + "_" + to_string(1 + pTime->tm_mon) + "_" + to_string(pTime->tm_mday) + "/";
    myDir += strLocalDay;
    const char* daysFolder = myDir.c_str();
    mkdir(daysFolder);

    //Create a time folder
    // strTime = to_string(5+pTime->tm_hour) + "_" + to_string(30+pTime->tm_min) + "_" + to_string(pTime->tm_sec);
    strTime = to_string(pTime->tm_hour) + "_" + to_string(pTime->tm_min) + "_" + to_string(pTime->tm_sec) + "/";
    myDir += strTime;
    const char* timeFolder = myDir.c_str();
    mkdir(timeFolder);

    cout << "Data backup feature "<<endl;
    cout << "Please Please select the file you want to backup "<<endl;
    cout << "1. Employee.data"<<endl;
    cout << "2. Dependent.data"<<endl;
    cout << "3. Department.data"<<endl;
    cout << "4. Work_on.data"<<endl;
    cout << "5. DeptLocation.data"<<endl;
    cout << "6. Project.data"<<endl;
    cout << "Your Choice: " ; cin >> Choice;
    switch (Choice)
    {
    case 1:
        myDir += "Employee.data";
        EmployeeData employeeData("Employee.data");
        employeeData.ExportToFile(myDir);
        cout << "this is " << myDir;
        break;
    // case 2:
    //     myDir += "Dependent.data";
    //     DependentData dependentData("Dependent.data");
    //     dependentData.ExportToFile(myDir);
    //     break;
    // // case 3:
    //     myDir += "Department.data";
    //     DepartmentData departmentData("Department.data");
    //     departmentData.ExportToFile(myDir);
    //     break;
    // case 4:
    //     myDir += "Work_on.data";
    //     Work_onData work_onData("Work_on.data");
    //     work_onData.ExportToFile(myDir);
    //     break;
    // case 5:
    //     myDir += "DeptLocation.data";
    //     DeptLocationsData deptLocationsData("DeptLocation.data");
    //     deptLocationsData.ExportToFile(myDir);
    //     break;
    // case 6:
    //     myDir += "Project.data";
    //     ProjectData projectData("Project.data");
    //     projectData.ExportToFile(myDir);
    //     break;
    // case 0:
    //     Iscontinue = false;
    //     break;
    // default:
    //     cout<<"Please Enter Again !"<<endl;
    //     break;
    }
        cout<< "Successfully! Here's your link: " << myDir << "\n\n";
}


void Ui::MainInterface()
{
    bool Iscontinue = true;
    do{ 
        int Choice;
        cout <<"==========================================================================="<<endl;
        cout <<"********Choose funtion that you want to use *********"<<endl;
        cout << "1. Display/Edit/Delete/Add Element in The Table"<<endl;
        cout << "2. Display the names of all employees who are supervised by a particular manager"<<endl;
        cout << "3. Display Employee have Child" <<endl;
        cout << "4. Displays the specific project name and the total number of hours an employee has to work on that project"<<endl;
        cout << "5. Display Employees don't have any Project"<<endl;
        cout << "6. Displays the name of the department and the average salary of the employees working for that department."<<endl;
        cout << "7. Average salaries of all employees by gender"<<endl;
        cout << "8. The Last Name of the department manager is single"<<endl;
        cout << "9. Displays the names of all employees in a department and working for a specific project"<<endl;
        cout << "10 Back Up Data" <<endl;
        cout<<"============================================================"<<endl;
        cout<<"your Choice_"; cin >> Choice;
       
        switch (Choice) // choose sentence
        {
        case 1:
            ChooseTable();
            break;
        case 2:
            RestructureCompany();
            break;
        case 3:
            EmployeeHaveChild();
            break;
        case 4:
            GetNameProjectHours();
            break;
        case 5:
            EmployeeDontHaveProject();
            break;
        case 6:
            AverageSalaryOfDeparment();
            break;
        case 7:
            AverageSalaryByGender();
            break;
        case 8:
            LastNameOfManager();
            break;
        case 9:
            GetHoursProjectEmployeeName();
            break;
        case 10:
            DataBackUp();
            break;
        default:
            system("cls");
            cout<<"please Enter Again"<<endl;
            break;
        }
    }while (Iscontinue ==true); 
}


void Ui::ChooseTable()
{   system("cls");
    bool Iscontinue = true;
    do 
    {
        int SubChoice;
        cout<<"**************************************************************"<<endl;
        cout<<"#####         select the Table you want to use          ######"<<endl;
        cout<<"                     ******************                       "<<endl;
        cout<<"1. Employee table"<<endl;
        cout<<"2. Department table"<<endl;
        cout<<"3. Dept_Location table"<<endl;
        cout<<"4. Project table"<<endl;
        cout<<"5. Work_on table"<<endl;
        cout<<"6. Dependent table"<<endl;
        cout<<"0. Stop"<<endl;
        cout<<"***************************************************************"<<endl;
        cout<<"Your choice_"; cin >> SubChoice;
        switch (SubChoice)
        {
        case 1:
            ChooseFuntion(SubChoice);
            break;
        case 2:
            ChooseFuntion(SubChoice);
            break;
        case 3:
            ChooseFuntion(SubChoice);
            break;
        case 4:
            ChooseFuntion(SubChoice);
            break;
        case 5:
            ChooseFuntion(SubChoice);
            break;
        case 6:
            ChooseFuntion(SubChoice);
            break;
        default:
            cout<<" Please Enter again";
            break;
        }
        if(SubChoice == 0)
        {
            Iscontinue = false ;
            system("cls");
        }
    }
    while(Iscontinue==true);
}

void Ui:: ChooseFuntion(int Subchoice)
{   system("cls");
    bool Iscontinue = true;
    do
    {

        int Subchoice2;
        cout<<"**************************************************************"<<endl;
        cout<<"#####          select the function you want to use      ######"<<endl;
        cout<<"                       ******************                     "<<endl;
        cout<<" 1. Display the Table"<<endl;
        cout<<" 2. Edit the content of the table"<<endl;
        cout<<" 3. Add elements to the table"<<endl;
        cout<<" 4. Delete elements from the table"<<endl;
        cout<<" 0. Stop"<<endl;
        cout<<"**************************************************************"<<endl;
        cout<<"Your choice__"; cin>> Subchoice2;
        switch (Subchoice2)
        {
        case 1:
            if(Subchoice == 1)
            {
                DisplayEmployee();
            }
            if(Subchoice == 2)
            {
                DisplayDepartment();
            }
            if(Subchoice ==3)
            {
                DisplayDeptLocations();
            }
            if(Subchoice == 4)
            {
                DisplayProject();
            }
            if(Subchoice == 5)
            {
                DisplayWork_on();
            }
            if(Subchoice == 6)
            {
                DisplayDependent();
            }
            break;
        case 2:
            if(Subchoice == 1)
            {   
                CompanyData *companyData = new EmployeeData;
                companyData->Edit_Table();
            }
            if(Subchoice == 2)
            {
                CompanyData *companyData = new DepartmentData;
                companyData->Edit_Table();
            }
            if(Subchoice == 3)
            {
                CompanyData *companyData = new DeptLocationsData;
                companyData->Edit_Table();
            }
            if(Subchoice == 4)
            {
                CompanyData *companyData = new ProjectData;
                companyData->Edit_Table();
            }
            if(Subchoice == 5)
            {
                CompanyData *companyData = new Work_onData;
                companyData->Edit_Table();
            }
            if(Subchoice == 6)
            {
                CompanyData *companyData = new DependentData;
                companyData->Edit_Table();
            }
            break;
        case 3:
            if(Subchoice == 1)
            {   
                CreateEmployee();
            }
            if(Subchoice == 2)
            {   
                CreateDepartment();
            }
            if(Subchoice == 3)
            {   
                CreateDeptLocations();
            }
            if(Subchoice == 4)
            {   
                CreateProject();
            }
            if(Subchoice == 5)
            {   
                CreateWork_on();
            }
            if(Subchoice == 6)
            {   
                CreateDependent();
            }
            break;
        case 4:
            if(Subchoice == 1)
            {
                DeleteEmployee();
            }
            if(Subchoice == 2)
            {
                DeleteDepartment();
            }
            if(Subchoice == 3)
            {
                DeleteDeptLocations();
            }
            if(Subchoice == 4)
            {
                DeleteProject();
            }
            if(Subchoice == 5)
            {
                DeleteWork_on();
            }
            if(Subchoice == 6)
            {
                DeleteDependent();
            }
            break;
        }
        if(Subchoice2 == 0) 
        {
            Iscontinue = false;
            system ("cls");
        }
    }
    while(Iscontinue==true );
};


Employee EnterEmployeeInfor(Employee &employee)
{   
    cout <<"Old Data:  ";
    cout << employee.ToString()<<endl;
    cout <<endl;
    bool Iscontinue = true;
    do
    {
        int n;
        cout<<endl;
        cout<<"Choose Information that you want to edit"<<endl;
        cout<<"1.FName: "<<endl;
        cout<<"2.MInit_: "<<endl;
        cout<<"3.LName_: "<<endl;
        cout<<"4.SSN_: "<<endl;
        cout<<"5.BDate_: "<<endl;
        cout<<"6.Address_: "<<endl;
        cout<<"7.Salary_: "<<endl;
        cout<<"8.SuperSSN_: "<<endl;
        cout<<"9.DNO_: "<<endl;
        cout<<"10.SEX_: "<<endl;
        cout<<"0. Stop"<<endl;
        cout<<"Your Choice: ";
        cin >> n;
        switch (n)
        {
        case 1:
            cout<<"Enter FName: ";
            cin.ignore();
            getline(cin, employee.FName);
            break;
        case 2: 
            cout<<"Enter MInit_: ";
            cin.ignore();
            getline(cin, employee.MInit);
            break;
        case 3: 
            cout<<"Enter LName_: ";
            cin.ignore();
            getline(cin ,employee.LName);
            break;
        case 4: 
            cout<<"Enter SSN_: ";
            cin >> employee.SSN;
            break;
        case 5: 
            cout<<"Enter BDate_: ";
            cin.ignore();
            getline(cin,employee.BDate);
            break;
        case 6: 
            cout<<"Enter Address_: ";
            cin.ignore();
            getline(cin ,employee.Address);
            break;
        case 7: 
            cout<<"Enter Salary_: ";
            cin >> employee.Salary;
            break;
        case 8: 
            cout<<"Enter SuperSSN_: ";
            cin >> employee.SuperSSN;
            break;
        case 9: 
            cout<<"Enter DNO_: ";
            cin >> employee.DNO;
            break;
        case 10: 
            cout<<"Enter SEX_: ";
            cin >> employee.Sex;
            break;
        case 0:
            Iscontinue = false;
            break;
        default:
        cout<<" please Enter Again";
            break;
        }
    }while(Iscontinue == true);
    cout <<endl;
    cout << "Data has been changed "<<endl;
    cout<< employee.ToString()<<endl;
    cout<< endl;
    return employee;
}


Dependent EnterDependentInfor(Dependent &dependent)
{   
    cout <<"Old Data:  ";
    cout << dependent.ToString()<<endl;
    cout <<endl;
    bool Iscontinue = true;
    do
    {
        int n;
        cout<< endl;
        cout<<"Choose Information that you want to edit"<<endl;
        cout<<"1.ESSN : "<<endl;
        cout<<"2.DependentName : "<<endl;
        cout<<"3.Sex : "<<endl;
        cout<<"4.BDate : "<<endl;
        cout<<"5.Relationship: "<<endl;
        cout<<"0. Stop"<<endl;
        cout<<"Your Choice: ";
        cin >> n;
        switch (n)
        {
        case 1:
            cout<<"Enter ESSN: ";
            cin >> dependent.ESSN;
            break;
        case 2: 
            cout<<"Enter DependentName: ";
            cin.ignore();
            getline(cin, dependent.DependentName);
            break;
        case 3: 
            cout<<"Enter Sex: ";
            cin >> dependent.Sex;
            break;
        case 4: 
            cout<<"Enter BDate: ";
            cin.ignore();
            getline(cin ,dependent.BDate);
            break;
        case 5: 
            cout<<"Enter Relationship: ";
            cin.ignore();
            getline(cin,dependent.Relationship);
            break;
        case 0:
            Iscontinue = false;
            break;
        default:
        cout<<" please Enter Again";
            break;
        }
    }while(Iscontinue == true);
    cout <<endl;
    cout << "Data has been changed "<<endl;
    cout<< dependent.ToString()<<endl;
    cout<< endl;
    return dependent;
}

Work_on EnterWork_onInfor(Work_on &work_on)
{   
    bool Iscontinue = true ;
    cout <<"Old Data:  ";
    cout << work_on.ToString()<<endl;
    cout <<endl;
    do 
    {
        int n;
        cout<< endl;
        cout<<"Choose Information that you want to edit"<<endl;
        cout<<"1. ESSN : "<<endl;
        cout<<"2. PNO : "<<endl;
        cout<<"3. Hours : "<<endl;
        cout<<"0. Stop"<<endl;
        cout<<"Your Choice: ";
        cin >> n;
        switch (n)
        {
        case 1:
            cout<<"Enter ESSN: ";
            cin >> work_on.ESSN;
            break;
        case 2: 
            cout<<"Enter PNO: ";
            cin >> work_on.PNO;
            break;
        case 3: 
            cout<<"Enter Hours: ";
            cin >> work_on.Hours;
            break;
        case 0:
            Iscontinue = false;
            break;
        default:
        cout<<" please Enter Again";
            break;
        }
    
    }while(Iscontinue == true);
    cout <<endl;
    cout << "Data has been changed "<<endl;
    cout<< work_on.ToString()<<endl;
    cout<< endl;
    return work_on;
}

Project EnterProjectInfor(Project &project)
{   
    bool Iscontinue = true ;
    cout <<"Old Data:  ";
    cout << project.ToString()<<endl;
    cout <<endl;
    do
    {
        int n;
        cout<<endl;
        cout<<"Choose Information that you want to edit"<<endl;
        cout<<"1. PName : "<<endl;
        cout<<"2. PNumber : "<<endl;
        cout<<"3. PLocation : "<<endl;
        cout<<"4. DNum"<<endl;
        cout<<"0. Stop"<<endl;
        cout<<"Your Choice: ";
        cin >> n;
        switch (n)
        {
        case 1:
            cout<<"Enter PName: ";
            cin.ignore();
            getline(cin, project.PName);
            break;
        case 2: 
            cout<<"Enter PNumber: ";
            cin >> project.PNumber;
            break;
        case 3: 
            cout<<"Enter PLocation: ";
            cin.ignore();
            getline(cin ,project.PLocation);
            break;
        case 4: 
            cout<<"Enter DNum: ";
            cin >> project.DNum;
            break;
        case 0:
            Iscontinue = false;
            break;
        default:
        cout<<" please Enter Again";
            break;
        }
    } while(Iscontinue == true);
    cout<<endl;
    cout << "Data has been changed "<<endl;
    cout<< project.ToString()<<endl;
    cout<<endl;
    return project;
}

Department EnterDepartmentInfor(Department &department)
{   
    bool Iscontinue = true ;
    cout <<"Old Data:  ";
    cout << department.ToString()<<endl;
    cout <<endl;
    do
    {
        int n;
        cout<<endl;
        cout<<"Choose Information that you want to edit"<<endl;
        cout<<"1. DName : "<<endl;
        cout<<"2. MgrSSN : "<<endl;
        cout<<"3. Dnumber : "<<endl;
        cout<<"4. MgrStartDate : "<<endl;
        cout<<"0. Stop"<<endl;
        cout<<"Your Choice: ";
        cin >> n;
        switch (n)
        {
        case 1:
            cout<<"Enter DName: ";
            cin.ignore();
            getline(cin ,department.DName);
            break;
        case 2: 
            cout<<"Enter MgrSSN: ";
            cin >> department.MgrSSN;
            break;
        case 3: 
            cout<<"Enter Dnumber: ";
            cin >> department.Dnumber;
            break;
        case 4: 
            cout<<"Enter MgrStartDate: ";
            cin.ignore();
            getline(cin,department.MgrStartDate);
            break;
        case 0:
            Iscontinue = false;
            break;
        default:
            cout<<" please Enter Again";
            break;
        }
    }while(Iscontinue == true);
    cout<<endl;
    cout << "Data has been changed "<<endl;
    cout<< department.ToString()<<endl;
    cout<<endl;
    return department;
}

DeptLocations EnterDeptLocationInfor(DeptLocations &deptLocations)
{   
    bool Iscontinue = true ;
    cout <<"Old Data:  ";
    cout << deptLocations.ToString()<<endl;
    cout <<endl;
    do
    {
        int n;
        cout<<endl;
        cout<<"Choose Information that you want to edit"<<endl;
        cout<<"1. DNumber : "<<endl;
        cout<<"2. DLocation : "<<endl;
        cout<<"0. Stop"<<endl;
        cout<<"Your Choice: ";
        cin >> n;
        switch (n)
        {
        case 1:
            cout<<"Enter DNumber: ";
            cin >> deptLocations.DNumber;
            break;
        case 2: 
            cout<<"Enter DLocation: ";
            cin.ignore();
            getline(cin,deptLocations.DLocation);
            break;
        case 0:
            Iscontinue = false;
            break;
        default:
            cout<<" please Enter Again";
            break;
        }
    }while(Iscontinue == true);
    cout<<endl;
    cout << "Data has been changed "<<endl;
    cout<< deptLocations.ToString()<<endl;
    cout<<endl;
    return deptLocations;
}

int Ui::ChooseToEdit()
{ 
    cout<<"|** Please enter the Id of the Table that you want to edit **|" <<endl;
    cout<<" ID: "; 
    int n;
    cin >> n;
    n = n-1 ;
    return n;
}

void Ui::CreateEmployee()
{
    bool isContinue = true;       
    CompanyData* companyData = new EmployeeData("Employee.data");

    while(isContinue){
        // cout<<""
        if(isContinue == 1){

        int id; string fName; string mInit; string lName; long ssn; string bDate; string address; char sex; int salary; long superSSN; int dno;
        
        // cout<<"Id: "; cin>>id;
        cout<<"First Name: "; cin>>fName; 
        cout<<"Midle Name: "; cin>> mInit; 
        cout<<"Last name: "; cin>>lName; 
        cout<<"SSN: "; cin>>ssn; 
        cout<<"Birthday: "; fflush(stdin); getline(cin, bDate); 
        cout<<"Address: "; getline(cin, address); 
        cout<<"Sex: "; cin>>sex; 
        cout<<"Salary: "; cin>>salary; 
        cout<<"super SSN "; cin>>superSSN; 
        cout<<"DNO: "; cin>>dno;

        Company* pC = new Employee(0, fName, mInit, lName, ssn, bDate, address, sex, salary, superSSN, dno);

        companyData->AddMember(pC);
        
        }else if(isContinue == 0){
            isContinue = false;
        }
        cout<< "0. stop"<<endl; 
        cin>>isContinue;
        
        companyData->ExportToFile("Employee.data");
    }
}



void Ui::CreateDepartment()
{
    string dName; long mgrSSN; string mgrStartDate; int dNumber;
    cout<<"dName: "; cin>> dName; 
    cout<<"mgrSSN: "; cin>> mgrSSN; 
    cout<<"mgrStartDate: "; fflush(stdin); getline(cin, mgrStartDate); 
    cout<<"dNumber: "; cin>>dNumber; 
    Company* pC = new Department(0, dName, mgrSSN, mgrStartDate, dNumber);
    CompanyData* companyData = new DepartmentData("Department.data");
    companyData->AddMember(pC);
    companyData->ExportToFile("Department.data");
}

void Ui :: CreateProject()
{
    bool isContinue = true;
    CompanyData* companyData = new ProjectData("Project.data");
    do
    {
        if(isContinue == 1)
        {
            // int id, string pName,string pLocation,int pNumber,int dNum
        string pName; string pLocation; int pNumber; int dNum;
        cout<<"pName: "; fflush(stdin); getline(cin, pName); 
        cout<<"pLocation: "; fflush(stdin); getline(cin, pLocation); 
        cout<<"pNumber: "; cin >> pNumber; 
        cout<<"dNum: "; cin >> dNum; 
        Company* pC = new Project(0, pName, pLocation, pNumber, dNum);
        companyData->AddMember(pC);
        }
        else if(isContinue == 0)
        {
        isContinue = false;
        }
        cout<<"0. To stop"; cin >> isContinue;
    } while (isContinue);
    companyData->ExportToFile("Project.data");
}

void Ui::CreateWork_on(){    
    bool isContinue = true;
    CompanyData* companyData = new Work_onData("Work_on.data");

    do
    {
        if(isContinue == 1){    
            int Id; long ESSN; int PNO; float Hours;
            cout<<"ESSN: "; cin >> ESSN; 
            cout<<"PNO: "; cin >> PNO; 
            cout<<"Hours: "; cin >> Hours; 
            Company* pC = new Work_on(0, ESSN, PNO, Hours);

            companyData->AddMember(pC);

        }
        else if(isContinue == 0){
            isContinue = false;
        }

        cout<<"0. To stop"; cin >> isContinue;

    } while (isContinue);
    companyData->ExportToFile("Work_on.data");
}

void Ui::CreateDependent()
{
    bool isContinue = true;
    CompanyData* companyData = new DependentData("Dependent.data");

    do
    {
        if(isContinue == 1)
        {
            int Id; long ESSN; string DependentName; char Sex; string BDate; string Relationship;            
            cout<<"ESSN: "; cin>> ESSN; 
            cout<<"DependentName: "; fflush(stdin); getline(cin, DependentName); 
            cout<<"Sex: "; cin>> Sex; 
            cout<<"BDate: "; fflush(stdin); getline(cin, BDate); 
            cout<<"Relationship: "; fflush(stdin); getline(cin, Relationship); 
            Company* pC = new Dependent(0, ESSN, DependentName, Sex, BDate, Relationship);
            companyData->AddMember(pC);
        }
        else if(isContinue == 0)
        {
            isContinue = false;
        }
        cout<<"0. To stop"; cin >> isContinue;
    } while (isContinue);
    companyData->ExportToFile("Dependent.data");
}

void Ui::CreateDeptLocations()
{
    bool isContinue = true;
    CompanyData* companyData = new DeptLocationsData("DeptLocations.data");
    do
    {
        if(isContinue == 1){
            int dNumber; string dLocation;
            
            cout<<"dNumber: "; cin>> dNumber; 
            cout<<"dLocation: "; fflush(stdin); getline(cin, dLocation); 
            Company* pC = new DeptLocations(0, dNumber, dLocation);
            companyData->AddMember(pC);

        }else if(isContinue == 0){
            isContinue = false;
        }

        cout<<"0. To stop"; cin >> isContinue;

    } while (isContinue);
    companyData->ExportToFile("DeptLocations.data");

}
//me
void Ui::DeleteEmployee()
{   int Id; 
    cout<<"please Enter Id of table that you want to delete"<<endl;
    cout<<"Id: "; cin >> Id;
    CompanyData* companyData= new EmployeeData("Employee.data");
    --Id;
    companyData->DeleteMember(Id);
    companyData->ExportToFile("Employee.data");
}

void Ui::DeleteProject()
{   int Id; 
    cout<<"please Enter Id of table that you want to delete"<<endl;
    cout<<"Id: "; cin >> Id;
    CompanyData* companyData= new ProjectData("Project.data");
    --Id;
    companyData->DeleteMember(Id);
    companyData->ExportToFile("Project.data");
}

void Ui::DeleteDepartment()
{   int Id; 
    cout<<"please Enter Id of table that you want to delete"<<endl;
    cout<<"Id: "; cin >> Id;
    CompanyData* companyData= new DepartmentData("Department.data");
    --Id;
    companyData->DeleteMember(Id);
    companyData->ExportToFile("Department.data");
}

void Ui::DeleteWork_on()
{   int Id; 
    cout<<"please Enter Id of table that you want to delete"<<endl;
    cout<<"Id: "; cin >> Id;
    CompanyData* companyData= new Work_onData("Work_on.data");

    --Id;
    companyData->DeleteMember(Id);
    companyData->ExportToFile("Work_on.data");
}

void Ui::DeleteDependent()
{   int Id; 
    cout<<"please Enter Id of table that you want to delete"<<endl;
    cout<<"Id: "; cin >> Id;
    CompanyData* companyData= new DependentData("Dependent.data");

    --Id;
    companyData->DeleteMember(Id);
    companyData->ExportToFile("Dependent.data");
}

void Ui::DeleteDeptLocations()
{   int Id; 
    cout<<"please Enter Id of table that you want to delete"<<endl;
    cout<<"Id: "; cin >> Id;
    CompanyData* companyData= new DeptLocationsData("DeptLocations.data");
    --Id;
    companyData->DeleteMember(Id);
    companyData->ExportToFile("DeptLocations.data");
}

string Ui :: UpperString(string s)
{
    transform(s.begin(), s.end(), s.begin(),::toupper);
    return s;
}