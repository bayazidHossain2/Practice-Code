#include<iostream>
#include<vector>
using namespace std;
bool isVisited[30005];
int maxCost;
int costs[30005];
void DFS(vector<vector<pair<int,int>>> adjList,int indx){
    isVisited[indx]=true;
    int mcost=0;
    int smcost=0;
    for(pair<int,int> v : adjList[indx]){
        if(!isVisited[v.first]){
            DFS(adjList,v.first);
            if(mcost<costs[v.first]+v.second){
                smcost=mcost;
                mcost=costs[v.first]+v.second;
            }else if(smcost<costs[v.first]+v.second){
                smcost=costs[v.first]+v.second;
            }
        }
    }
    //cout<<mcost<<endl;
    if(maxCost<mcost+smcost){
        maxCost=mcost+smcost;
    }
    costs[indx]=mcost;
}
int main(){
    int T;
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        int N;
        cin>>N;
        vector<vector<pair<int,int>>> adjList(N,vector<pair<int,int>>());
        int u,v,w;
        isVisited[0]=false;
        costs[0]=0;
        for(int i=1;i<N;i++){
            cin>>u>>v>>w;
            adjList[u].push_back(make_pair(v,w));
            adjList[v].push_back(make_pair(u,w));
            isVisited[i]=false;
            costs[i]=0;
        }maxCost=0;

        DFS(adjList,0);
        cout<<"Case "<<tc<<": "<<maxCost<<endl;
    }return 0;
}
