class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> ind;
        int ans = 0;

        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            if (ind.find(s[r]) != ind.end())
                l = max(ind[s[r]] + 1, l);

            ans = max(ans, r - l + 1);
            ind[s[r]] = r;
        }

        return ans;
    }
};