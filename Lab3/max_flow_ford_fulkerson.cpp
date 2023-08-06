#include <bits/stdc++.h>

using namespace std;
#define N 6

bool bfs(int n, int rgraph[][N], int s, int t, int parent[N]){
    int visited[n];
    for(int i=0; i<n; i++)
        visited[i] = 0;
    
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    parent[s] = -1;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v=0; v<n; v++){
            if((visited[v] == 0) && (rgraph[u][v] > 0)){
                if(v == t){
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                visited[v] = 1;
                parent[v] = u;
            }
        }
    }
    return false;
}

int ford_fulkerson(int n, int G[][N], int s, int t){
    
    int rgraph[N][N];
    for(int u=0; u<n; u++){
        for(int v=0; v<n; v++){
            rgraph[u][v] = G[u][v];
        }
    }

    int parent[n];
    int max_flow = 0;

    while(bfs(n,rgraph,s,t,parent)){
        int path_flow = INT_MAX;
        for(int v=t; v!=s; v=parent[v]){
            int u = parent[v];
            path_flow = min(path_flow,rgraph[u][v]);
        }
        
        for(int v=t; v!=s; v=parent[v]){
            int u = parent[v];
            rgraph[u][v] -= path_flow;
            rgraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }

    return max_flow;

}

int main(){
    int n = 6;
    int G[][N] = {{0,16,13,0,0,0},
    {0,0,10,12,0,0},
    {0,4,0,0,14,0},
    {0,0,9,0,0,20}, 
    {0,0,0,7,0,4}, 
    {0,0,0,0,0,0}};
    
    cout << "The max flow of given network is: " << ford_fulkerson(n,G,0,5);
    return 0;
}