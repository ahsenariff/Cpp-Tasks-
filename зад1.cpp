#include <iostream>
#include <iomanip>

class Time {
    private:
        int hours;
        int minutes;
        int seconds;
    public:
        void setTime();
        void printTime();
   
};

void Time::setTime() {
    std::cout << "Enter hours(0-23): ";
    std::cin >> hours;
    while (hours < 0 || hours > 24) {
        std::cout << "Enter hours(0-23) again: ";
        std::cin >> hours;
    }

    std::cout << "Enter minutes(0-59): ";
    std::cin >> minutes;
    while (minutes < 0 || minutes > 59) {
        std::cout << "Enter minutes(0-59) again: ";
        std::cin >> minutes;
    }
    std::cout << "Enter seconds(0-59): ";
    std::cin >> seconds;
    while (seconds < 0 || seconds > 59) {
        std::cout << "Enter seconds(0-59) again: ";
        std::cin >> seconds;
    }
}

void Time::printTime() {

    std::cout << "Time: "
    <<  std::setfill('0') << std:: setw(2) << hours << ':'
    <<  std::setfill('0') << std:: setw(2) << minutes << ':'
    <<  std::setfill('0') << std:: setw(2) << seconds << std:: endl;

    if (hours < 12) {
        std::cout << "Time: "
        <<  std::setfill('0') << std:: setw(2) << hours << ':'
        <<  std::setfill('0') << std:: setw(2) << minutes << ':'
        <<  std::setfill('0') << std:: setw(2) << seconds
        << " AM" << std:: endl;
    } else {
        std::cout << "Time: "
        <<  std::setfill('0') << std:: setw(2) << hours << ':'
        <<  std::setfill('0') << std:: setw(2) << minutes << ':'
        <<  std::setfill('0') << std:: setw(2) << seconds << " PM"
        << std:: endl;
    }
}

int main() {
    Time t1;
    t1.setTime();
    t1.printTime();
    return 0;
}