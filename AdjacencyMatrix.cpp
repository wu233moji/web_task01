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
    cout << "�����붥�����ͱ������ո�ָ�����" << endl;
    cin >> Gp->numNodes >> Gp->numEdges;
    cout << "�����붥����Ϣ���ո�ָ�����" << endl;
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
        cout << "������ߣ�vi, vj)���ϱ�i���±�j��Ȩֵw���ո�ָ���:" << endl;
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
