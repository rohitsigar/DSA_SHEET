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
        
        if(head->next==NULL)
            return head;
        
        if(k==1)
            return head;
        
        
        int curcnt = 2;
        
        ListNode* cur = head->next;
        ListNode* prev = head;
        
        ListNode* str = head;
        
        ListNode* temp  = head;
        
        int n = 0;
        
        while(temp!=NULL)
        {
            n++;
            temp = temp->next;
        }

        int round = n/k;

        
        int curtot = 0;
        ListNode* prevp = head;
        while(round)
        {
            round--;
            while(curcnt <= k)
            {
                ListNode* p = cur->next;
                cur->next = prev;
                prev = cur;
                cur = p;
                curcnt++;
            }
            str->next = cur;
            if(prevp!=head)
                prevp->next = prev;
            else
                head = prev;
            
            if(round==0)
                break;
            
            prevp = str;
            str = cur;
            prev = cur;
            cur = cur->next;
            curcnt = 2;
        }
        
        return head;
    }
        
   
};