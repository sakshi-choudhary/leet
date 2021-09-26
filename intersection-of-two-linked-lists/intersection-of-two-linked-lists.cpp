/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> mp;
        while(headA){
            mp.insert(headA);
            headA=headA->next;
        }
        while(headB){
            if(mp.find(headB)!=mp.end()){
                return headB;
            }
            headB=headB->next;
        }
        return NULL;
    }
};