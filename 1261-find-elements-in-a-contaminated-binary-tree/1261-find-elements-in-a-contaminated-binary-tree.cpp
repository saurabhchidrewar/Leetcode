/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
    set <int> st;
public:
    void construct(TreeNode* root, int data) {
        if (root == NULL)
            return;
        
        root->val = data;
        st.insert(data);
        
        if (root->left) 
            construct(root->left, 2 * data + 1);
        if (root->right)
            construct(root->right, 2 * data + 2);
    }
    
    FindElements(TreeNode* root) {
        construct(root, 0);
    }
    
    bool find(int target) {
        return st.find(target) != st.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */