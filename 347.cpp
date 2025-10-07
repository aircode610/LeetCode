class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> cnt;
        for (auto& num : nums)
            cnt[num]++;

        map<int, vector<int>> freq;
        for (auto& [key, value] : cnt) {
            freq[value].push_back(key);
        }
        
        int i = 0;
        vector<int> ans;
        for (auto it = freq.rbegin(); it != freq.rend() && i < k; ++it) {
            auto& list = it->second;
            int j = 0;
            while (i < k && j < list.size()) {
                ans.push_back(list[j++]);
                i++;
            }
        }
        
        return ans;
    }
};