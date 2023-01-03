#include<iostream>
#include<map>
using namespace std;
int main(){
    //freopen("001output.txt","w",stdout);
    int T;
    string line;
    cin>>T;
    cin.ignore();
    getline(cin,line);
    while(T--){
        map<string,int> mp;
        int total=0;
        while(getline(cin,line)){
            if(line==""){
                break;
            }
            mp[line]++;
            total++;
        }
        for(auto v : mp){
            double p=(v.second*100.0)/(total+0.0);
            //cout<<v.second<<' '<<total<<endl;
            cout<<v.first;
            printf(" %.4lf\n",p);
        }
        if(T!=0){
            cout<<endl;
        }
    }return 0;
}
