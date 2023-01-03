#include<iostream>
#include<stack>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    stack<int> stk;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stk.push(0);
    int expl[n];
    int expr[n];
    for(int i=1;i<n;i++){
        while(!stk.empty()&&arr[stk.top()]>=arr[i]){
            expl[stk.top()]=i-stk.top();
            stk.pop();
        }
        stk.push(i);
    }
    while(!stk.empty()){
        expl[stk.top()]=n-stk.top();
        stk.pop();
    }
    for(int i=0;i<n;i++){
        cout<<expl[i]<<' ';
    }cout<<endl;
    stk.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(!stk.empty()&&arr[stk.top()]>=arr[i]){
            expr[stk.top()]=stk.top()-i;
            stk.pop();
        }
        stk.push(i);
    }
    while(!stk.empty()){
        expr[stk.top()]=stk.top()+1;
        stk.pop();
    }
    for(int i=0;i<n;i++){
        cout<<expr[i]<<' ';
    }cout<<endl;
    long long res=0;
    for(int i=0;i<n;i++){
        res+=expl[i]*expr[i]*arr[i];
    }cout<<res<<endl;

}
