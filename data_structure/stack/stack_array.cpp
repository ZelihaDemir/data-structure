#include <iostream>
using namespace std;

class Stack {
int top; // To have the top of the Stack
public:
int array[MAX]; // Maximum size of Stack
Stack() {
top = -1;
 }
bool push(int e);
int pop();
int peek();
bool isEmpty();
void print();
};
// Main driver method to test all functions
int main() 
{
class Stack s;
s.push(36);
s.push(29);
s.push(69);
s.push(11);
cout << s.pop() << " is popped from stack\n";
cout << "Top element is : " << s.peek() << endl;
cout <<"The stack has following elements in it: ";
s.print();
return 0;
}
