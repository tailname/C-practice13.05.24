#include"Manager.h"

ProjectManager::ProjectManager(const int& id, const std::string& name,
	const int& workTime, const int& salary,const Positions& position,
	Project* project): Employee(id,name,workTime,position) {
	this->projects.push_back(project);
	this->salary= salary;
}
int ProjectManager::calc_pro_additions(int bonus){
	return 0;
}
int ProjectManager::calc_Heads() {
	return projects[0]->get_num_of_employees() * salary;
}

int ProjectManager::calc_salary() {
	return projects[0]->get_budget() * (static_cast<float>(work_time)/ projects[0]->GetTimeInProject()) + calc_Heads();
}
int ProjectManager::calc_budget_part() {
	return projects[0]->get_budget() * (static_cast<float>(work_time)/ projects[0]->GetTimeInProject());
}


SeniorManager::SeniorManager(const int& id, const std::string& name,
	std::vector<int> workTime, const int& salary, const Positions& position,
	std::vector<Project*> projects) : ProjectManager(id,name,workTime[0],salary,position,projects[0]) {
	this->projects = projects;
	this->time_in_proj = workTime;
}

int SeniorManager::calc_Heads() {
	int salary_Heads = 0;
	for (int i = 0; i < projects.size(); ++i) {
		salary_Heads += projects[i]->get_num_of_employees() * salary;
	}
	return salary_Heads;
}
int SeniorManager::calc_salary() {
	int salary = 0;
	for (int i = 0; i < projects.size(); ++i) {
		salary += projects[i]->get_budget() *
		          (static_cast<float>(time_in_proj[i]) /
				  projects[i]->GetTimeInProject());
	}
	return salary + calc_Heads();
}