  // Copyright 2024 Matvey Pavlov
#pragma once
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include "Personal.h"
#include"Engineer.h"
#include"Manager.h"
class Factory_Staff {
 private:
     Positions SetPosition(std::string pos);
     std::vector<Project*> projects;
     std::vector<Employee*> empl;
     void MakeProjects();
 public:
    void make_staff();
    std::vector<Employee*> GetStaff();
};

