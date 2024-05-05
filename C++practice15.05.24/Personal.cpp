  // Copyright 2024 Matvey Pavlov
#include"Personal.h"

Personal::Personal(int id, std::string name,
                   int workTime, int salary,
                   Positions position):
                   Employee(id, name, workTime, position) {
    this->salary = salary;
}
int Personal::calc_bonus_salary(int bonus) {
    return bonus * salary;
}

int Personal::calc_base_salary(int salary, int work_time_salary) {
    return salary * work_time_salary;
}

Driver::Driver(int id, std::string name,
    int work_time, int salary, Positions position) :
    Personal(id, name, work_time, salary, position) {}

int Driver::calc_salary() {
    return calc_bonus_salary(bonus) + calc_base_salary(salary, work_time);
}
void Driver::SetNightHours(int bonus) {
    this->bonus = bonus;
}
int Driver::calc_bonus_salary(int bonus) {
    return bonus * salary;
}

Cleaner::Cleaner(int id, std::string name,
    int work_time, int salary, Positions position) :
    Personal(id, name, work_time, salary, position) {}
int Cleaner::calc_salary() {
    return calc_base_salary(salary, work_time);
}
