#include <iostream>
using namespace std;
void maxHeapDown(int* a, int start, int end)
{
    int c = start;          
    int l = 2*c + 1;   
    int tmp = a[c];           
    for (; l <= end; c=l,l=2*l+1)
    {
        if ( l < end && a[l] < a[l+1])
            l++;        
        if (tmp >= a[l])
            break;       
        else          
        {
            a[c] = a[l];
            a[l]= tmp;
        }
    }
}


void heapSortAsc(int* a, int n)
{
    int i,tmp;
    for (i = n / 2 - 1; i >= 0; i--)
        maxHeapDown(a, i, n-1);
    for (i = n - 1; i > 0; i--)
    {
        
        tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        maxHeapDown(a, 0, i-1);
    }
}


void minHeapDown(int* a, int start, int end)
{
    int c = start;           
    int l = 2*c + 1;        
    int tmp = a[c];           
    for (; l <= end; c=l,l=2*l+1)
    {
       
        if ( l < end && a[l] > a[l+1])
            l++;        
        if (tmp <= a[l])
            break;        
        else          
        {
            a[c] = a[l];
            a[l]= tmp;
        }
    }
}


void heapSortDesc(int* a, int n)
{
    int i,tmp;

    for (i = n / 2 - 1; i >= 0; i--)
        minHeapDown(a, i, n-1);
    for (i = n - 1; i > 0; i--)
    {
        tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        minHeapDown(a, 0, i-1);
    }
}

int main()
{
    int i,n;
    int a[101];
    cout<<"请输入需排序个数：" ;
    cin>>n;   
    int ilen =n;
    cout << "排序前：";
    for (i=0; i<ilen; i++)
       cin>>a[i];
    cout << endl;
    heapSortAsc(a, ilen);            
    cout << "排序后：";
    for (i=0; i<ilen; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
