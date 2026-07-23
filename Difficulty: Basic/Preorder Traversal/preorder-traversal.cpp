class Solution {
  public:
    vector<int> preOrder(Node* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }

    void solve(Node* root, vector<int> &ans) {
        if (root == NULL)
            return;

        ans.push_back(root->data);   
        solve(root->left, ans); 
        solve(root->right, ans);   
    }
};