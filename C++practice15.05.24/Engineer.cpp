#include"Engineer.h"

Engineer::Engineer(const int& id, const std::string& name,
	const int& workTime, const int& salary, const Positions& position,
	Project* project, const uint8_t& part):
	Personal(id, name, workTime, salary, position) {
	this->project = project;
	this->part = part;
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
	return (float)part/100 * project->get_budget();
}
void Engineer::SetPartInProject(const uint8_t& part) {
	this->part = part;
}

Tester::Tester(const int& id, const std::string& name,
	const int& workTime, const int& salary, const Positions& position,
	Project* project, const uint8_t& part, const uint8_t& found_errors) :
	Engineer(id, name, workTime, salary, position, project,part) {
	this->found_errors = found_errors;
}
int Tester::calc_pro_additions(int bonus) {
	return project->get_budget() * (float)(part / 100) +
		   (found_errors / 20) * salary + calc_bonus_salary(bonus);
}
Programmer::Programmer(const int& id, const std::string& name,
	const int& workTime, const int& salary, const Positions& position,
	Project* project, const uint8_t& part) :
	Engineer(id, name, workTime, salary, position, project, part) {}
void Programmer::SetPrematurelyWrittenCode(int hours) {
	bonus = (hours / 10) * 2;
}
int Programmer::calc_pro_additions(int bonus) {
	return calc_bonus_salary(bonus);
}


TeamLeader::TeamLeader(const int& id, const std::string& name,
	const int& workTime, const int& salary, const Positions& position,
	Project* project, const uint8_t& part) :
	Programmer(id, name, workTime, salary, position, project, part) {}
int TeamLeader::calc_Heads() {
	return project->get_num_of_employees() * 1000;
}
int TeamLeader::calc_salary() {
	return salary * work_time + calc_pro_additions() +
		   project->get_budget() * (float)(part / 100) +
		   calc_Heads();
}