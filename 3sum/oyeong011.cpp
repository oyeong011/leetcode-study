class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int t = 0;
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> v;
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum == t){
                    v.push_back({nums[i], nums[j], nums[k]}), j++;
                    while(nums[j] == nums[j - 1] && j < k) {
                        j++;
                    }
                }
                else if(sum < t)j++;
                else k--;
            }
        }
        return v;
    }
};
