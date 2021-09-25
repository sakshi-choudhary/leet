class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* ptr1=head,*ptr2=head,*first;
        while(--k)
            ptr1=ptr1->next;       // find first node address
			first=ptr1;                  //store it in first variable
        ptr1=ptr1->next;

        while(ptr1)
        {
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        swap(ptr2->val,first->val); //kth node from end will be at ptr2 so swap ptr2 and first
        return head;
    }
};