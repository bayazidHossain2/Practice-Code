#include<iostream>
#include<stack>
using namespace std;
int maximum_rectangular_area(int arr[],int N){
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
    return maximum_area;
}
int main(){
    int T;
    cin>>T;
    for(int tc=1;tc<=T;tc++){
        int M,N;
        cin>>M>>N;
        string arr[M];
        for(int i=0;i<M;i++){
            cin>>arr[i];
        }
        int histo[N] = {0};
        int Result = 0;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(arr[i][j]=='1'){
                    histo[j]=0;
                }else{
                    histo[j]++;
                }
            }
            /*cout<<"For the "<<i<<" th row current histogram is :"<<endl;
            for(int i=0;i<N;i++){
                cout<<histo[i]<<' ';
            }cout<<endl;*/

            int max_area = maximum_rectangular_area(histo,N);
            if(Result < max_area){
                Result = max_area;
            }//cout<<"max area ia : "<<max_area<<endl;
        }
        cout<<"Case "<<tc<<": "<<Result<<endl;
    }
}

/*
5 6
1 0 1 0 1 1
1 0 1 1 0 1
1 1 1 1 1 0
1 1 1 1 1 0
1 1 0 0 1 1
*/

