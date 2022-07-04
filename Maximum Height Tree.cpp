#include<bits/stdc++.h>
using namespace std;
int shortpath(int src,vector<int>adj[],int n)
{
    vector<int>dist(n+1,INT_MAX);
    dist[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(dist[node]+1<dist[it])
            {
                dist[it]=1+dist[node];
                q.push(it);
            }
        }
    }
    return *max_element(dist.begin()+1,dist.end());
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    cout<< shortpath(1,adj,n);

}

// 2 3
// 2 1
// 4 2
// 5 1

// ---------------------------------------------------------------------------------------------------------------
int shortpath(vector<int>adj[],int src,int n)
{
    vector<int>dist(n+1,INT_MAX);
    dist[src]=0;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    cout<< shortpath(1,adj,n);

}