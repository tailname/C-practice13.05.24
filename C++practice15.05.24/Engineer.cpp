  // Copyright 2024 Matvey Pavlov
#include"Engineer.h"

Engineer::Engineer(const int& id, const std::string& name,
    const int& workTime, const int& salary, const Positions& position,
    Project* project):
    Personal(id, name, workTime, salary, position) {
    this->project = project;
}
void Engineer::SetProject(Project* project) {
    this->project = project;
}
int Engineer::calc_salary() {
    return calc_budget_part() +
           calc_base_salary(salary, work_time) +
           calc_pro_additions(bonus);
}
int Engineer::calc_budget_part() {
    return (static_cast<float>(work_time) /
            project->GetTimeInProject()) *
            project->get_budget();
}


Tester::Tester(const int& id, const std::string& name,
    const int& workTime, const int& salary, const Positions& position,
    Project* project, const uint8_t& found_errors) :
    Engineer(id, name, workTime, salary, position, project) {
    this->bonus = found_errors;
}
int Tester::calc_pro_additions(int bonus) {
    return (bonus / 20) * salary;
}
Programmer::Programmer(const int& id, const std::string& name,
    const int& workTime, const int& salary, const Positions& position,
    Project* project) :
    Engineer(id, name, workTime, salary, position, project) {}
void Programmer::SetPrematurelyWrittenCode(int hours) {
    bonus += hours * 2;
}
int Programmer::calc_pro_additions(int bonus) {
    return calc_bonus_salary(this->bonus);
}


TeamLeader::TeamLeader(const int& id, const std::string& name,
    const int& workTime, const int& salary, const Positions& position,
    Project* project) :
    Programmer(id, name, workTime, salary, position, project) {}
int TeamLeader::calc_Heads() {
    return project->get_num_of_employees() * 1000;
}
int TeamLeader::calc_salary() {
    return salary * work_time +
           calc_budget_part() +
           calc_Heads();
}
