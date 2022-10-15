#include<iostream>
using namespace std;
int main(){
    //freopen("001output.txt","w",stdout);

    double h,u,d,f;
    while(cin>>h>>u>>d>>f&&h!=0){
        int day=1;
        double c_h=0.0,fact=(u*(f/100.0));
        //cout<<fact<<endl;
        bool f=false;
        while(true){
            //cout<<"Day : "<<day<<" initial : "<<c_h<<' ';
            c_h+=u;
            if(c_h>h){
                f=true;
                break;
            }//cout<<"D_C : "<<u<<" H_C : "<<c_h<<' ';
            u-=fact;
            if(u<0){
                u=0;
            }

            c_h-=d;
            if(c_h<0){
                break;
            }
            //cout<<"A S : "<<c_h<<endl;
            day++;
        }
        if(f){
            cout<<"success on day "<<day<<endl;
        }else{
            cout<<"failure on day "<<day<<endl;
        }
    }return 0;
}

