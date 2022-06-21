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
    bool isPalindrome(ListNode* head) {
        
        if(head->next==NULL)
            return true;
        
        
        
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next!=NULL&& fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //now 
        ListNode *prev = slow->next;
        ListNode *cur = prev->next;
        ListNode *str = prev;
        
        while(cur!=NULL)
        {
            ListNode *p = cur->next;
            cur->next  = prev;
            prev = cur;
            cur = p;
        }
        slow->next = prev;
        str->next = NULL;
        
        while(head!=NULL && prev!=NULL)
        {
            if(head->val!=prev->val)
                return false;
            head = head->next;
            prev = prev->next;
        }
        return true;
        
        
        
    }
};