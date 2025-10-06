class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const auto& str : strs) {
            vector<int> cnt(26, 0);
            for (const auto& c : str)
                cnt[c - 'a']++;
            
            string hash = to_string(cnt[0]);
            for (int i = 1; i < 26; i++)
                hash += ',' + to_string(cnt[i]);

            cout << hash << endl;
            groups[hash].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto& [group, strs] : groups)
            ans.push_back(strs);

        return ans;
    }
};