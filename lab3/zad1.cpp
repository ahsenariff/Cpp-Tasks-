
#include <iostream>
#include <vector>

class Stack {
    std:: vector<char> elements;

    public:
    Stack() {};
    void push(const char &ch);
    void loadstack(int upper);
    void printstack(const Stack &stack);
    ~Stack() {};
};
void Stack::push(const char &ch) {
    elements.push_back(ch);
}
void Stack::loadstack(int upper) {
    char start;
    char end;
    if (upper == 1) {
        start = 'A';
        end = 'Z';
    }
    else {
        start = 'a';
        end = 'z';
    }
    for (char ch = start; ch <= end; ++ch) {
        push(ch);
    }
}
void Stack::printstack(const Stack &stack) {
    for (int i = elements.size() - 1; i >= 0; --i) {
        std::cout << elements[i];
    }
}
int main() {
    Stack stack;
    stack.loadstack(1);
    stack.printstack(Stack());
}
