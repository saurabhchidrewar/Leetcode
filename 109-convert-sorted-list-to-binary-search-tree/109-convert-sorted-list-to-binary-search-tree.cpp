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
class Solution {
    TreeNode* BST(vector<int> &arr, int start, int end) {
        if (start >= end)
            return NULL;
        
        int mid = start + (end - start)/2;
        
        TreeNode* ans = new TreeNode(arr[mid]);
        ans->left = BST(arr, start, mid);
        ans->right = BST(arr, mid+1, end);
        
        return ans;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* p = head;
        vector <int> arr;
        while (p) {
            arr.push_back(p->val);
            p = p->next;
        }
        return BST(arr, 0, arr.size());
    }
};