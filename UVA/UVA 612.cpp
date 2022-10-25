#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int unsortedness(string str){
    int n=0;
    for(int i=0;i<str.size();i++){
        int c=0;
        for(int j=i+1;j<str.size();j++){
            if(str[i]>str[j]){
                c++;
            }
        }n+=c;
    }return n;
}
int main(){
    /*freopen("001Input.txt","r",stdin);
    freopen("001Output.txt","w",stdout);*/
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        string str[m];
        vector<pair<int,int>> inds;
        for(int i=0;i<m;i++){
            cin>>str[i];
            inds.push_back(make_pair(unsortedness(str[i]),i));
            //cout<<inds.back().first<<endl;
        }
        sort(inds.begin(),inds.end());
        for(int i=0;i<m;i++){
            cout<<str[inds[i].second]<<endl;
        }
        if(T!=0){
            cout<<endl;
        }
    }return 0;
}
