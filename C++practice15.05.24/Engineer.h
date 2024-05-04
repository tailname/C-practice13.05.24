#pragma once
#include<iostream>
#include"Personal.h"

class Engineer : public Personal, public Project_Budget {
protected:
	Project* project;
	uint8_t part;
	
public:
	Engineer(const int& id, const std::string& name,
		const int& workTime, const int& salary,const Positions& position,
		Project* project, const uint8_t& part =0);
	
	void SetProject(Project* project);
	void SetPartInProject(const uint8_t& part);
	int calc_salary() override;
	int calc_budget_part() override;
};

class Tester :public Engineer {
 private:
	 uint8_t found_errors = 0;
 public:
	 Tester(const int& id, const std::string& name,
		 const int& workTime, const int& salary, const Positions& position,
		 Project* project, const uint8_t& part = 0,const uint8_t& found_errors);
	 int calc_pro_additions(int bonus = 0) override;
};

class Programmer : public Engineer {
public:
	Programmer(const int& id, const std::string& name,
		const int& workTime, const int& salary, const Positions& position,
		Project* project, const uint8_t& part =0);
	void SetPrematurelyWrittenCode(int hours);
	int calc_pro_additions(int bonus = 0) override;
};

class TeamLeader :public Programmer, public Heading {
	TeamLeader(const int& id, const std::string& name,
		const int& workTime, const int& salary, const Positions& position,
		Project* project, const uint8_t& part = 0);
	int calc_Heads() override;
	int calc_salary() override;
};