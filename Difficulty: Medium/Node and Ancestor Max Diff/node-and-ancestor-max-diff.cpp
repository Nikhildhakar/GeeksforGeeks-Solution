class Solution {
public:
    int ans = INT_MIN;

    void solve(Node* root, int mx) {
        if (root == NULL)
            return;

        // Ancestor - current descendant
        ans = max(ans, mx - root->data);

        // Maximum ancestor value for children
        mx = max(mx, root->data);

        solve(root->left, mx);
        solve(root->right, mx);
    }

    int maxDiff(Node* root) {
        if (root == NULL)
            return 0;

        // Root itself is not a descendant of an ancestor
        solve(root->left, root->data);
        solve(root->right, root->data);

        return ans;
    }
};