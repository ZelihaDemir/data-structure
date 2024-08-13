#include <iostream>
using namespace std;
int *calculateSquare(int* x)
{
    int result = (*x)*(*x);
    int *resultPtr = &result;
    return resultPtr;
}

int main()
{
    int x;
    cout<<"Enter a number :";
    cin>>x;
    cout<<"The square of number is: "<<*calculateSquare(&x)<<endl;

}