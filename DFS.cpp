#include<iostream>  
#include<malloc.h>  
using namespace std;  
 
#define maxNum 100 //�����ڽӾ�֤����󶨵���  
int visited[maxNum];//ͨ��visited�����������������Ƿ񱻷��ʹ���0��ʾδ�����ʣ�1��ʾ������  
  
//ͼ���ڽӾ����ʾ�ṹ  
typedef struct  
{  
    char v[maxNum];//ͼ�Ķ�����Ϣ  
    int e[maxNum][maxNum];//ͼ�Ķ�����Ϣ  
    int vNum;//�������  
    int eNum;//�ߵĸ���  
}graph;  
  
void createGraph(graph *g);//����ͼg  
void DFS(graph *g);//������ȱ���ͼg  
  
void dfs(graph *g,int i)  
{  
    //cout<<"����"<<g->v[i]<<"�Ѿ�������"<<endl;  
    cout<<"����"<<i<<"�Ѿ�������"<<endl;  
    visited[i]=1;//��Ƕ���i������  
    for(int j=0;j<g->vNum;j++)  
    {  
        if(g->e[i][j]!=0&&visited[j]==0)  
            dfs(g,j);  
    }  
}  
  
void DFS(graph *g)  
{  
    int i;  
    //��ʼ��visited���飬��ʾһ��ʼ���ж��㶼δ�����ʹ�  
    for(i=0;i<g->vNum;i++)  
        visited[i]=0;  
    //�����������  
    for(i=0;i<g->vNum;i++)  
        if(visited[i]==0)//����������Ϊ�����ʹ������i�����������������ȱ���  
            dfs(g,i);  
}  
  
void createGraph(graph *g)//����ͼg  
{  
    cout<<"���ڴ�������ͼ..."<<endl;  
    cout<<"�����붥�����vNum:";  
    cin>>g->vNum;  
    cout<<"������ߵĸ���eNum:";  
    cin>>g->eNum;  
    int i,j;  
  
    //���붥����Ϣ  
    //cout<<"�����붥����Ϣ��"<<endl;  
    //for(i=0;i<g->vNum;i++)  
    //  cin>>g->v[i];  
  
    //��ʼ��ͼg  
    for(i=0;i<g->vNum;i++)  
        for(j=0;j<g->vNum;j++)  
            g->e[i][j]=0;  
  
    //����ߵ����  
    cout<<"������ߵ�ͷ��β"<<endl;  
    for(int k=0;k<g->eNum;k++)  
    {  
        cin>>i>>j;  
        g->e[i][j]=1;  
        g->e[j][i]=1;  
    }  
}  
  
int main()  
{  
    graph *g;  
    g=(graph*)malloc(sizeof(graph));  
    createGraph(g);  
    DFS(g);  
    int i;  
    cin>>i;  
    return 0;  
}  
  
/* 
���룺 
���ڴ�������ͼ... 
�����붥�����vNum:10 
������ߵĸ���eNum:9 
������ߵ�ͷ��β 
0 1 
0 3 
1 4 
1 5 
3 6 
4 8 
5 2 
6 7 
8 9 
*/  
