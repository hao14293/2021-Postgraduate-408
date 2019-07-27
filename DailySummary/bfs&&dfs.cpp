#include<iostream>
#include <cstdio>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>
using namespace std;
int n;
vector< list<int> > graph;
bool visited[100] = { 0 };
void CreateGraph()
{
    cout << "input the vertex num:" << endl;
    cin >> n;
    vector< list<int> >::iterator it;
    for (int i = 0; i < n; ++i)
    {
        list<int> i1;
        int t;
        while (cin >> t&&t != n)//输入每个顶点相连的图，以最终节点为结束标志
            i1.push_back(t);
        graph.push_back(i1);
    }
}
void CreateGraph1()
{
    int n;
    vector< list<int> >::iterator it;
    ifstream in("data.txt");
    in >> n;
    for (int i = 0; i < n; ++i)
    {
        list<int> i1;
        int t;
        while (in >> t&&t != n)//输入每个顶点相连的图，以最终节点为结束标志
            i1.push_back(t);
        graph.push_back(i1);
    }
}
void dfs(int v)//以v开始做深度优先搜索
{
    list<int>::iterator it;
    visited[v] = true;
    cout << v << " ";
    for (it = graph[v].begin(); it != graph[v].end(); it++)
        if (!visited[*it])
            dfs(*it);
}
void dfs_noRecursion(int v)//以v开始做深度优先搜索,非递归实现
{
    list<int>::iterator it;
    visited[v] = true;
    cout << v << " ";
    stack<int>mystack;
    mystack.push(v);
    while (!mystack.empty())
    {
        v = mystack.top();
        mystack.pop();
        if (!visited[v])
        {
            cout << v << " ";
            visited[v] = true;
        }

        for (it = graph[v].begin(); it != graph[v].end(); it++)
        {
            if (!visited[*it])
            {
                mystack.push(*it);

            }
        }
    }
    cout << endl;
}
void bfs(int v)//以v开始做广度优先搜索（非递归实现，借助队列）
{
    list<int>::iterator it;
    visited[v] = true;
    cout << v << " ";
    queue<int> myque;
    myque.push(v);
    while (!myque.empty())
    {
        v = myque.front();
        myque.pop();
        for (it = graph[v].begin(); it != graph[v].end(); it++)
        {
            if (!visited[*it])
            {
                cout << *it << " ";
                myque.push(*it);
                visited[*it] = true;//访问过
            }
        }
    }
    cout << endl;
}
int main()
{
    CreateGraph1();
    cout << "result for bfs:" << endl;
    bfs(0);
    memset(visited, 0, sizeof(visited));
    cout << "result for dfs(Recursion):" << endl;
    dfs(0);
    cout << endl;
    memset(visited, 0, sizeof(visited));
    cout << "result for nodfs(Recursion):" << endl;
    dfs_noRecursion(0);
    system("pause");
    return 0;
}
