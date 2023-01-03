#include<iostream>
using namespace std;

///Not efficient Solution. Time complexity O(n^2).
int main(){
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int result=0;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(arr[i]<=arr[j]&&result<(j-i)){
                result=j-i;
            }
        }
    }cout<<result<<endl;
    return 0;
}
