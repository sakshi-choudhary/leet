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
private:
    int len(ListNode *head) {
    if(head==NULL){
    return 0;
    }
    int smallOutput=len(head->next);
    return smallOutput+1;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int l=len(head);
      
        if(head==NULL||head->next==NULL||k==0){
            return head;
        }
          if(k>=l){
            k=k%l;
        }
        int cnt=0;
        ListNode* prevLst=NULL;
        while(cnt<k){
            ListNode* temp=head;
            while(temp->next!=NULL){
                if(temp->next->next==NULL){
                    prevLst=temp;
                }
                temp=temp->next;
                
            }
            temp->next=head;
            prevLst->next=NULL;
            head=temp;
            cnt++;
        }
        return head;
    }
};