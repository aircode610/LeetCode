class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0, right = m * n;
        while (right - left > 1) {
            int mid = (left + right) / 2;

            if (matrix[mid / n][mid % n] <= target)
                left = mid;
            else
                right = mid;
        }

        return matrix[left / n][left % n] == target;
    }
};