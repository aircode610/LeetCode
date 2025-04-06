class Solution {
private:
    void merge(vector<int>& nums, int left, int mid, int right) {
        int i = left;
        int j = mid + 1;
        
        vector<int> merged;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j])
                merged.push_back(nums[i++]);
            else
                merged.push_back(nums[j++]);
        }
        while (i <= mid)
            merged.push_back(nums[i++]);
        while (j <= mid)
            merged.push_back(nums[j++]);
        
        for (int i = 0; i < merged.size(); i++)
            nums[left + i] = merged[i];
    }

    void mergesort(vector<int>& nums, int left, int right) {
        if (left == right)
            return;
        
        int mid = (left + right) / 2;

        mergesort(nums, left, mid);
        mergesort(nums, mid + 1, right);

        merge(nums, left, mid, right);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);

        return nums;
    }
};