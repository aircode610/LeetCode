class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0 - 1, r = nums.size();
        while (r - l > 1) {
            int m = (l + r) / 2;

            if (target <= nums[m])
                r = m;
            else
                l = m;
        }

        return r;

        // auto it = lower_bound(nums.begin(), nums.end(), target);
        // if (it == nums.end()) return nums.size();
        // return distance(nums.begin(), it);
    }
};