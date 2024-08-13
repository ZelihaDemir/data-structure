#include <iostream>
using namespace std;
class myMatrix
{
private:
    int r;
    int c;
    int **ptr;
public:
myMatrix(int rows,int columns)
{
    r = rows;
    c = columns;
    ptr = new int*[r];
    for(int i=0;i<r;++i)
    {
        ptr[i]=new int[c];
    }
}
~myMatrix()
{
    for(int i=0;i<r;++i)
    {
        delete[]ptr[i];
    }
    delete[]ptr;
}
void initializeMatrix()
{
    cout<<"Enter matrix elements :"<<endl;
    for(int i=0;i<r;++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cout<<"Enter element at position"<<" [" << i << "," << j << "]:";
            cin>>ptr[i][j];
        }
    }

}
int getSpecificElement(int x, int y)
{
    return(ptr[x][y]);
}
bool putElementatSpecificLocation(int x, int y, int value)
{
    if(x>=0 && x<r && y>=0 && y<c)
    {
        ptr[x][y]= value;
        return true;
    }
    return false;
}
double calculateRowSum()
{
    double maxAvg=0.0;
    for(int i=0;i<r;++i)
    {
        double rowSum=0.0;
        for (int j=0;j<c;++j)
        {
            rowSum +=ptr[i][j];
        }
        double row_avg=rowSum/c;
        if(row_avg>maxAvg)
        {
            maxAvg=row_avg;
        }
    }
    return maxAvg;
}
void printMatrix()
{
    cout << "Matrix:"<<endl;
    for(int i=0;i<r;++i)
    {
        for(int j=0;j<c;++j)
        {
            cout <<ptr[i][j]<<"\t";
        }
        cout<<endl;
    }

}
};
int main()
{
    int rows,columns;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    cout<< "Enter the number of columns : ";
    cin>>columns;

myMatrix m(rows,columns);
m.initializeMatrix();

m.printMatrix();

int x,y,value;
cout << "Enter the position (x, y) to get an element: ";
cin>>x>>y;
cout <<"Element at position ("<<x<<","<<y<<"):"<<m.getSpecificElement(x,y)<<endl;

cout << "Enter the position (x, y) and value to put an element: ";
cin>>x>>y>>value;
if(m.putElementatSpecificLocation(x,y,value))
{
    cout<<"value stored successfully"<<endl;
} 
else
cout<<"Falled to store value."<<endl;

double maxavg=m.calculateRowSum();
cout<<"Maximum average row value: "<<maxavg<<endl;


    return 0;
}