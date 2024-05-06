  // Copyright 2024 Matvey Pavlov
#include"Employee.h"
Project::Project(int id, int budget, int number_of_employees) {
    this->id = id;
    this->budget = budget;
    this->number_of_employees = number_of_employees;
}
int Project::get_num_of_employees() const {
    return number_of_employees;
}
int Project::get_budget() const {
    return budget;
}

Employee::Employee(int id, std::string name,
    int work_time, Positions position) {
    this->id = id;
    this->name = name;
    this->work_time = work_time;
    this->position = position;
}
int Employee::GetID() const {
    return id;
}
void Employee::calc() {
    payment = calc_salary();
}
void Employee::print_info() {
    std::cout << "ID - " << GetID() << " Name - " << name <<
                 " Time at work - " <<
                 work_time << " h " << " Position - " <<
                 enum_print[position] << " payment - " <<
                 calc_salary() << std::endl;
}
void Project::SetTimeInProject(int time_in_project) {
    this->time_in_project = time_in_project;
}
int Project::GetTimeInProject() const {
    return time_in_project;
}
