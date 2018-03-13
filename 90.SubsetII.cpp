class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.size() == 0)
            return {};

        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        vector<int> subset;

        dfs(subset, nums, 0, results);

        return results;

    }


    void dfs(vector<int> &subset, vector<int> &nums, int startIndex, vector<vector<int>> &results)
    {
        results.push_back(subset);

        for(int i = startIndex; i < nums.size(); i++)
        {
            if(i != startIndex && nums[i] == nums[i-1])
                continue;
            subset.push_back(nums[i]);
            dfs(subset, nums, i + 1, results);
            subset.pop_back();
        }
    }
};
