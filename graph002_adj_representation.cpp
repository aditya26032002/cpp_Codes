#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m, v1, v2;
    cin>>n>>m;
    vector<int> adj[n+1];

    while (m--)
    {
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    for(int i = 0; i<=n; i++){
        cout<<i<<"->";
        for(int j = 0; j<adj[i].size(); j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}