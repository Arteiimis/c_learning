// 寻找图的关键路径
#include <bits/stdc++.h>
using namespace std;

// 最大边数，最大点数
const int Max_M = 1000;
const int Max_N = 50;

struct Graph
{
    int nodeNumber, Link[Max_N], number;
    struct node
    {
        int vertex, weight, next;
    } edge[Max_M];
    void initGraph(int n = 0)
    {
        number = n;
        nodeNumber = 0;
        memset(Link, -1, sizeof(Link));
    }
    void addEdge(int vertex_x, int vertex_y, int weight)
    {
        edge[nodeNumber].vertex = vertex_y;
        edge[nodeNumber].weight = weight;
        edge[nodeNumber].next = Link[vertex_x];
        Link[vertex_x] = nodeNumber;
        nodeNumber++;
    }
    void eraseLink(int vertex)
    {
        Link[vertex] = -1;
    }
};

// 求图的拓扑序列
int topoOrder[Max_N], inDegree[Max_N];
bool topo(Graph &G, int *topoOrder)
{
    memset(inDegree, 0, sizeof(inDegree));
    // 统计入度
    for (int i = 0; i < G.number; i++)
    {
        for (int p = G.Link[i]; p != -1; p = G.edge[p].next)
            inDegree[G.edge[p].vertex]++;
    }

    queue<int> que;
    // 入度为0的入队
    for (int i = 0; i < G.number; i++)
        if (inDegree[i] == 0)
            que.push(i);

    int cnt = 0;
    // 拓扑排序
    while (!que.empty())
    {
        int vertex = que.front();
        topoOrder[cnt++] = vertex;
        que.pop();

        for (int p = G.Link[vertex]; p != -1; p = G.edge[p].next)
        {
            if (--inDegree[G.edge[p].vertex] == 0)
                que.push(G.edge[p].vertex);
        }
    }

    // 如果图中有环，返回false
    return cnt == G.number;
}

// 求图的关键路径

// 输出图的关键路径
int criPath[Max_N];
void findPrecusorNode(Graph &G, int vertex, int number)
{
    criPath[number] = vertex;
    // 当前节点没有前驱节点，已经找到了一条关键路径
    if (G.Link[vertex] == -1)
    {
        for (int i = number; i > 0; i--)
            printf("%d ", criPath[i]);
        printf("%d\n", criPath[0]);
    }
    else    // 否则继续找前驱节点
    {
        for (int p = G.Link[vertex]; p != -1; p = G.edge[p].next)
            findPrecusorNode(G, G.edge[p].vertex, number + 1);
    }
}

int lastVis[Max_N];
Graph g;
void getCriticalPath(Graph &G, int *topoOrder)
{
    memset(lastVis, 0, sizeof(lastVis));
    g.initGraph(G.number);
    // 求最晚发生时间
    for (int i = 0; i < G.number; i++)
    {
        // 从后往前遍历
        for (int p = G.Link[i]; p != -1; p = G.edge[p].next)
        {
            // 更新最晚发生时间
            if (lastVis[G.edge[p].vertex] < lastVis[i] + G.edge[p].weight)
            {
                lastVis[G.edge[p].vertex] = lastVis[i] + G.edge[p].weight;
                // 更新前驱节点
                g.eraseLink(G.edge[p].vertex);
                g.addEdge(G.edge[p].vertex, i, G.edge[p].weight);
            }
            // 如果最晚发生时间相同，更新前驱节点
            else if (lastVis[G.edge[p].vertex] == lastVis[i] + G.edge[p].weight)
                g.addEdge(G.edge[p].vertex, i, G.edge[p].weight);
        }
    }

    // 求关键路径
    int Max_cost = 0;
    for (int i = 0; i < G.number; i++)
        Max_cost = max(Max_cost, lastVis[i]);

    // 输出关键路径长度
    printf("关键路径长度为：%d\n", Max_cost);
    for (int i = 0; i < G.number; i++)
        if (lastVis[i] == Max_cost)
        {
            // 输出关键路径
            findPrecusorNode(g, i, 0);
        }
}

//输出最早发生时间
int earliest[Max_N];
void getEarliest(Graph &G, int *topoOrder)
{
    assert(topo(G, topoOrder));
    memset(earliest, 0, sizeof(earliest));
    // 求最早发生时间
    for (int i = 0; i < G.number; i++)
    {
        // 从前往后遍历
        for (int p = G.Link[topoOrder[i]]; p != -1; p = G.edge[p].next)
        {
            // 更新最早发生时间
            if (earliest[G.edge[p].vertex] < earliest[topoOrder[i]] + G.edge[p].weight)
                earliest[G.edge[p].vertex] = earliest[topoOrder[i]] + G.edge[p].weight;
        }
    }
    // 输出最早发生时间
    for (int i = 0; i < G.number; i++)
        printf("节点%d的最早发生时间为：%d\n", i, earliest[i]);
}

int latest[Max_N];
void getLatest(Graph &G, int *topoOrder)
{
    assert(topo(G, topoOrder));
    memset(latest, 0, sizeof(latest));
    int duration = 100; // 假设项目的总工期为 100 天
    // 求最晚发生时间
    for (int i = 0; i < G.number; i++)
        if (G.Link[i] == -1)
            latest[i] = duration;
    // 从后往前遍历
    for (int i = G.number - 1; i >= 0; i--)
    {
        // 更新最晚发生时间
        for (int p = G.Link[topoOrder[i]]; p != -1; p = G.edge[p].next)
        {
            // 更新最晚发生时间
            if (latest[topoOrder[i]] > latest[G.edge[p].vertex] - G.edge[p].weight)
                latest[topoOrder[i]] = latest[G.edge[p].vertex] - G.edge[p].weight;
        }
    }
    // 输出最晚发生时间
    for (int i = 0; i < G.number; i++)
        printf("节点%d的最晚发生时间为：%d\n", i, latest[i]);
}

int main()
{
    Graph G;
    // 给定10个节点

    int n;
    puts("请输入点的数目:");
    scanf("%d", &n);
    G.initGraph(n);
    puts("请输入边的数目:");
    int m, x, y, w;
    scanf("%d", &m);
    printf("节点编号0 ~ %d\n", n - 1);
    puts("请输入边：（按格式 vertex_x vertex_y weight) ");
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &x, &y, &w);
        G.addEdge(x, y, w);
    }

    if (topo(G, topoOrder))
        getCriticalPath(G, topoOrder);
    else
        puts("图中存在环，故不存在关键路径");

    getEarliest(G, topoOrder);
    getLatest(G, topoOrder);

    return 0;
}