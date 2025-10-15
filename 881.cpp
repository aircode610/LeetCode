class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end()); // can be replaced with counting sort

        int l = 0, r = people.size() - 1, ans = 0;
        while (l < r) {
            if (people[l] + people[r] > limit) {
                if (people[l] >= people[r])
                    l++;
                else
                    r--;
            }
            else {
                l++;
                r--;
            }
            ans++;
        }

        if(l == r)
            ans++;

        return ans;
    }
};