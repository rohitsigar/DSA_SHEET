/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head==NULL)
        {
            return NULL;
        }
        
        
        
        
        unordered_map<Node* , Node*> m1;
        
        Node* temp = head;
        
        Node* neNode = new Node(0);
        
    
        
        neNode->val = head->val;
            Node *nhead = neNode;
        m1[temp] = nhead;
        while(temp!=NULL)
        {
            if(temp->next!=NULL)
            {
                if(m1.find(temp->next)!=m1.end())
                {
                    Node *tem = m1[temp->next];
                    neNode->next = tem;
                }
                else
                {
                 
                    Node *tp = new Node(0);
                    tp->val = temp->next->val;
                    neNode->next = tp;
                    m1[temp->next] = neNode->next;
                }
               
            }
            
            if(temp->random!=NULL)
            {
                if(m1.find(temp->random)!=m1.end())
                {
                    Node *tem = m1[temp->random];
                    neNode->random = tem;
                }
                else
                {
                   Node *tp = new Node(0);
                    
                    tp->val = temp->random->val;
                    neNode->random = tp;
                    m1[temp->random] = neNode->random;
                    
                    
                }
            }
            else
                neNode->random = NULL;
            
            temp = temp->next;
            neNode = neNode->next;
           
            
            
        }
        return nhead;
       
        
    }
};

//no extra space solution



/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *iter = head; 
          Node *front = head;

          // First round: make copy of each node,
          // and link them together side-by-side in a single list.
          while (iter != NULL) {
            front = iter->next;

            Node *copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;

            iter = front;
          }

          // Second round: assign random pointers for the copy nodes.
          iter = head;
          while (iter != NULL) {
            if (iter->random != NULL) {
              iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
          }

          // Third round: restore the original list, and extract the copy list.
          iter = head;
          Node 