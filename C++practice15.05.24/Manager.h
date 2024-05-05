#pragma once
#include"Employee.h"
#include"Interfaces.h"
#include<vector>

class ProjectManager:public Heading,public Employee,public Project_Budget {
 private:
	int calc_pro_additions(int bonus =0 ) override;
 protected:
	 std::vector<Project*> projects;
	 std::vector<int> time_in_proj;
	 int salary;
 public:
	 ProjectManager(const int& id, const std::string& name,
		 const int& workTime, const int& salary,const Positions& position,
		 Project* project);
	 int calc_Heads() override;
	 int calc_salary() override;
	 int calc_budget_part() override;

};

class SeniorManager :public ProjectManager {
public:
	SeniorManager(const int& id, const std::string& name,
		std::vector<int> workTime,const int& salary, const Positions& position,
		std::vector<Project*> projects);
	int calc_Heads() override;
	int calc_salary() override;
	
};