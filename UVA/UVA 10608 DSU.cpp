#include<iostream>
#include<sstream>
using namespace std;
int parent[30002];
int cnt[30002];
int max_count;
int find_parent(int ind){
    if(parent[ind]==ind){
        return ind;
    }
    parent[ind]=find_parent(parent[ind]);
    return parent[ind];
}
void connect(int x,int y){
    int parentx = find_parent(x);
    int parenty = find_parent(y);
    if(parentx == parenty){
        return;
    }
    //cout<<parentx<<' '<<parenty<<endl;
    parent[parentx] = parenty;
    cnt[parenty] += cnt[parentx];
    //cout<<"P : "<<parenty<<' '<<cnt[parenty]<<endl;
    if(max_count<cnt[parenty]){
        max_count=cnt[parenty];
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int N,M;
        cin>>N>>M;
        for(int i=1;i<=N;i++){
            parent[i]=i;
            cnt[i]=1;
        }max_count = 0;
        while(M--){
            int a,b;
            cin>>a>>b;
            connect(a,b);
        }
        max_count = max(1,max_count);
        cout<<max_count<<endl;
    }return 0;
}


