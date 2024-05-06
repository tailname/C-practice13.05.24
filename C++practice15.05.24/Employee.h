  // Copyright 2024 Matvey Pavlov
#pragma once
#include <string>
#include <vector>
#include<iostream>

enum Positions {
    programmer,
    team_leader,
    project_manager,
    senior_manager,
    cleaner,
    driver,
    tester,
};
class Project {
 public:
    Project(int id, int budget, int number_of_employees);
    int get_num_of_employees() const;
    int get_budget() const;
    void SetTimeInProject(int time_in_project);
    int GetTimeInProject() const;
 private:
    int time_in_project;
    int id;
    int budget;
    int number_of_employees;
};
class Employee {
 public:
    virtual ~Employee() = default;
    Employee(int id, std::string name,
             int work_time, Positions position);
    int GetID() const;
    virtual int calc_salary() = 0;
    void print_info();
    void calc();
 private:
    int id;
 protected:
    Positions position;
    int payment;
    int work_time;
    std::string name;
    std::vector<std::string> enum_print = {"programmer",
                                           "team_leader",
                                           "project_manager",
                                           "senior_manager",
                                           "cleaner",
                                           "driver",
                                           "tester"};
};
