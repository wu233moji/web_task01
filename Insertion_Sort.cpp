#include<iostream>
using namespace std;
void InsertSort(int a[], int len);
int a[101],n;
int main()
{
    int i;
    cout<<"请输入需要排序个数："<<endl;
	cin>>n;
    for(i=0;i<n;i++) 
     cin>>a[i]; 
    cout<<"排序结果如下："<<endl;
    InsertSort(a, n);
    for(i = 0; i < n; ++i)
       
   cout<<a[i]<<endl;
   return 0;
    
}

void InsertSort(int a[], int len)
{
    int i, j, key;
    for(i = 1; i < len; ++i){
        key = a[i];
        for(j = i-1; j >=0; --j){
            if(a[j] > key)
                a[j+1] = a[j];
            else
                break;
        }
        a[j+1] = key;
    }
}
