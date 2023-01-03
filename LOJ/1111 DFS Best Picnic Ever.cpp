///Unsolved

#include<iostream>
#include<vector>
using namespace std;
const int sz = 1002;
int reach[sz];
bool visited[sz];

void DFS(vector<vector<int>> parent,int u){
    visited[u]=true;
    for(int v : parent[u]){
        if(!visited[v]){
            DFS(parent,v);
        }
        reach[u]+=reach[v];
    }
}

int main(){
    freopen("001Input.txt","r",stdin);
    freopen("001Output.txt","w",stdout);
    int T;
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        int k,n,m;
        cin>>k>>n>>m;
        for(int i=1;i<=n;i++){
            reach[i] = 0;
            visited[i] = false;
        }
        int ki;
        while(k--){
            cin>>ki;
            reach[ki]+=1;
        }
        vector<vector<int>> parent(n+2,vector<int>());
        int u,v;
        while(m--){
            cin>>u>>v;
            parent[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                DFS(parent,i);
            }//cout<<"reach "<<i<<' '<<reach[i]<<endl;
        }
        int res=0;
        for(int i=1;i<=n;i++){
            if(reach[i]>=k){
                res++;
            }
        }cout<<res<<endl;
    }
}
