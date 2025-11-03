#include <cstring>
#include <iostream>

class Student {
private:
    char* name;
    int fNumber;
    double grade;

public:
    Student(const char* name, int fNumber, double grade);
    Student(const Student& other);
    Student() {
        name = nullptr;
        fNumber = 0;
        grade = 0.0;
    }
    Student& operator=(const Student& other) {
        if (this != &other) {
            delete[] name;

            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            fNumber = other.fNumber;
            grade = other.grade;
        }
        return *this;
    }
    ~Student();

    double getGrade() const;
    void setGrade(double g);
    void display() const;
};
Student:: Student(const char* name, int fNumber, double grade) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->fNumber = fNumber;
    this->grade = grade;
}
Student::Student(const Student &other) {
    name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    fNumber = other.fNumber;
    grade = other.grade;
}
double Student::getGrade() const{
    return grade;
}
void Student::setGrade(double g) {
    grade = g;
}
Student::~Student() {
    delete[] name;
}
void Student::display() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Number: " << fNumber << std::endl;
    std::cout << "Grade: " << grade << std::endl;
}

class StudentList {
    int capacity;
    int counter;
    Student *students;

public:
    StudentList(int initialCapacity);
    void add(const Student &s);
    Student& getBest();
    const Student& getByIndex(int i) const;
    void swapStudents(int i, int j);

};
StudentList :: StudentList(int initialCapacity) {
    capacity = initialCapacity;
    students = new Student[capacity];
    if (!students) {
        std::cout << "Memory allocation error!\n";
        exit(1);
    }
    counter = 0;
}

void StudentList:: add(const Student &s) {
    if (counter >= capacity) {
        std::cout << "Student list is full!\n";
        return;
    }
    students[counter++] = s;
}

Student& StudentList::getBest() {
    int max = 0;
    for (int i = 1; i < counter; ++i) {
        if (students[i].getGrade() > students[max].getGrade()) {
            max = i;
        }
    }
    return students[max];
}

const Student& StudentList:: getByIndex(int i) const{
    return students[i];
}

void StudentList:: swapStudents(int i, int j) {
    Student& a = students[i];
    Student& b = students[j];
    Student temp = a;
    a = b;
    b = temp;
}
int main() {
    StudentList list(5);

    list.add(Student("Ivan", 12345, 5.5));
    list.add(Student("Maria", 23456, 4.8));
    list.add(Student("Georgi", 34567, 4.0));
    list.add(Student("Elena", 45678, 4.9));
    list.add(Student("Petar", 56789, 4.7));

    Student& best = list.getBest();
    std::cout << "The student with best grade: "<< std::endl;
    best.display();
    std:: cout << "\n";

    if (best.getGrade() <= 6.0 ) {
        double newGrade = best.getGrade() + 0.5;
        if (newGrade > 6.0) {
            std:: cout << "The grade can not be bigger than 6.0 after increasing" << std::endl;
        }
        else {
            best.setGrade(newGrade);
            std::cout << "The student with best grade after increasing: " << best.getGrade() << std::endl;
        }
    }
    std:: cout << "\n";
    std:: cout << "---All students---" << std::endl;
    for (int i = 0; i < 5; ++i) {
        list.getByIndex(i).display();
    }

    list.swapStudents(0, 1);
    std:: cout << "---All students after swaping---" << std::endl;
    for (int i = 0; i < 5; ++i) {
        list.getByIndex(i).display();
    }
    return 0;
}