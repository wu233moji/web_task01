#include <iostream>  
using namespace std;  
void Merge(int *A,int *L,int leftCount,int *R,int rightCount) 
{  
	int i,j,k;  
	i = 0; j = 0; k =0;  
	while(i<leftCount && j< rightCount) 
	{  
        if(L[i]  < R[j]) A[k++] = L[i++];  
        else A[k++] = R[j++];  
    }  
    while(i < leftCount) A[k++] = L[i++];  
    while(j < rightCount) A[k++] = R[j++];  
}  

void MergeSort(int *A,int n) 
{  
    int mid,i, *L, *R;  
    if(n < 2) return;
  
    mid = n/2;  
  
 
    L = new int[mid];  
    R = new int [n - mid];  
  
    for(i = 0;i<mid;i++) L[i] = A[i]; 
    for(i = mid;i<n;i++) R[i-mid] = A[i]; 
  
    MergeSort(L,mid);  
    MergeSort(R,n-mid); 
    Merge(A,L,mid,R,n-mid);  
    delete [] R;  
    delete [] L;  
}  
  
int main() 
{   int n,i;
	cout<<"���������������";
	cin>>n;
	int A[n]; 
	for(i=0;i<n;i++)
	cin>>A[i];
	 MergeSort(A,n);  
	 cout<<"�����Ľ����";
     for(i = 0;i < n;i++)  
       cout<< " " << A[i];  
    return 0;  
}  
