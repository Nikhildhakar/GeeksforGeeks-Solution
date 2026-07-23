class Solution {
  public:
    bool canRepresentBST(vector<int> &arr) {
        stack<int> st;
        int root = INT_MIN;

        for (int x : arr) {
            if (x < root)
                return false;

            while (!st.empty() && st.top() < x) {
                root = st.top();
                st.pop();
            }

            st.push(x);
        }

        return true;
    }
};