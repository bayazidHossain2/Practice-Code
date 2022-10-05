#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(){}
    Node(int data,Node* next,Node* prev){
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};
class LinkList{
public:
    Node* strt;
    bool isRev;
    unordered_map<int,Node*> mp;
    LinkList(int n){
        strt = new Node(1,nullptr,nullptr);
        mp[1] = strt;
        isRev = false;
        for(int i=2;i<=n;i++){
            Node* child = new Node(i,nullptr,mp[i-1]);
            mp[i-1]->next=child;
            mp[i]=child;
        }
    }
    void cutX(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        if(prev != nullptr){
            prev->next = next;
        }
        if(next != nullptr){
            next->prev = prev;
        }
    }
    void addLeft(int x,int y,bool r=true){
        if(isRev&&r){
            addRight(x,y,false);
        }else{
            Node* npx = mp[x];
            Node* npy = mp[y];
            cutX(npx);
            Node* prevY = npy->prev;
            npx->prev = prevY;
            npx->next = npy;
            npy->prev = npx;
            if(prevY!=nullptr){
                prevY->next = npx;
            }
        }
    }
    void addRight(int x,int y,bool r=true){
        if(isRev&&r){
            addLeft(x,y,false);
        }else{
            Node* npx = mp[x];
            Node* npy = mp[y];
            cutX(npx);
            Node* nextY = npy->next;
            npx->prev = npy;
            npx->next = nextY;
            npy->next = npx;
            if(nextY!=nullptr){
                nextY->prev = npx;
            }
        }
    }
    void swp(int x,int y){
        Node* npx = mp[x];
        Node* npy = mp[y];
        int temp = npx->data;
        npx->data = npy->data;
        npy->data = temp;
        Node* tNode = mp[x];
        mp[x] = mp[y];
        mp[y] = tNode;
    }
    void rev(){
        isRev = 1 - isRev;
    }
    void print(Node* temp){
        if(isRev){
            while(temp!=nullptr){
                cout<<temp->data<<' ';
                temp = temp->prev;
            }cout<<endl;
        }else{
            while(temp!=nullptr){
                cout<<temp->data<<' ';
                temp = temp->next;
            }cout<<endl;
        }
    }
    void printR(Node* temp){
        while(temp!=nullptr){
            cout<<temp->data<<' ';
            temp = temp->prev;
        }cout<<endl;
    }
    void findStart(){
        if(isRev){
            while(strt->next != nullptr){
                strt = strt->next;
            }
        }else{
            while(strt->prev != nullptr){
                strt = strt->prev;
            }
        }
    }
    long long getOddSum(){
        long long sum = 0;
        if(isRev){
            while(strt != nullptr){
                sum += strt->data;
                if(strt->prev==nullptr){
                    break;
                }
                strt = (strt->prev)->prev;
            }
        }else{
            while(strt != nullptr){
                sum += strt->data;
                if(strt->next==nullptr){
                    break;
                }
                strt = (strt->next)->next;
            }
        }
        return sum;
    }
};

int  main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    int n,m;
    int tc = 1;
    while(cin>>n>>m){
        LinkList ll = LinkList(n);
        while(m--){
            int q,x,y;
            cin>>q;
            switch(q){
            case 1:
                cin>>x>>y;
                ll.addLeft(x,y);
                break;
            case 2:
                cin>>x>>y;
                ll.addRight(x,y);
                break;
            case 3:
                cin>>x>>y;
                ll.swp(x,y);
                break;
            case 4:
                ll.rev();
            }
            //ll.findStart();
            //ll.print(ll.strt);
        }
        ll.findStart();
        //ll.print(ll.strt);
        cout<<"Case "<<tc++<<": "<<ll.getOddSum()<<endl;
    }return 0;
}
