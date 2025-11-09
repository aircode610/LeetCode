class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            
            if (nums[mid] < nums[r])
                r = mid;
            else   
                l = mid;
        }

        return min(nums[l], nums[r]);
    }
};