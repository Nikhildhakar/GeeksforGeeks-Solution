# Geek's Destination with Special Jump

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Geek starts at position  **0**  on the positive X-axis and needs to reach or pass position  **d**  on the positive X-axis.

Geek normally follows a repeating movement pattern:

- Move forward by a units, taking a seconds.
- Move backward by b units, taking b seconds.

Geek also has a special jump that moves him exactly  **j**  units forward in 1 second. He can use it at any time, even in the middle of a forward or backward movement, and the journey ends immediately after the jump.

Given five integers  **a**,  **b**,  **d**,  **l**, and  **r**. For every integer j in the range [l, r], find the minimum time required for Geek to reach or pass position d. He may either use the special jump or reach the destination using normal movement alone, whichever takes less time.

Return the sum of the minimum times for all jump lengths from l to r. Since, the answer can be large, return modulo 109 + 7. 

 **Note:** Each jump length is considered independently.

 **Examples:** 

```
Input: a = 2, b = 1, d = 5, l = 3, r = 4
Output: 5
Explanation: 
For j = 3, Geek moves 2 units forward, then takes a jump of 3 units to reach the destination. The minimum time required is 3 seconds.
For j = 4, Geek moves 1 unit forward, then takes a jump of 4 units to reach the destination. The minimum time required is 2 seconds.
Total sum for the range [l, r] = 3 + 2 = 5.
```

```
Input: a = 4, b = 2, d = 8, l = 2, r = 4
Output: 26
Explanation:
For j = 2, Geek moves 4 units forward, then 2 units backward. She then moves 4 units forward again and takes a jump of 2 units to reach the destination. The minimum time required is 11 seconds.
For j = 3, Geek moves 4 units forward, then 2 units backward. She then moves 3 units forward and takes a jump of 3 units to reach the destination. The minimum time required is 10 seconds.
For j = 4, Geek moves 4 units forward, then takes a jump of 4 units to reach the destination. The minimum time required is 5 seconds.
Total sum for the range [l, r] = 11 + 10 + 5 = 26.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-25T09:21:51.246Z  

```cpp
class Solution {
    static constexpr long long MOD = 1000000007LL;

    long long normalTime(long long a, long long b, long long x) {
        if (x <= 0) return 0;
        if (x <= a) return x;
        long long net = a - b;
        long long k = (x - a - 1) / net + 1;
        return x + 2LL * b * k;
    }

    // Sum of (normalTime(a, b, x) + 1) for 1 <= lo <= x <= hi in O(1)
    long long sumJumpRaw(long long a, long long b, long long lo, long long hi) {
        if (lo > hi) return 0;
        long long net = a - b;
        __int128 total = 0;

        // 1 <= x <= a  =>  x + 1
        if (lo <= a) {
            long long end1 = min(hi, a);
            __int128 cnt = end1 - lo + 1;
            total += ((__int128)(lo + end1) * cnt) / 2 + cnt;
            lo = end1 + 1;
        }
        if (lo > hi) return (long long)(total % MOD);

        // x > a  =>  let u = x - a - 1 >= 0, term = u + (a + 2b + 2) + 2b * (u / net)
        long long uLo = lo - a - 1;
        long long uHi = hi - a - 1;
        __int128 cnt = uHi - uLo + 1;

        __int128 baseSum = (((__int128)(uLo + uHi) * cnt) / 2) + cnt * (__int128)(a + 2LL * b + 2LL);

        long long qStart = uLo / net;
        long long qEnd = uHi / net;
        __int128 qSum = 0;

        if (qStart == qEnd) {
            qSum = cnt * (__int128)qStart;
        } else {
            __int128 cFirst = (qStart + 1) * net - uLo;
            qSum += cFirst * (__int128)qStart;

            if (qStart + 1 <= qEnd - 1) {
                long long mLo = qStart + 1;
                long long mHi = qEnd - 1;
                __int128 mCnt = mHi - mLo + 1;
                qSum += (__int128)net * (((__int128)(mLo + mHi) * mCnt) / 2);
            }

            __int128 cLast = uHi - qEnd * net + 1;
            qSum += cLast * (__int128)qEnd;
        }

        total += baseSum + (__int128)(2LL * b) * qSum;
        return (long long)(total % MOD);
    }

public:
    int minTime(int a, int b, int d, int l, int r) {
        long long A = a, B = b, D = d, L = l, R = r;
        long long cap = normalTime(A, B, D);

        long long xLo = max(1LL, D - R);
        long long xHi = min(D - 1, D - L);
        if (xLo > xHi) return 0;

        // Largest x in [xLo, xHi] such that normalTime(A, B, x) + 1 <= cap
        long long left = xLo, right = xHi, split = xLo - 1;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (normalTime(A, B, mid) + 1 <= cap) {
                split = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        __int128 ans = 0;
        if (split >= xLo) {
            ans += sumJumpRaw(A, B, xLo, split);
        }
        if (split + 1 <= xHi) {
            __int128 remCnt = xHi - split;
            ans += remCnt * (__int128)cap;
        }

        return (int)(ans % MOD);
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/geek-and-her-destination--145724/1)