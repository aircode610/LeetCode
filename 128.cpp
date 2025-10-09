class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> lcs;
        int ans = 0;

        for (int num : nums) {
            if (!lcs[num]) {
                lcs[num] = lcs[num - 1] + lcs[num + 1] + 1;
                lcs[num - lcs[num - 1]] = lcs[num];
                lcs[num + lcs[num + 1]] = lcs[num];
                ans = max(ans, lcs[num]);
            }
        }

        return ans;
    }
};