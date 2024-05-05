  // Copyright 2024 Matvey Pavlov
#include"Factory.h"
Factory_Staff::~Factory_Staff() {
    for (int i = 0; i < projects.size(); ++i) {
        delete projects[i];
    }
    for (int i = 0; i < empl.size(); ++i) {
        delete empl[i];
    }
}
void Factory_Staff::MakeProjects() {
    std::ifstream ifs("projects_info.txt");
    int budget, id, numb_of_empl;
    projects.push_back(new Project(0, 0, 0));
    while (ifs >> id >> budget >> numb_of_empl) {
        Project* proj = new Project(id, budget, numb_of_empl);
        proj->SetTimeInProject(0);
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
    std::string first_name,
                second_name, third_name,
                position, other_information;
    int id_person, salary, worktime, id_proj;
    while (ifs >> id_person) {
        std::vector<int> work_times;
        ifs >> first_name >> second_name >> third_name >>
               salary;
        ifs.get();
        std::getline(ifs, other_information);
        ifs >> position;
        std::stringstream ss(other_information);
        while (ss >> worktime) {
            work_times.push_back(worktime);
        }
        switch (SetPosition(position)) {
        case Positions::cleaner:
        {
            Cleaner* cleaner = new Cleaner(id_person, first_name + " " +
                second_name + " " + third_name,
                worktime, salary, SetPosition(position));
            empl.push_back(cleaner);
            break;
        }
        case Positions::driver:
        {
            int night_hours;
            ifs >> night_hours;
            Driver* driver = new Driver(id_person, first_name + " " +
                second_name + " " + third_name,
                worktime, salary, SetPosition(position));
            driver->SetNightHours(night_hours);
            empl.push_back(driver);
            break;
        }
        case Positions::programmer:
        {
            int PrematurelyWrittenCode;
            ifs >> id_proj;
            ifs >> PrematurelyWrittenCode;
            Programmer* programmer =
            new Programmer(id_person, first_name + " " +
                second_name + " " + third_name,
                worktime, salary, SetPosition(position),
                projects[id_proj]);
            projects[id_proj]->SetTimeInProject(
                projects[id_proj]->GetTimeInProject() +
                worktime);
            programmer->SetPrematurelyWrittenCode(PrematurelyWrittenCode);
            empl.push_back(programmer);
            break;
        }
        case Positions::tester:
        {
            int found_errors;
            ifs >> id_proj;
            ifs >> found_errors;
            Tester* tester = new Tester(id_person, first_name + " " +
                second_name + " " + third_name,
                worktime, salary, SetPosition(position),
                projects[id_proj], found_errors);
            projects[id_proj]->SetTimeInProject(
                projects[id_proj]->GetTimeInProject() +
                worktime);
            empl.push_back(tester);
            break;
        }
        case Positions::team_leader:
        {
            ifs >> id_proj;
            TeamLeader* team_leader =
            new TeamLeader(id_person, first_name + " " +
                second_name + " " + third_name,
                worktime, salary, SetPosition(position),
                projects[id_proj]);
            projects[id_proj]->SetTimeInProject(
                projects[id_proj]->GetTimeInProject() +
                worktime);
            empl.push_back(team_leader);
            break;
        }
        case Positions::project_manager:
        {
            ifs >> id_proj;
            ProjectManager* project_manager =
            new ProjectManager(id_person,
                first_name + " " +
                second_name + " " + third_name,
                worktime, salary, SetPosition(position), projects[id_proj]);
            projects[id_proj]->SetTimeInProject(
                               projects[id_proj]->GetTimeInProject() +
                               worktime);
            empl.push_back(project_manager);
            break;
        }
        case Positions::senior_manager:
        {
            std::vector<Project*> projects_for_senior_manager;
            int i = 0;
            ifs.get();
            std::getline(ifs, other_information);
            std::stringstream ss = std::stringstream(other_information);
            while (ss >> id_proj) {
                projects_for_senior_manager.push_back(projects[id_proj]);
                projects[id_proj]->SetTimeInProject(
                                   projects[id_proj]->GetTimeInProject() +
                                   work_times[i++]);
            }
            SeniorManager* senior_manager =
            new SeniorManager(id_person,
                              first_name + " " +
                              second_name + " " + third_name,
                              work_times, salary,
                              SetPosition(position),
                              projects_for_senior_manager);
            empl.push_back(senior_manager);
            break;
        }
        }
    }
    ifs.close();
}

std::vector<Employee*> Factory_Staff::GetStaff() {
    return empl;
}
