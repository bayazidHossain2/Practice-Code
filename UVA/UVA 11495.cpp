#include<iostream>
using namespace std;
static long long res;
int arr[999999];

void marge(int l,int mid,int r){
    int range=r-l+5;
    int ls=mid-l+1;
    int temp[range];
    int p=0;
    int lp=l;
    int rp=mid+1;
    while(lp<=mid&&rp<=r){
        if(arr[lp]<=arr[rp]){
            temp[p]=arr[lp];
            lp++;
        }else{
            temp[p]=arr[rp];
            rp++;
            res+=(ls-p);
            //cout<<"current result : "<<res<<endl;
            //cout<<"Updated by : "<<(ls-p)<<endl;
            ls++;
        }p++;
        //cout<<"set :"<<temp[p-1]<<' ';
    }
    while(lp<=mid){
        temp[p]=arr[lp];
        lp++;
        p++;
        //cout<<"set :"<<temp[p-1]<<' ';
    }
    while(rp<=r){
        temp[p]=arr[rp];
        rp++;
        p++;
        //cout<<"set :"<<temp[p-1]<<' ';
    }//cout<<endl<<" copying to main array : ";
    for(int lp=l;lp<=r;lp++){
        arr[lp]=temp[lp-l];
        //cout<<arr[lp]<<' ';
    }//cout<<endl;
}
void marge_sort(int l,int r){
    if(r-l<1){
        return;
    }
    int mid=(l+r)/2;
    marge_sort(l,mid);
    marge_sort(mid+1,r);
    //cout<<"marging limit : "<<l<<' '<<mid<<' '<<r<<endl;
    marge(l,mid,r);
}
void print(int s){
    for(int i=0;i<s;i++){
        cout<<arr[i]<<' ';
    }cout<<endl;
}

int main(){
    //freopen("001output.txt","w",stdout);
    //freopen("001input.txt","r",stdin);
    int N;
    while(cin>>N&&N){
        res=0;
        for(int i=0;i<N;i++){
            //cout<<"enter value : ";
            cin>>arr[i];
        }
        /*cout<<"Before sorting array is : "<<endl;
        print(N);
        cout<<endl;*/
        marge_sort(0,N-1);
        //print(N);
        if(1&res){
            cout<<"Marcelo"<<endl;
        }else{
            cout<<"Carlos"<<endl;
        }
    }return 0;
}


