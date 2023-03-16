#include<bits/stdc++.h>

#define p(x) cout<<x<<endl;

using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("001input.txt","r",stdin);
    freopen("001output.txt","w",stdout);
    #endif
    

    int T,R,H;
    while(cin>>T>>R>>H){
    	int priceT[T],priceR[R],priceH[H];
    	int nextT[T][R],nextR[R][H],nextH[H][T];

    	for(int i=0;i<T;i++){
    		cin>>priceT[i];
    		for(int j=0;j<R;j++){
    			cin>>nextT[i][j];
    		}
    	}
    	for(int i=0;i<R;i++){
    		cin>>priceR[i];
    		for(int j=0;j<H;j++){
    			cin>>nextR[i][j];
    		}
    	}
    	for(int i=0;i<H;i++){
    		cin>>priceH[i];
    		for(int j=0;j<T;j++){
    			cin>>nextH[i][j];
    		}
    	}

    	int minc=INT_MAX;
    	int resc=INT_MAX,rt,rr,rh;
    	//cout<<"nc : "<<minc<<endl;
    	for(int i=0;i<T;i++){
    		for(int j=0;j<R;j++){
    			for(int k=0;k<H;k++){
    				if(nextT[i][j]==0&&nextR[j][k]==0&&nextH[k][i]==0){
    					//cout<<i<<' '<<j<<' '<<k<<' '<<endl;
    					int cost = priceT[i]+priceR[j]+priceH[k];
    					if(cost<resc){
    						resc=cost;
    						rt=i;
    						rr=j;
    						rh=k;
    					}
    				}
    				// minc=min(minc,priceT[i]+priceR[j]+priceH[k]);
    				// cout<<"minc : ";
    				// p(minc);
    			}
    		}
    	}
    	if(resc==INT_MAX){
    		p("Don't get married!");
    	}else{
			cout<<rt<<' '<<rr<<' '<<rh<<":"<<resc<<endl;
    	}
    }

    return 0;
}