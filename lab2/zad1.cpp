#include <iostream>
#include <ostream>

class Rectangle {
private:
    double a, b;
    public:
    Rectangle();
    double face();
    double face(double *);
    void show(const char *);
    ~Rectangle();
};
Rectangle::Rectangle() {
    do {
        std:: cout << "\nEnter two values for the sides of rectangle:\n";
        std:: cin >> a >> b;
    }while (!(a >= 0 && b >= 0));
}
double Rectangle::face() {
    double p,s;
    p = a + b;
    s = a * b;
    return s;
}
double Rectangle::face(double *p) {
    double pp = a + b;
    *p = pp;
    double s = a * b;
    return s;
}
void Rectangle::show(const char *name) {
    std:: cout << "Sides of the rectangle " << name << ":\n";
    std::cout << "a = "<< a << " " << "b = " << b << "\n";
}
Rectangle::~Rectangle() {
    std:: cout << "\nDeallocating the rectangle\n";
}

int main() {
    Rectangle rect1;
    double p,s;
    rect1.show("rect1");
    std:: cout << "\nThe face of rectangle1 is s = " << rect1.face();

    Rectangle rect2;
    rect2.show("rect2");
    s = rect2.face(&p);
    std:: cout << "\nThe face of rectangle2 is s = " << s << ", and the perimeter is p = "<< p;
}


