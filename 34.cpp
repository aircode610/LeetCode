class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;

        int l = 0 - 1, r = nums.size();
        while (r - l > 1) {
            int m = (l + r)/ 2;
            if (target <= nums[m])
                r = m;
            else
                l = m;
        }

        if (r == nums.size() || nums[r] != target)
            return {-1, -1};
        else
            ans.push_back(r);
        
        l = 0 - 1, r = nums.size();
        while (r - l > 1) {
            int m = (l + r)/ 2;
            if (target + 1 <= nums[m])
                r = m;
            else
                l = m;
        }
        
        ans.push_back(l);
        
        return ans;

        // auto ans = equal_range(nums.begin(), nums.end(), target);
        // if (ans.first == ans.second)
        //     return {-1, -1};
        
        // return { static_cast<int>(distance(nums.begin(), ans.first)), 
        //          static_cast<int>(distance(nums.begin(), prev(ans.second))) };
    }
};