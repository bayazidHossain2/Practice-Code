#include<iostream>
#include<set>
#include<math.h>
#include<vector>
using namespace std;
const int N=500;
int high_divisor[N];
void sieve(){
    for(int i=2;i<N;i++){
        if(high_divisor[i]==0){
            for(int j=i;j<N;j+=i){
                high_divisor[j]=i;
            }
        }
    }
}
unsigned long long pow_ite(int x,int y){
    unsigned long long ans=1,n=x;
    while(y){
        if(1&y){
            ans*=n;
        }n*=n;
        y>>=1;
    }return ans;
}
int main(){
    //cout<<pow_ite(2,2)<<endl;
    //freopen("001output.txt","w",stdout);
    sieve();
    set<unsigned long long> pqu;
    for(int i=2;i<65537;i++){
        for(int j=4;j<500;j++){
            if(high_divisor[j]!=j){
                if(j*log2(i)<64){
                    pqu.insert(pow_ite(i,j));
                }
            }
        }
    }//int c=1;
    cout<<1<<endl;
    for(set<unsigned long long>::iterator i=pqu.begin();i!=pqu.end();i++){
        cout<<(*i)<<endl;

    }
}
