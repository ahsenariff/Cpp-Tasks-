#include <iostream>
#include <limits>
#include <vector>
#include <string>

class Employee {
private:
    int number;
    std::string name;
    int work_experience;
    std:: string position;
    std:: vector<double> salary;
public:
    Employee();
    Employee(std:: string position);

    void setNumber();
    void setName();
    void set_work_experience();
    void set_position();
    void set_salary();

    int getNumber();
    std::string getName();
    int getWorkExperience();
    std::string getPosition();
    std::vector<double> getSalary();

    double average_salary();
    double min_salary();
    void displayEmployee();

    ~Employee();
};
Employee::Employee() {
    number = 0;
    work_experience = 0;
}
Employee:: Employee(std::string position) {
    std::cout << "Please enter the position: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, this->position);
}

void Employee::setNumber() {
    std::cout << "Please enter the number: ";
    std::cin >> number;
}
void Employee::setName() {
    std::cout << "Please enter the name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
}
void Employee::set_work_experience() {
    std::cout << "Please enter the work experience: ";
    std::cin >> work_experience;
}
void Employee::set_position() {
    std::cout << "Please enter the position: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, position);
}
void Employee::set_salary() {
    int n;
    std::cout << "Enter the number of salaries: ";
    std::cin >> n;
    if (n <= 0 ) {
        std::cout << "No salaries to enter\n";
        salary.clear();
        return;
    }
    salary.clear();
    for (int i = 0; i < n; i++) {
        double s;
        std::cout << "Please enter the salary: " << (i+1) << ": ";
        std::cin >> s;
        salary.push_back(s);
    }

}

int Employee::getNumber() {
    return number;
}
std::string Employee::getName() {
    return name;
}
int Employee::getWorkExperience() {
    return work_experience;
}
std::string Employee::getPosition() {
    return position;
}
std::vector<double> Employee::getSalary() {
    return salary;
}
double Employee::average_salary() {
    if (salary.size() == 0) {
        return 0;
    }
    double sum = 0.0;
    for (int i = 0; i < salary.size(); i++) {
        sum += salary[i];
    }
    return sum / salary.size();
}
double Employee::min_salary() {
    if (salary.size() == 0) {
        return 0.0;
    }
    double min = salary[0];
    for (int i = 0; i < salary.size(); i++) {
        if (salary[i] < min) {
            min = salary[i];
        }
    }
    return min;
}
void Employee::displayEmployee() {
    std:: cout << "Social number: " << number << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Work experience: " << work_experience << std::endl;
    std::cout << "Position: " << position << std::endl;
    std::cout << "Salaries: ";
    if (salary.size() == 0) {
        std:: cout << "No salary" << std::endl;
    }
    else {
        for (int i = 0; i < salary.size(); i++) {
            std::cout << salary[i] << " ";
            if (i+1 < salary.size()) std::cout << ", ";
        }
        std::cout << "\n";
    }
    std::cout << "Average salary: " << average_salary() << std::endl;
    std::cout << "Minimum salary: " << min_salary() << std::endl;
}
Employee::~Employee() {
    std::cout << "Destructor of Employee! " << std::endl;
}


int main() {
    std:: cout << "Please enter the number of employees: ";
    int n;
    std::cin >> n;

    std::vector<Employee> employees;
    employees.reserve(n);
    for (int i = 0; i < n; i++) {
        Employee employee1;
        employee1.setNumber();
        employee1.setName();
        employee1.set_work_experience();
        employee1.set_position();
        employee1.set_salary();

        employee1.average_salary();
        employee1.min_salary();

        employees.push_back(std::move(employee1));
    }

    for (int i = 0; i < employees.size(); i++) {
        std::cout << "\n ---Employee info--\n";
        employees[i].displayEmployee();
    }

    return 0;
}