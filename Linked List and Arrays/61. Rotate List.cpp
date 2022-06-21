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
    ListNode* rotateRight(ListNode* head, int k) {
        
        int tot = 0;
        
        if(head==NULL)
            return head;
        if(head->next==NULL)
            return head;
        ListNode* temp = head;
        
        while(temp!=NULL)
        {
            if(temp->next==NULL)
            {
                temp->next = head;
                tot++;
                break;
            }
            temp = temp->next;
            tot++;
        }
        
        k = k%tot;
        int str = tot - k;
        
        temp = head;
        

        
        while(str > 1)
        {
            str--;
            temp = temp->next;
        }
        ListNode *ans = temp->next;
        temp->next = NULL;
        return ans;
        
        
    }
};