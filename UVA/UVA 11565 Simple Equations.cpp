#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    //freopen("001output.txt","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int A,B,C;
        cin>>A>>B>>C;
        bool noSolution=true;
        for(int x=-22;x<=22;x++){
            if(x*x<=C){
                for(int y=-100;y<=100;y++){
                    if(x*x+y*y<=C){
                        for(int z=-100;z<=100;z++){
                            if((x!=y)&&(y!=z)&&(x!=z)&&(x+y+z==A)&&(x*y*z==B)&&(x*x+y*y+z*z==C)){
                                int arr[3]={x,y,z};
                                sort(arr,arr+3);
                                cout<<arr[0]<<' '<<arr[1]<<' '<<arr[2]<<endl;
                                noSolution = false;
                                goto next;
                            }
                        }
                    }
                }
            }
        }
        next:
        if(noSolution){
            cout<<"No solution."<<endl;
        }
    }
}
