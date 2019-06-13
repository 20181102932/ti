#include<iostream>
using namespace std;

template <class T>
class MyArray{
private:
    T *data;
    int size;
public:
    ~MyArray();
    bool check();
    MyArray(int i){
        size=i;
        data=new T[i];
    }
    void sort(){
        T c;
        int a,b;
        for(a=0;a<size;a++)
        {
            cin>>data[a];
        }
        for(a=0;a<size;a++)
        {
            for(b=0;b<size-1;b++)
            {
                if(data[b]>data[b+1])
                {
                    c=data[b];
                    data[b]=data[b+1];
                    data[b+1]=c;
                }
            }
        }
    }
    void display(){
        int a;
        for(a=0;a<size;a++)
        {
            cout<<data[a]<<" ";
        }
        cout<<endl;
    }
};
template<class T>
MyArray<T>::~MyArray(){ delete[] data;}

template<class T>
bool MyArray<T>::check(){
    int i;
    for(i=0;i<size-1;i++)
        if(data[i]>data[i+1]) { cout<<"ERROR!"<<endl;return false;}
    return true;
}
int main( )
{
    MyArray<int> *pI;
    MyArray<float> *pF;
    MyArray<char> *pC;
    int ty, size;
    cin>>ty;
    while(ty>0){
        cin>>size;
        switch(ty){
            case 1: pI = new MyArray<int>(size);   pI->sort(); pI->check(); pI->display(); delete pI; break;
            case 2: pF = new MyArray<float>(size); pF->sort(); pF->check(); pF->display(); delete pF; break;
            case 3: pC = new MyArray<char>(size);  pC->sort(); pC->check(); pC->display(); delete pC; break;
        }
        cin>>ty;
    }
    return 0;
}
