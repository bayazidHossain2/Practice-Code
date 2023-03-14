#include<iostream>
using namespace std;
int main(){
    //freopen("001Output.txt","w",stdout);
    long long tot[100];
    long long male[100];
    tot[0]=1;
    tot[1]=2;
    male[0]=0;
    male[1]=1;
    for(int i=2;i<50;i++){
        male[i]=tot[i-1];
        tot[i] = tot[i-1]+tot[i-2]+1;
    }
    int n;
    while(cin>>n&&n!=-1){
        cout<<male[n]<<' '<<tot[n]<<endl;
    }return 0;
}
