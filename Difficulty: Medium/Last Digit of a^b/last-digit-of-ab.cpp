class Solution {
public:
    int getLastDigit(string a, string b) {
        if (b == "0")
            return 1;

        int last = a.back() - '0';

        int mod = 0;
        for (char c : b)
            mod = (mod * 10 + (c - '0')) % 4;

        if (mod == 0)
            mod = 4;

        int ans = 1;
        for (int i = 0; i < mod; i++)
            ans *= last;

        return ans % 10;
    }
};