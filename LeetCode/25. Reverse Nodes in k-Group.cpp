/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* st=head;
        int arr[k+1];
        if(k==1){
            return head;
        }
        while(true){
            ListNode* n=st;
            bool f=false;
            int p=0;
            while(p<k){
                arr[p++]=n->val;
                if(n->next==nullptr){
                    break;
                }
                n=n->next;
            }
            //cout<<p<<' '<<k<<endl;
            if(p!=k){
                break;
            }else{
                for(int i=k-1;i>=0;i--){
                    //cout<<arr[i]<<' ';
                    st->val=arr[i];
                    st=st->next;
                }//cout<<endl;
                
            }st=n;
            //cout<<"last val is : "<<n->val<<endl;
        }
        return head;
    }
};