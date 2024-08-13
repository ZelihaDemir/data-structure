#include <iostream>
using namespace std;

/* Link list node */
class Node {
public:
    int data;
    Node* next;
};

/* Function to insert the element at the front of the list */
void push(Node** head_ref, int new_data) {
    /* Step 1: Allocate the node*/
    Node* new_node = new Node();
    /* Step 2: Assign the data*/
    new_node->data = new_data;
    /* Step 3: Make next of new node as head */
    new_node->next = (*head_ref);
    /* Step 4: Move the head to point to new node */
    (*head_ref) = new_node;
}
/* Function to print the data value of each node in the list */
void printList(Node* head) {
    while (head) {
        if (head->next == NULL)
            cout << "["<< head->data <<"]";
        else
            cout << "["<< head->data << "]-->";
        head = head->next;
    }
    cout << endl << endl;
}

/*Function for insertion at the middle of the list*/
void insertAfter(Node* prev_node, int new_data)
{
    /* step 1: check if the given node is null */
    if(prev_node == NULL)
    {
        cout << "The given previous node cannot be NULL ";
        return;
    }
    /* step 2 : allocate the node */
    Node *new_node = new Node();

    /* step 3 : assign the data */
    new_node->data = new_data;

    /* step 4 :  Make next of new node as next of prev_node */
    new_node->next = prev_node->next;

    /* Step 5: Make next of prev_node as new_node */
    prev_node->next = new_node;
}
/* Function to insert a new node at the end of the list */
void append(Node **head_ref,int new_data)
{
    /* Step 1 : Allocate a new node */
    Node *new_node = new Node();

    /* Used in Step 5 */
    Node* last = *head_ref;

    /* Step 2 : assign the data */
    new_node->data = new_data;

    /* Step 3 : Set the next of the newly created node to null. */
    new_node->next = NULL;

    /* Step 4: If list is empty, then set the newly created node as head */
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    
    /* Step 5: Else traverse till the last node */
    while(last->next != NULL)
    {
        last = last->next;
    }
    /* Set-Change the next of the last node */
    last->next = new_node;
    return;
}
/* Function to search an element/node in the list */
bool search(Node* head,int value)
{
    /* Step 1 & 2: Create the node and set it to head */
    Node *current = head;
    /* Step 3: Loop through each element of the list
    * and compare it with the value to be searched
    * Return true if the element found
    */ 
    while(current !=NULL)
    {
        if(current->data == value)
        {
            return true;
        }
        
    current = current->next;
    }
    /* Step 4: Return false if element not in the lest */ 
    return false;
}
/* Function to delete a node at the front of the list */
void deleteFirstNode(Node** head_ref)
{
    /* check if the given list is null */
    if (*head_ref == NULL)
    {
        cout << "list is null. ";
        return;
    }
    /* Create the node and set it to head */
    Node *temp = *head_ref;

    /* Remove the first node from the linked list */
    *head_ref = (*head_ref)->next;

    /* Free the memory of the first node */
    delete temp;
}
/* Function to delete the node from the middle of the list */
void deleteMiddleNode(Node **head_ref,int key)
{
    /* check if the list is empty */
if (*head_ref == NULL)
    return;

/* find the node with given key */
Node *temp = *head_ref;
Node *prev = NULL;
while (temp != NULL && temp->data != key)
{
    prev = temp;
    temp = temp->next;
}
/* if the key is not present in the list */
if(temp == NULL)
return;
/* if the node to be deleted is the head is the head node */
if (temp == *head_ref)
{
    *head_ref =temp->next;
}
/* remove the node from the middle */
else
prev->next = temp->next;

/* free the memory of the deleted node */
delete temp;
}
/* Function to delete the node from the end of the list */
void deleteEnd(Node** head_ref)
 {
    // Check if the list is empty
    if (*head_ref == NULL)
        return;

    // If there is only one node in the list
    if ((*head_ref)->next == NULL) {
        delete *head_ref;
        *head_ref = NULL;
        return;
    }

    // Find the second-to-last node
    Node* secondLast = *head_ref;
    while (secondLast->next->next != NULL) {
        secondLast = secondLast->next;
    }

    // Delete the last node
    delete secondLast->next;
    secondLast->next = NULL;
}
/* Driver code*/
int main() {
    /* Start with the empty list */
    Node* head = NULL;
    int x = 21;
 
    /* Use push() to construct below list */
    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);
    
    /* Use printList() to display the list build above in this fashion 14->21->11->30->10 */
    cout << "original list \n";
    printList(head); // [14]-->[21]-->[11]-->[30]-->[10]

    cout << "add the 25 afte the 11 and add the 42 and of the list \n";

    /* Use insertAfter() to insert a new node after the node with value 11 */
    Node* nodeToInsertAfter = head->next->next; // Node with value 11
    insertAfter(nodeToInsertAfter, 25);

    /* Use append() to add a new node at the end of the list */
    append(&head, 42);
    printList(head);

    
    /* use search to find the number */
    cout << "Is there 21 in the list? \n";
    if (search(head,21))
    {
        cout << "THERE IS.\n" << endl; 
    }
    else
    {
        cout << "THERE ARE. \n"<< endl;
    }
    
    /* use deleteFirstNode() to delete the first node */
    cout <<"Deleting the first node.\n";
    deleteFirstNode(&head);
    printList(head);

    /* use deleteMiddleNode() to delete the spesific node t chose */
    cout << "Deleting node with value your chosed"<<endl;
    deleteMiddleNode(&head,11);
    printList(head);

    /* use deleteEnd() to delete the end of the node */
    cout << "Deleting the end node:\n";
    deleteEnd(&head);
    printList(head);
    return 0;
}