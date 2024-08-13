
#include <iostream>
using namespace std;

/* Class containing left and right child of current node */
class Node {
    public:
        int data;
        Node *left, *right;
        Node(int item) {
            data = item;
            left = right = NULL;
        }
};

/* Function to print nodes at current level */
int height(Node* node) {
    if (node == NULL)
        return 0;
    else {
        /* Compute the height of each subtree */
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        /* Use the larger one */
        if (leftHeight > rightHeight) {
            return (leftHeight + 1);
        } else {
            return (rightHeight + 1);
        }
    }
}

/* Function to print nodes at current level */
void printCurrentLevel(Node* root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

/* Function to print level order traversal */
void printReverseLevelOrder(Node* root) {
    int h = height(root);
    int i;
    for (i = h; i >= 1; i--)
        printCurrentLevel(root, i);
}

/* Main driver method */
int main() {    
    Node* root = new Node(30);
    root->left = new Node(9);
    root->right = new Node(45);
    root->left->left = new Node(5);
    root->left->right = new Node(20);
    root->left->right->left = new Node(13);
    root->left->right->right = new Node(23);
    cout << "Reverse Level order traversal of BT is ";
    printReverseLevelOrder(root);
return 0;
}
