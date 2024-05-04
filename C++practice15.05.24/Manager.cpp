#include"Manager.h"

ProjectManager::ProjectManager(const int& id, const std::string& name,
	const int& workTime, const Positions& position,
	Project* project, const uint8_t& part = 0):Employee(id,name,workTime,position) {
	this->projects.push_back(project);
	this->part = part;
}

int ProjectManager::calc_Heads() {
	return projects[0]->get_num_of_employees() * 10000;
}

int ProjectManager::calc_salary() {
	return projects[0]->get_budget() * (float)(part / 100) + calc_Heads();
}

SeniorManager::SeniorManager(const int& id, const std::string& name,
	const int& workTime, const Positions& position,
	std::vector<Project*> projects) : ProjectManager(id,name,workTime,position,projects[0], 1) {
	this->projects = projects;
}

int SeniorManager::calc_Heads() {
	int salary_Heads = 0;
	for (int i = 0; i < projects.size(); ++i) {
		salary_Heads += projects[i]->get_num_of_employees() * 1000;
	}
	return salary_Heads;
}
int SeniorManager::calc_salary() {
	int salary = 0;
	for (int i = 0; i < projects.size(); ++i) {
		salary += projects[i]->get_budget()*0.01;
	}
	return salary + calc_Heads();
}