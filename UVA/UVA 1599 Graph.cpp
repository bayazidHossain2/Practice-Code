#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
void bfs(vector<vector<pair<int,int>>> &adj,int ind,int dis[]){
    bool vis[adj.size()+1]={false};
    queue<int> qu;
    qu.push(ind);
    vis[ind]=true;
    dis[ind]=0;
    while(!qu.empty()){
        int var=qu.front();
        qu.pop();
        for(int i=0;i<adj[var].size();i++){
            if(!vis[adj[var][i].second]){
                vis[adj[var][i].second]=true;
                dis[adj[var][i].second]=dis[var]+1;
                qu.push(adj[var][i].second);
            }
        }
    }
}
int main(){
    int n,m;
    //freopen("001output.txt","w",stdout);
    //freopen("001input.txt","r",stdin);
    while(cin>>n>>m){
        vector<vector<pair<int,int>>> adj(n+1,vector<pair<int,int>>());
        int u,v,c;
        while(m--){
            cin>>u>>v>>c;
            adj[u].push_back(make_pair(c,v));
            adj[v].push_back(make_pair(c,u));
        }

        /*for(int i=1;i<=n;i++){
            sort(adj[i].begin(),adj[i].end());
        }*/
        int dis_from_one[n+1];
        bfs(adj,1,dis_from_one);
        /*for(int i=1;i<=n;i++){
            cout<<i<<' '<<dis_from_one[i]<<endl;
        }cout<<endl;*/
        int dis_from_n[n+1];
        bfs(adj,n,dis_from_n);
        /*for(int i=1;i<=n;i++){
            cout<<i<<' '<<dis_from_n[i]<<endl;
        }*/
        bool con[n+1]={false};
        for(int i=1;i<=n;i++){
            if(dis_from_n[i]+dis_from_one[i]==dis_from_one[n]){
                con[i]=true;
                //cout<<"connected "<<i<<endl;
            }
        }
        vector<int> colors;
        queue<int> indeces;
        indeces.push(1);
        con[1]=false;
        vector<int> mind;
        int mcolor=2000000000;

        while(true){
            if(!indeces.empty()){
                int ind=indeces.front();
                indeces.pop();
                //con[ind]=false;
                //cout<<"Processing for ind : "<<ind<<" n size : "<<adj[ind].size()<<endl;
                for(int i=0;i<adj[ind].size();i++){
                    //cout<<"n : "<<adj[ind][i].second<<" c : "<<adj[ind][i].first<<endl;
                    if(con[adj[ind][i].second]){
                        //cout<<"connected with "<<adj[ind][i].second<<endl;
                        if(adj[ind][i].first<mcolor){
                            mind.clear();
                            mcolor=adj[ind][i].first;
                            mind.push_back(adj[ind][i].second);
                        }else if(adj[ind][i].first==mcolor){
                            mind.push_back(adj[ind][i].second);
                        }//con[adj[ind][i].second]=false;
                    }
                }
            }else{
                colors.push_back(mcolor);
                mcolor=2000000000;
                bool bc=false;
                for(int v : mind){
                    indeces.push(v);
                    con[v]=false;
                    //cout<<"pushing to the que : "<<v<<endl;
                    if(v==n){
                        bc=true;
                    }
                }mind.clear();
                if(bc){
                    break;
                }
            }
        }
        cout<<colors.size()<<endl;
        for(int i=0;i<colors.size();i++){
            cout<<colors[i];
            if((i+1)!=colors.size()){
                cout<<' ';
            }
        }cout<<endl;
    }
}
