class Solution {
public:
    int characterReplacement(std::string s, int k) {
        unordered_map<char, int> cnt;
        int ans = 0;

        int l = 0, maxf = 0;
        for (int r = 0; r < s.size(); r++) {
            cnt[s[r]]++;
            maxf = max(maxf, cnt[s[r]]);

            while ((r - l + 1) - maxf > k) {
                cnt[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};