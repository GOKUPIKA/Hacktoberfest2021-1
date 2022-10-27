// Question: Flatten Binary Tree to Linked List
// Platform: Leetcode
// Difficulty: Medium

// **OPTIMIZED APPROACH**
// * Time Complexity: O(n)
// * Space Complexity: O(1)

class Solution {
public:
    
    void flatten(TreeNode* root) {
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left!=NULL){
                TreeNode* prev=curr->left;
                while(prev->right){
                    prev=prev->right;
                }
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
    
};

// **EXPLANATION:**
// 1. We use the threading method in this approach.
// 2. We first move to nodes left's right till it reaches NUll, when it reaches null we mark it right to current's right and left to NULL.


// **RECURSIVE APPROACH**
// * Time Complexity: O(n)
// * Space Complexity: O(n)

class Solution {
public:
    
    TreeNode* prev=NULL;
    
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        flatten(root->right);
        flatten(root->left);
    
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
    
};


// **EXPLANATION:**
// In this we are going to call RIGHT - LEFT - ROOT
// 1. First we make the previous node which intialize store the null and which is further used to make the connection(store previous node).
// 2. We first make the recursive left and right calls and then intialize the left and right node of root ; 
// 3. Left point to NULL
// 4. Right points to previous 


// **ITERATIVE USING STACK APPROACH**
// * Time Complexity: O(n)
// * Space Complexity: O(n)

class Solution {
public:
    
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        
        stack<TreeNode*>st;        
        st.push(root);
        
        while(!st.empty()){
            TreeNode* curr=st.top();
            st.pop();
            
            if(curr->right){
                st.push(curr->right);
            }
            if(curr->left){
                st.push(curr->left);
            }
            if(!st.empty()){
                curr->right=st.top();
            }
            curr->left=NULL;
        }        
    }
    
};
