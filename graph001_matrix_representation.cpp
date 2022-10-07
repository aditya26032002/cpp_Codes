#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int v1,v2;
    int edges[n+1][n+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j<=n; j++){
            edges[i][j] = 0;
        }
    }

    while(m){
        cin>>v1>>v2;
        edges[v1][v2] = 1;
        edges[v2][v1] = 1;
        m--;
    }
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j<=n; j++){
            cout<<edges[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}