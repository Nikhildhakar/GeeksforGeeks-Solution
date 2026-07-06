class Solution {
public:
    int maxPathSum(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0;
        int m = a.size(), n = b.size();
        
        long long sum_a = 0, sum_b = 0;
        long long result = 0;
        
        while (i < m && j < n) {
            if (a[i] < b[j]) {
                sum_a += a[i++];
            } 
            else if (b[j] < a[i]) {
                sum_b += b[j++];
            } 
            else { 
                result += max(sum_a, sum_b) + a[i];
                sum_a = 0;
                sum_b = 0;
                i++;
                j++;
            }
        }
        
        while (i < m) {
            sum_a += a[i++];
        }
        
        while (j < n) {
            sum_b += b[j++];
        }
        
        result += max(sum_a, sum_b);
        
        return result;
    }
};
