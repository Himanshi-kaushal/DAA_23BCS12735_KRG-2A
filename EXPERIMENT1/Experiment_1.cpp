#include <iostream>
using namespace std;

const int MAX_SIZE = 5;   
template <typename T>
class Stack {
private:
    T arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(T value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << "Pushed: " << value << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }

    T peek() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return T(); 
        }
        return arr[top];
    }
};

int main() {
    Stack<int> intStack;

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    cout << "Top element: " << intStack.peek() << endl;

    intStack.pop();
    cout << "Top after pop: " << intStack.peek() << endl;

    cout << "Is stack empty? " << (intStack.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (intStack.isFull() ? "Yes" : "No") << endl;

    Stack<string> strStack;
    strStack.push("Hello");
    strStack.push("World");

    cout << "Top of string stack: " << strStack.peek() << endl;

    return 0;
}
