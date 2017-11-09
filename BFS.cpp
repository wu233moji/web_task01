#include<iostream>    
#include<malloc.h>    
#include<queue>  
#include<stdlib.h>  
using namespace std;    
  
#define maxNum 100 //定义邻接举证的最大定点数    
int visited[maxNum];//通过visited数组来标记这个顶点是否被访问过，0表示未被访问，1表示被访问    
queue<int>q;  
//图的邻接矩阵表示结构    
typedef struct    
{    
    char v[maxNum];//图的顶点信息    
    int e[maxNum][maxNum];//图的顶点信息    
    int vNum;//顶点个数    
    int eNum;//边的个数    
}graph;    
//函数声明  
void createGraph(graph *g);//创建图g    
void BFS(graph *g);//广度优先遍历图g    
    
void bfs(graph *g,int i)  
{  
    int k,j;  
    cout<<"顶点"<<i<<"已经被访问"<<endl;    
    visited[i]=1;//标记顶点i被访问   
      
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
                cout<<"顶点"<<j<<"已经被访问"<<endl;  
                visited[j]=1;  
                q.push(j);  
            }  
        }  
    }  
}  
    
void BFS(graph *g)  
{  
    int i;  
    //初始化visited数组，表示一开始所有顶点都未被访问过    
    for(i=1;i<=g->vNum;i++)  
        visited[i]=0;  
    //广度优先搜索    
    for(i=1;i<=g->vNum;i++)  
    {  
        if(visited[i]==0)//如果这个顶点为被访问过，则从i顶点出发进行广度优先遍历   
            bfs(g,i);  
    }  
}  
void createGraph(graph *g)//创建图g    
{    
    cout<<"正在创建无向图..."<<endl;    
    cout<<"请输入顶点个数vNum:";    
    cin>>g->vNum;    
    cout<<"请输入边的个数eNum:";    
    cin>>g->eNum;    
    int i,j;    
    
    //初始画图g    
    for(i=1;i<=g->vNum;i++)    
        for(j=1;j<=g->vNum;j++)    
            g->e[i][j]=0;    
    
    //输入边的情况    
    cout<<"请输入边的头和尾"<<endl;    
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
