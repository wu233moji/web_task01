#include<iostream>  
#include<malloc.h>  
using namespace std;  
 
#define maxNum 100 //定义邻接举证的最大定点数  
int visited[maxNum];//通过visited数组来标记这个顶点是否被访问过，0表示未被访问，1表示被访问  
  
//图的邻接矩阵表示结构  
typedef struct  
{  
    char v[maxNum];//图的顶点信息  
    int e[maxNum][maxNum];//图的顶点信息  
    int vNum;//顶点个数  
    int eNum;//边的个数  
}graph;  
  
void createGraph(graph *g);//创建图g  
void DFS(graph *g);//深度优先遍历图g  
  
void dfs(graph *g,int i)  
{  
    //cout<<"顶点"<<g->v[i]<<"已经被访问"<<endl;  
    cout<<"顶点"<<i<<"已经被访问"<<endl;  
    visited[i]=1;//标记顶点i被访问  
    for(int j=0;j<g->vNum;j++)  
    {  
        if(g->e[i][j]!=0&&visited[j]==0)  
            dfs(g,j);  
    }  
}  
  
void DFS(graph *g)  
{  
    int i;  
    //初始化visited数组，表示一开始所有顶点都未被访问过  
    for(i=0;i<g->vNum;i++)  
        visited[i]=0;  
    //深度优先搜索  
    for(i=0;i<g->vNum;i++)  
        if(visited[i]==0)//如果这个顶点为被访问过，则从i顶点出发进行深度优先遍历  
            dfs(g,i);  
}  
  
void createGraph(graph *g)//创建图g  
{  
    cout<<"正在创建无向图..."<<endl;  
    cout<<"请输入顶点个数vNum:";  
    cin>>g->vNum;  
    cout<<"请输入边的个数eNum:";  
    cin>>g->eNum;  
    int i,j;  
  
    //输入顶点信息  
    //cout<<"请输入顶点信息："<<endl;  
    //for(i=0;i<g->vNum;i++)  
    //  cin>>g->v[i];  
  
    //初始画图g  
    for(i=0;i<g->vNum;i++)  
        for(j=0;j<g->vNum;j++)  
            g->e[i][j]=0;  
  
    //输入边的情况  
    cout<<"请输入边的头和尾"<<endl;  
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
输入： 
正在创建无向图... 
请输入顶点个数vNum:10 
请输入边的个数eNum:9 
请输入边的头和尾 
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
