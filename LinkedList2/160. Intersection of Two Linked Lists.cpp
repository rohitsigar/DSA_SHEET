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
        
        
        int n = 0;
        int m = 0;
        
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        
        while(tempA!=NULL)
        {
            n++;
            tempA = tempA->next;
        }
        
        while(tempB!=NULL)
        {
            m++;
            tempB = tempB->next;
        }
        
        if(m > n)
        {
            swap(headA , headB);
            swap(n ,m);
        }
        
        while(n > m)
        {
            headA = headA->next;
            n--;
        }
        
        while(headA!=NULL)
        {
            if(headA==headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
        
        
        
        
    }
};


// more Simple solution


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        
        ListNode *dA = headA;
        ListNode *dB = headB;
        
        while(dA!=dB)
        {
            dA = (dA==NULL) ? headB : dA->next;
            dB = (dB==NULL) ? headA : dB->next; 
        }
        
        return dA;
        
        
        
        
    }
};