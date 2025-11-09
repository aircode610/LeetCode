class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> cntT;
        for (auto& c : t)
            cntT[c]++;
        
        int have = 0, need = cntT.size();
        unordered_map<char, int> window;
        pair<int, int> ans = {-1, -1};
        int ansL = INT_MAX;
        int l = 0;

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;

            if (cntT.count(c) && window[c] == cntT[c])
                have++;

            while (have == need) {
                if ((r - l + 1) < ansL) {
                    ans = {l, r};
                    ansL = r - l + 1;
                }

                window[s[l]]--;
                if (cntT.count(s[l]) && window[s[l]] < cntT[s[l]])
                    have--;

                l++;
            }
        }

        return ansL == INT_MAX ? "" : s.substr(ans.first, ansL);
    }
};