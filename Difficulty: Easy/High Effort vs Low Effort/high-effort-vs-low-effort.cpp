class Solution {
public:
    int maxTask(vector<int>& h, vector<int>& l) {
        int n = h.size();

        // dpNo = maximum tasks when no task is done today
        // dpLow = maximum tasks when low-effort is done today
        // dpHigh = maximum tasks when high-effort is done today

        int dpNo = 0;
        int dpLow = 0;
        int dpHigh = 0;

        for (int i = 0; i < n; i++) {
            int newNo = max({dpNo, dpLow, dpHigh});

            // Low-effort can be done after any previous state
            int newLow = max({dpNo, dpLow, dpHigh}) + l[i];

            // High-effort can only be done if previous day had NO task
            int newHigh = dpNo + h[i];

            dpNo = newNo;
            dpLow = newLow;
            dpHigh = newHigh;
        }

        return max({dpNo, dpLow, dpHigh});
    }
};