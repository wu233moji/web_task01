#include<iostream>    
#include<malloc.h>    
#include<queue>  
#include<stdlib.h>  
using namespace std;    
  
#define maxNum 100 //�����ڽӾ�֤����󶨵���    
int visited[maxNum];//ͨ��visited�����������������Ƿ񱻷��ʹ���0��ʾδ�����ʣ�1��ʾ������    
queue<int>q;  
//ͼ���ڽӾ����ʾ�ṹ    
typedef struct    
{    
    char v[maxNum];//ͼ�Ķ�����Ϣ    
    int e[maxNum][maxNum];//ͼ�Ķ�����Ϣ    
    int vNum;//�������    
    int eNum;//�ߵĸ���    
}graph;    
//��������  
void createGraph(graph *g);//����ͼg    
void BFS(graph *g);//������ȱ���ͼg    
    
void bfs(graph *g,int i)  
{  
    int k,j;  
    cout<<"����"<<i<<"�Ѿ�������"<<endl;    
    visited[i]=1;//��Ƕ���i������   
      
    q.push(i);  
    while(!q.empty())  
    {  
        k=q.front();  
        q.pop();  
        //cout<<q.size();  
        for(j=1;j<=g->vNum;j++)  
        {  
            if(g->e[k][j]!=0&&visited[j]==0)  
            {  
                cout<<"����"<<j<<"�Ѿ�������"<<endl;  
                visited[j]=1;  
                q.push(j);  
            }  
        }  
    }  
}  
    
void BFS(graph *g)  
{  
    int i;  
    //��ʼ��visited���飬��ʾһ��ʼ���ж��㶼δ�����ʹ�    
    for(i=1;i<=g->vNum;i++)  
        visited[i]=0;  
    //�����������    
    for(i=1;i<=g->vNum;i++)  
    {  
        if(visited[i]==0)//����������Ϊ�����ʹ������i����������й�����ȱ���   
            bfs(g,i);  
    }  
}  
void createGraph(graph *g)//����ͼg    
{    
    cout<<"���ڴ�������ͼ..."<<endl;    
    cout<<"�����붥�����vNum:";    
    cin>>g->vNum;    
    cout<<"������ߵĸ���eNum:";    
    cin>>g->eNum;    
    int i,j;    
    
    //��ʼ��ͼg    
    for(i=1;i<=g->vNum;i++)    
        for(j=1;j<=g->vNum;j++)    
            g->e[i][j]=0;    
    
    //����ߵ����    
    cout<<"������ߵ�ͷ��β"<<endl;    
    for(int k=1;k<=g->eNum;k++)    
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
    BFS(g);    
    system("pause");  
    return 0;    
}    
