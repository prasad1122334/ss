#include<iostream>
#include<vector>
#include<queue>
#include<omp.h>
using namespace std;

class Graph
{
    int V;
    vector<int>adj[100];
    public:
    Graph(int v)
    {
        V=v;
    }
    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //parallel BFS
    void BFS(int start)
    {
        bool visited[1000]={false};
        queue<int>q;
        visited[start]=true;
        q.push(start);
        cout<<"Prallel BFS ";
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            cout<<node<<" ";
            for(int i=0;i<adj[node].size();i++)
            {
                int neighbor=adj[node][i];
                if(!visited[neighbor])
                {
                    visited[neighbor]=true;
                    q.push(neighbor);
                }
            }
        }
        cout<<endl;
    }

    //DFS UTILITY
    void DFSUtil(int node,bool visited[])
    {
        visited[node]=true;
        cout<<node<<" ";
        #pragma omp parallel for
        for(int i=0;i<adj[node].size();i++)
        {
            int neighbor=adj[node][i];
            if(!visited[neighbor])
            {
                DFSUtil(neighbor,visited);
            }

        }
    }

    //DFS
    void DFS(int start)
    {
        bool visited[1000]={false};
        cout<<"Parallel DFS ";
        DFSUtil(start,visited);
        cout<<endl;
    }
};

int main()
{
    int V,E;
    cout<<"ENter no of vertices :";
    cin>>V;
    cout<<"ENter No of Egdes :";
    cin>>E;
    Graph g(V);
    cout<<"Enter Edges :";
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    int start;
    cout<<"Enter starting vertex :";
    cin>>start;

    g.BFS(start);
    g.DFS(start);
    return 0;
}