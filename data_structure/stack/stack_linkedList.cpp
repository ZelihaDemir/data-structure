#include <iostream>
using namespace std;
// A class represent a stack
class StackNode{
    public:
    int data;
    StackNode *next;
};
StackNode *newNode(int data){
    StackNode *stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}
int isEmpty(StackNode* root) { 
    return !root; 
}  
void push(StackNode **root,int data){
    StackNode *stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    cout << data <<"  is pushed to stack \n";
}
int pop(StackNode** root) { 
    if (isEmpty(*root)) 
        return -999; // INT_MIN; 
    StackNode* temp = *root; 
    *root = (*root)->next; 
    int popped = temp->data; 
    free(temp);
    return popped; 
}
int peek(StackNode* root) { 
    if (isEmpty(root)) 
        return -999; // INT_MIN; 
    return root->data; 
}
void print(StackNode** root) {
    while(!isEmpty(*root)) { 
        // print top element in stack 
        cout << peek(*root) <<" "; 
        // remove top element in stack 
        pop(root); 
    }
} 
  
// Driver code 
int main() { 
    StackNode* root = NULL; 
    push(&root, 36); 
    push(&root, 29); 
    push(&root, 69);
    push(&root, 11); 
    cout << "Top element is " << peek(root) << endl; 
    cout << pop(&root) << " is popped from stack\n"; 
    cout <<"Elements present in stack : ";
    print(&root); 
    cout<<endl;
    return 0; 
} 