#include<iostream>
using namespace std;

#define MAXVEX 100
#define INFINITY  65535 

typedef int EdgeType;
typedef char VertexType;

typedef struct
{
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numNodes, numEdges;
} MGraph;

void CreateMGraph(MGraph *Gp)
{
    int i, j, k, w;
    cout << "请输入顶点数和边数（空格分隔）：" << endl;
    cin >> Gp->numNodes >> Gp->numEdges;
    cout << "请输入顶点信息（空格分隔）：" << endl;
    for (i = 0; i < Gp->numNodes; i++)
        cin >> Gp->vexs[i];
    for (i = 0; i < Gp->numNodes; i++)
    {
        for (j = 0; j < Gp->numNodes; j++)
        {
            if (i == j)
                Gp->arc[i][j] = 0;
            else
                Gp->arc[i][j] = INFINITY;
        }
    }

    for (k = 0; k < Gp->numEdges; k++)
    {
        cout << "请输入边（vi, vj)的上标i，下标j和权值w（空格分隔）:" << endl;
        cin >> i >> j >> w;
        Gp->arc[i][j] = w;
        Gp->arc[j][i] = Gp->arc[i][j];
    }
}

int main(void)
{
    MGraph MG;
    CreateMGraph(&MG);

    return 0;
}
