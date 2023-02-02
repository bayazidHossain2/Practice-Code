#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[20];
vector<vector<int>> res(2000,vector<int>(6));
int cmb;
int k;
void btc(int ind,int c=0){
    if(c==6){
        res[cmb+1]=res[cmb];
        cmb++;
    }else{
        for(;ind+(5-c)<k;ind++){
            res[cmb][c]=arr[ind];
            btc(ind+1,c+1);
        }
    }
}
int main(){
    //freopen("001input.txt","r",stdin);
    //freopen("001output.txt","w",stdout);
    bool f=false;
    while(cin>>k&&k!=0){
        if(f){
            cout<<endl;
        }else{
            f=true;
        }
        cmb=0;
        for(int i=0;i<k;i++){
            cin>>arr[i];
        }
        sort(arr,arr+k);
        btc(0);
        for(int i=0;i<cmb;i++){
            for(int j=0;j<6;j++){
                cout<<res[i][j];
                if(j!=5){
                    cout<<' ';
                }
            }cout<<endl;
        }
    }
}
