#include<iostream>
using namespace std;

class MyStack {
    int *arr;
    int top;
    int size;

public:
    MyStack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int val) {
        if (top == size - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }

        top++;
        arr[top] = val;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }

        top--;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is Empty" << endl;
            return -1;
        }

        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {

    MyStack st(5);

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top Element: " << st.peek() << endl;

    st.pop();

    cout << "Top Element after pop: " << st.peek() << endl;

    return 0;
}