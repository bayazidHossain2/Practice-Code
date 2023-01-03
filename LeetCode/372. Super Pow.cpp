#include<iostream>
#include<vector>
using namespace std;
const int M = 1337;
///1337 not a prime number and it's prime factors are 7 and 191
///so etf(1337) = 1337*(1-1/7)*(1-1/191)=6*190=1140
///formula is a^b=((a^(b%etf(M)))%M)

int exp_ite(int a,int b){
    a=a%M;
    int ans=1;
    while(b){
        if(1&b){
            ans=(a*ans)%M;
        }
        a=(a*a)%M;
        b=b>>1;
    }return ans;
}

int superPow(int a, vector<int>& b) {
    int etf=1140;
    int p=1;
    int b_mod_etf=0;
    for(int i=b.size()-1;i>=0;i--){
        b_mod_etf+=(b[i]*p)%etf;
        p*=10;
        p%=etf;
    }
    return exp_ite(a,b_mod_etf);
}
int main(){
    vector<int> b;
    b.push_back(1);
    b.
    cout<<superPow(3,4)<<endl;
}
