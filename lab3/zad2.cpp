#include <algorithm>
#include <iostream>

class Queue {
    int size;
    int *p;
    int frontIndex;
    int lastIndex;
    int counter;

    public:
    Queue(int maxSize);
    int& enqueue(int value);
    int dequeue();
    const int& front() const;
    bool isEmpty() const;
    bool isFull() const;
    void display();

    friend void mergeQueues(const Queue &q1, const Queue &q2, Queue &result);
    ~Queue();
};
Queue:: Queue (int maxSize) {
    size = maxSize;
    p = new int[maxSize];
    if (!p) {
        std::cout << "Memory allocation error!\n";
        exit(1);
    }
    frontIndex = 0;
    lastIndex = -1;
    counter = 0;
}

int& Queue::enqueue(int value) {

    if (isFull()) {
        std::cout << "Queue is full!\n";
        exit(1);
    }
    lastIndex = (lastIndex + 1) % size;
    p[lastIndex] = value;
    counter++;
    return p[lastIndex];
}

int Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue is empty!\n";
        return -1;
    }
    int value = p[frontIndex];
    frontIndex = (frontIndex + 1) % size;
    counter--;
    return value;
}

const int& Queue::front() const{
    if (isEmpty()) {
        std::cout << "Queue is empty!\n";
        return -1;
    }
    return p[frontIndex];
}
bool Queue::isEmpty() const{
    return (counter == 0);
}
bool Queue::isFull() const{
    return (counter == size);
}

void Queue::display() {
    int i = frontIndex;
    for (int c = 0; c < counter; c++) {
        std:: cout << p[i] << " ";
        i = (i + 1) % size;
    }
    std:: cout << std::endl;
}

void mergeQueues(const Queue& q1, const Queue& q2, Queue& result) {
    Queue temp1 = q1;
    Queue temp2 = q2;

    while (!temp1.isEmpty() || !temp2.isEmpty()) {
        if (!temp1.isEmpty()) {
            result.enqueue(temp1.dequeue());
        }
        if (!temp2.isEmpty()) {
            result.enqueue(temp2.dequeue());
        }
    }
}
Queue:: ~Queue() {
    delete [] p;
}

int main() {
    Queue q1(3);
    Queue q2(3);
    Queue result(6);

    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);

    std::cout << "Queue 1: ";
    q1.display();

    int removed = q1.dequeue();
    std::cout << "Removed element from q1: " << removed << '\n';

    q2.enqueue(4);
    q2.enqueue(5);
    q2.enqueue(6);

    std::cout << "Queue 2: ";
    q2.display();

    int removed2 = q2.dequeue();
    std::cout << "Removed element from q2: " << removed2 << '\n';

    mergeQueues(q1, q2, result);

    std::cout << "Merged queues:\n";
    while (!result.isEmpty()) {
        std::cout << result.dequeue() << " ";
    }

    std::cout << std::endl;
    return 0;
}