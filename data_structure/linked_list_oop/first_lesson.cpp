#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data=0)  //varsayılan parametre olaral 0 atandı
    {
        this->data=data;
        next=NULL;
    }
};

int main()
{
    /*
    Node n1;
    n1.data=10;
    cout<<n1.data<<endl
    */
    Node *n1=new Node(10);  //nesne oluşturuldu
    Node *n2=new Node(20);
    Node *n3=new Node(30);

    n1->next=n2;    //düğümleri birbirine bağladık
    n2->next=n3;

    cout<<n1->data<<" ";
    cout<<n2->data<<" ";
    cout<<n3->data<<endl;

    cout<<n1->data<<" ";
    cout<<n1->next->data;
    cout<<" "<<n1->next->next->data<<endl;

    Node *temp=n1;

    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    

     
}
