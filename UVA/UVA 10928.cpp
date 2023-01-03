#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    //freopen("001output.txt","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int P;
        cin>>P;
        cin.ignore();
        int min_neighbor=10000;
        string str;
        vector<int> res;
        for(int i=1;i<=P;i++){
            getline(cin,str);
            stringstream ss(str);
            int temp;
            int cnt{0};
            while(ss>>temp){
                cnt++;
            }if(cnt<min_neighbor){
                res.clear();
                res.push_back(i);
                min_neighbor=cnt;
            }else if(cnt==min_neighbor){
                res.push_back(i);
            }
        }
        for(int i=0;i<res.size();i++){
            cout<<res[i];
            if((i+1)!=res.size()){
                cout<<' ';
            }
        }cout<<endl;
    }return 0;
}
