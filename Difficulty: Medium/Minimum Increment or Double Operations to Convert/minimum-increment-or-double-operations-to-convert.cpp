class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        int ans = 0;

        while (true) {
            bool allZero = true;

            // Handle odd numbers (reverse of increment)
            for (int &x : arr) {
                if (x % 2 == 1) {
                    x--;
                    ans++;
                }
                if (x != 0)
                    allZero = false;
            }

            if (allZero)
                break;

            // Reverse of double operation
            for (int &x : arr)
                x /= 2;

            ans++;
        }

        return ans;
    }
};