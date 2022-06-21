Node *merge(Node *A , Node* B)
{
    Node* temp = new Node(0);
    Node* res = temp;
    
    while(A!=NULL && B!=NULL)
    {
        if(A->data > B->data)
        {
            temp->bottom = B;
            temp = temp->bottom;
            B = B->bottom;
        }
        else
        {
            temp->bottom = A;
            temp = temp->bottom;
            A = A->bottom;
        }
    }
    
    if(A!=NULL)
    temp->bottom = A;
    else
    temp->bottom = B;
    return res->bottom;
}
Node *flatten(Node *root)
{
   // Your code here
   
   if(root==NULL)
   
   return root;
   if(root->next==NULL)
   return root;
   
   Node *Next = flatten(root->next);
   
   return merge(root , Next);
}
