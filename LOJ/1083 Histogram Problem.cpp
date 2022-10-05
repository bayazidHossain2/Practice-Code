#include<iostream>
#include<stack>
using namespace std;
int main(){
    int T;
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        int N;
        cin>>N;
        int arr[N];
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }
        int left_count[N];
        int right_count[N];
        stack<int> stk;
        left_count[0]=1;
        stk.push(0);
        for(int i=1;i<N;i++){
            int cnt = 0;
            while(!stk.empty()){
                int indx = stk.top();
                if(arr[indx]>=arr[i]){
                    cnt += left_count[indx];
                }else{
                    break;
                }
                stk.pop();
            }cnt++;
            left_count[i] = cnt;
            stk.push(i);
        }
        /*cout<<"Left count is : ";
        for(int i=0;i<N;i++){
            cout<<left_count[i]<<' ';
        }cout<<endl;*/

        stk = stack<int>();
        right_count[N-1] = 1;
        stk.push(N-1);
        for(int i=N-2;i>=0;i--){
            int cnt = 0;
            while(!stk.empty()){
                int indx = stk.top();
                if(arr[indx]>=arr[i]){
                    cnt += right_count[indx];
                }else{
                    break;
                }
                stk.pop();
            }cnt++;
            right_count[i] = cnt;
            stk.push(i);
        }
        /*cout<<"Right count is : ";
        for(int i=0;i<N;i++){
            cout<<right_count[i]<<' ';
        }cout<<endl;*/

        int maximum_area=0;
        for(int i=0;i<N;i++){
            int area = (left_count[i]+right_count[i]-1)*arr[i];
            if(maximum_area<area){
                maximum_area = area;
            }
        }//cout<<"Maximum area is : "<<maximum_area<<endl;
        cout<<"Case "<<tc<<": "<<maximum_area<<endl;
    }
}

/*
7
5 2 3 4 2 1 5
*/
