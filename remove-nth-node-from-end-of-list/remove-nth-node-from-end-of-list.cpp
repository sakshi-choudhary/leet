class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //Make an offset pointer and make it move n spaces.
        ListNode* offset = head;
        
        //Then start moving from head again(using curr) so that you can get the n-last position
        ListNode* curr = head;
        
        //Prev required so that curr can be deleted rightaway
        ListNode* prev = new ListNode(-1);
        prev->next = curr;
        
        for(int i = 1; i < n; ++i)
            offset = offset->next;

    
        while(offset->next != NULL)
        {
            offset = offset->next;
            prev=curr;
            curr = curr->next;
        }
        
        prev->next = curr->next;
        
        //For cases where only one number is there OR the first number is deleted
        if(curr==head)
            return head->next;
        
        //Delete the node from memory to avoid leak
        delete curr;
        
        return head;
    }
};