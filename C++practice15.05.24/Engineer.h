#pragma once
#include<iostream>
#include"Personal.h"

class Engineer : public Personal, public Project_Budget {
protected:
	Project* project;
	
public:
	Engineer(const int& id, const std::string& name,
		const int& workTime, const int& salary,const Positions& position,
		Project* project);
	
	void SetProject(Project* project);
	void SetPartInProject(const uint8_t& part);
	int calc_salary() override;
	int calc_budget_part() override;
};

class Tester :public Engineer {
 public:
	 Tester(const int& id, const std::string& name,
		 const int& workTime, const int& salary, const Positions& position,
		 Project* project, const uint8_t& found_errors);
	 int calc_pro_additions(int bonus = 0) override;
};

class Programmer : public Engineer {
public:
	Programmer(const int& id, const std::string& name,
		const int& workTime, const int& salary, const Positions& position,
		Project* project);
	void SetPrematurelyWrittenCode(int hours);
	int calc_pro_additions(int bonus = 0) override;
};

class TeamLeader :public Programmer, public Heading {
 public:
	TeamLeader(const int& id, const std::string& name,
		const int& workTime, const int& salary, const Positions& position,
		Project* project);
	int calc_Heads() override;
	int calc_salary() override;
};