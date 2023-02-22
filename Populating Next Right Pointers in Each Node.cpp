/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        // Node*curr=root;
        // while(curr->left!=NULL){
        //     Node*temp=curr;
        //     while(curr!=NULL){
        //         curr->left->next=curr->right;
        //         if (curr -> next!=NULL) curr->right->next = curr->next->left;
        //         curr=curr->next;
        //     }
        //     curr=temp->left;
        // }
        // return root;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                Node*temp=q.front();
                q.pop();
                if(sz==0){
                    temp->next=NULL;
                }else{
                    temp->next=q.front();
                }
                if(temp->left)
                    q.push(temp->left);
                if(temp->right){
                    q.push(temp->right);
                }
            }
         }
        return root;
    }
};