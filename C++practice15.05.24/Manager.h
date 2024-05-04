#pragma once
#include"Employee.h"
#include"Interfaces.h"
#include<vector>

class ProjectManager:public Heading,public Employee,public Project_Budget {
 protected:
	 std::vector<Project*> projects;
	 uint8_t part;
 public:
	 ProjectManager(const int& id, const std::string& name,
		 const int& workTime, const Positions& position,
		 Project* project, const uint8_t& part = 0);
	 int calc_Heads() override;
	 int calc_salary() override;
};

class SeniorManager :public ProjectManager {
public:
	SeniorManager(const int& id, const std::string& name,
		const int& workTime, const Positions& position,
		std::vector<Project*> projects);
	int calc_Heads() override;
	int calc_salary() override;
};