#include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int maxSum=-999999999;
    int curSum=0;
    for(int i=0;i<N;i++){
        curSum+=arr[i];
        if(maxSum<curSum){
            maxSum=curSum;
        }
        curSum=max(0,curSum);
    }cout<<maxSum<<endl;
    return 0;
}
