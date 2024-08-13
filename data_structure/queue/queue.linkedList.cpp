/* This program defines a queue implementation using singly linked list
 * It first implement the linked list class (QNode) for nodes 
 * Then a Queue class to maintain the queue
 */
#include <iostream>
using namespace std;

/* Linked list node to store a queue entry
 */
class QNode {
    public: 
        int data;
        QNode* next;
	// Constructor to create a new linked list node
        QNode(int data) {
            this->data = data;
            this->next = NULL;
        }
};
/* Represent a queue: front stores the front node of the linked list 
 * and rear stores the last node of the linked list */
class Queue {
    public: 
        QNode *front, *rear;
        Queue() { 
            front = rear = NULL; 
        }
        // Method to insert an element to the queue.
        void enqueue(int element) {
            // Create a new linked list node
            QNode* temp = new QNode(element);
            /* If the queue is empty, then the new node
             * is the front and rear both */
            if (rear == NULL) {
                front = rear = temp;
                cout << front->data << " is enqueued\n";
                return;
            }
            /* Otherwise, add the new node at the end of 
            * the queue and change the rear */
            rear->next = temp;
            rear = temp;
            cout << rear->data << " is enqueued\n";
        }

        // Method to remove an element from the queue.
        void dequeue() {
            // If the queue is empty, return NULL.
            if (front == NULL)
                return;
            /* Store the previous front and 
             * move front to one node ahead */
            QNode* temp = front;
            front = front->next;
            /* If the front becomes NULL,  
             * then change rear to NULL also */
            if (front == NULL)
                rear = NULL;
            cout << temp->data << " is dequeued\n";
            delete (temp);
        }

};

// Main driver method
int main() {
    Queue q;
    q.enqueue(36);
    q.enqueue(29);
    q.enqueue(69);
    q.enqueue(11);
    q.dequeue();
    q.enqueue(99);
    q.enqueue(55);
    q.enqueue(80);
    q.dequeue();
    q.dequeue();

// eğer front Null ise ekrana -1 yazdır değil ise datayı yazdır

    cout << "Front Element: " << ((q.front != NULL) ? (q.front)->data : -1)<< endl;
    cout << "Rear Element: " << ((q.rear != NULL) ? (q.rear)->data : -1);
    return 0;
}