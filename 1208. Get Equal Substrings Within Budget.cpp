class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int i = 0;
        int current_cost = 0;
        int max_length = 0;
        for (int j = 0; j < n; j++) {
            current_cost += abs(s[j] - t[j]);
            while (current_cost > maxCost) {
                current_cost -= abs(s[i] - t[i]);
                ++i;
            }
            max_length = max(max_length, j - i + 1);
        }
        return max_length;
    }
};