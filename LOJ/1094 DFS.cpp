#include<iostream>
#include<vector>
using namespace std;
long long maxCost;
long long costs[30005];
void DFS(vector<vector<pair<int,int>>> adjList,int indx){
    if(costs[indx]!=-1){
        return;
    }
    costs[indx]=0;
    long long mcost=0;
    long long smcost=0;
    long long cost;
    for(pair<int,int> v : adjList[indx]){
        if(costs[v.first]==-1){
            DFS(adjList,v.first);
            cost = costs[v.first]+v.second;
            if(mcost<=cost){
                smcost=mcost;
                mcost=cost;
            }else if(smcost<cost){
                smcost=cost;
            }
        }
        costs[v.first]=max(long long(0),cost[v.first]);
    }
    //cout<<mcost<<endl;
    if(maxCost<mcost+smcost){
        maxCost=mcost+smcost;
    }
    costs[indx]=mcost;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        int N;
        cin>>N;
        vector<vector<pair<int,int>>> adjList(N,vector<pair<int,int>>());
        int u,v,w;
        costs[0]=-1;
        for(int i=1;i<N;i++){
            cin>>u>>v>>w;
            adjList[u].push_back(make_pair(v,w));
            adjList[v].push_back(make_pair(u,w));
            costs[i]=-1;
        }maxCost=0;

        DFS(adjList,0);
        cout<<"Case "<<tc<<": "<<maxCost<<endl;
    }return 0;
}
