#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

///Efficient Solution. Time complexity O(nLog(n)).
int main(){
    int N;
    cin>>N;
    vector<pair<int,int>> data(N);
    for(int i=0;i<N;i++){
        cin>>data[i].first;
        data[i].second=i;
    }
    sort(data.begin(),data.end());
    int result=0;
    int mind=0;
    for(int i=1;i<N;i++){
        if(data[mind].second>data[i].second){
            mind=i;
        }else{
            if((data[i].second-data[mind].second)>result){
                result=(data[i].second-data[mind].second);
            }
        }
    }cout<<result<<endl;
    return 0;
}
