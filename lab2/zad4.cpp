#include <iostream>
class pr2;
class pr1 {
    int printing;

    public:
    pr1() {
        printing = 0;
    }
    void set_print(int status) {
        printing = status;
    }
    friend bool inuse(pr1 printer1, pr2 printer2);
};

class pr2 {
    int printing;

public:
    pr2() {
        printing = 0;
    }
    void set_print(int status) {
        printing = status;
    }
    friend bool inuse(pr1 printer1, pr2 printer2);
};

bool inuse(pr1 printer1, pr2 printer2) {
    return printer1.printing == 1 || printer2.printing == 1;
}

int main() {
    pr1 printer1;
    pr2 printer2;
    printer1.set_print(0);
    printer2.set_print(0);
    if (inuse(printer1, printer2)) {
        std::cout << "The printers are in use" << std::endl;
    }
    else {
        std::cout << "The printers are not in use" << std::endl;
    }

}