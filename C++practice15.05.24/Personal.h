  // Copyright 2024 Matvey Pavlov
#pragma once
#include <iostream>
#include <string>
#include <utility>
#include "Employee.h"
#include"Interfaces.h"

class Personal : public Employee, public Work_Base_Time {
 public:
    Personal(int id, std::string name,
             int workTime, int salary, Positions position);
    int calc_bonus_salary(int bonus = 0) override;
    int calc_base_salary(int salary, int work_time_salary)  override;
 protected:
    int bonus;
    int salary;
};

class Driver : public Personal {
 public:
    Driver(int id, std::string name,
           int work_time, int salary, Positions position);
    void SetNightHours(int bonus = 4);
    int calc_salary() override;
    int calc_bonus_salary(int bonus = 4) override;
};

class Cleaner : public Personal {
 public:
    Cleaner(int id, std::string name,
            int work_time, int salary, Positions position);
    int calc_salary() override;
};
