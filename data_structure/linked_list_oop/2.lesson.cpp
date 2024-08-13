#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node(int data = 0)
    {
        this->data=data;
        next=NULL;
    }
};
class List{
    public:
    Node *root;
    List()
    {
        root=NULL;
    }

    bool isEmpty()
    {
        return root==NULL;
    }
    void insertBack(int value)
    {
        if(isEmpty())
        {
            root=new Node(value);
            cout<<"liste oluşturuldu ilk eleman eklendi"<<endl;
        }
        else
        {
            Node *temp=root;
            while(temp->next!=NULL)
            {
                temp=temp->next;//son düğümü buldu
            }
             temp->next=new Node(value);//sona düğüm ekledi
            cout<<"listenin sonuna düğüm eklendi";
        }
    }
};
int main()
{
    List l;
    cout<<l.isEmpty()<<endl;
    l.insertBack(10);
    l.insertBack(30);

}