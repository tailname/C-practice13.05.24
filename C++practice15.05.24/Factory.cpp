#include"Factory.h"
void Factory_Staff::MakeProjects() {
	std::ifstream ifs("projects_info.txt");
	int budget,id,numb_of_empl;
	while (ifs >>id>> budget>> numb_of_empl) {
		Project* proj = new Project(id, budget, numb_of_empl);
		projects.push_back(proj);
	}
}
Positions Factory_Staff::SetPosition(std::string pos) {
    if (pos == "cleaner") {
        return Positions::cleaner;
    }
    if (pos == "driver") {
        return Positions::driver;
    }
    if (pos == "programmer") {
		return Positions::programmer;
    }
    if (pos == "tester") {
        return Positions::tester;
    }
    if (pos == "team_leader") {
        return Positions::team_leader;
    }
    if (pos == "project_manager") {
        return Positions::project_manager;
    }
	if (pos == "senior_manager") {
		return Positions::senior_manager;
	}
}
void Factory_Staff::make_staff() {
	std::ifstream ifs("staff_info.txt");
	MakeProjects();
	std::string first_name, second_name, third_name, position;
	int id_person, salary, worktime, id_proj;
	while(!ifs.eof()){
		ifs >> id_person;
		ifs >> first_name >> second_name >> third_name >>
			   salary >> worktime >> position>>id_proj;
		}
		switch (SetPosition(position)){
			case Positions::cleaner:
				Cleaner* cleaner = new Cleaner(id_person, first_name + " " +
				                               second_name + " " + third_name, 
											   worktime, salary, SetPosition(position));
				empl.push_back(cleaner);
				break;
			case Positions::driver:
				Driver* driver = new Driver(id_person, first_name + " " +
				                               second_name + " " + third_name, 
											   worktime, salary, SetPosition(position));
				empl.push_back(driver);
				break;
			case Positions::programmer:
				Programmer* programmer = new Programmer(id_person, first_name + " " +
				                               second_name + " " + third_name, 
											   worktime, salary, SetPosition(position),
											   &projects[id_proj], 0 );
			    projects[id_proj]->SetTimeInProject(
					                                projects[id_proj]->GetTimeInProject() +
													worktime);
				empl.push_back(programmer);
				break;
				
			
		}

	}

}