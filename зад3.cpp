#include <iostream>
#include <thread>
#include <chrono>

class Line {
private:
    int len;
public:
    Line(int len);
    ~Line();
};

Line::Line(int length) {
    len = length;
    std::cout << "Drawing a line with length: " << len << '\n';

    for (int i = 0;  i < len; i++) {
        std:: cout<< "*";
        std:: cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

    }
    std::cout<< std::endl;
}
Line::~Line() {
    std::cout << "Deleting the line with length " << len << "\n";
    std::cout<< "\r";

    for (int i = 0; i < len; ++i) {
        std:: cout<< "*";

    }
    std::cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    for (int i = len -1; i >= 0; --i) {
        std:: cout<< "\r";
        for (int j = 0; j < i; ++j) {
            std:: cout<< "*";
        }
        for (int j = i; j < len; ++j) {
            std:: cout<< " ";
        }
        std:: cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    }

    std::cout <<"\r";
    for (int i = 0; i < len; ++i) {
        std:: cout<< " ";
    }
    std::cout<< "\r";
    std::cout.flush();
    std::cout << "The line is deleted" << std::endl;
}
int main() {
    int l;
    std:: cout << "Enter length of line: ";
    std::cin >> l;
    while (l < 0) {
        std::cout << "The length must be bigger than 0\n";
        std::cout << "Enter length of line: ";
        std::cin >> l;
    }
    {
        Line line(l);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}