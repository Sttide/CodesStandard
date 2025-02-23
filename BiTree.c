#include <stdio.h>
#include <string.h>

typedef struct DataNode
{
    int iNum;
    int iName;
    /* data */
    DATA_NODE_S *plst, *pright;
}DATA_NODE_S;

typedef struct 
{
    DATA_NODE_S *pstRoot;
    DATA_NODE_S  stNodes[100];
    /* data */
}BI_TREE_S;

int parent[100] = {0};
//parent[node[i].plst] = i;
int findParent(int x)
{
    if (x != 0)
    return  findParent(parent[x]);
}

int main()
{
    return 0;
}