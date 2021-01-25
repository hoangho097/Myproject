#include "DeptLocations.h"

using namespace std;

// Default Contructor
DeptLocations::DeptLocations(){}
// Contructor with paramaters
DeptLocations::DeptLocations(int id, int dNumber, string dLocation){
    Id = id;
    DNumber = dNumber;
    DLocation = dLocation;
}

string DeptLocations::ToString(){
    string s;
    s += "{";
    s += to_string(Id) + " ";
    s += to_string(DNumber) + " ";
    s += DLocation + " ";
    s += "}";
    return s;
}

json DeptLocations::ToJson(){
    json j;
    j["Id"] = Id;
    j["DNumber"] = DNumber;
    j["DLocation"] = DLocation;
    return j;
}