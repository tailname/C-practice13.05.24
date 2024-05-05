  // Copyright 2024 Matvey Pavlov

#include <iostream>
#include"Factory.h"
#include <Windows.h>
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Factory_Staff fs;
    fs.make_staff();

    std::vector<Employee*> empls = fs.GetStaff();
    for (Employee* emp : empls) {
        emp->print_info();
    }
    std::cout << "Hello World!\n";
}
