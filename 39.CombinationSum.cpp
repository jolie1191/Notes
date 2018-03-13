class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> results;
        vector<int> subset;
        dfs(subset, candidates, 0, target, results);

        return results;
    }

    //step 1: From subset, pick numbers from startIndex in set nums to subset which sums up to target, and put these subsets to results.
    //从subset开始， 从nums中的startIndex开始选取一些数放入subset中使得和为target， 找出所有这样的subsets并放入到results中
    void dfs(vector<int> &subset, vector<int> &nums, int startIndex, int target, vector<vector<int>> &results)
    {
        if(target == 0)
        {
            results.push_back(subset);
            return;
        }

        //step 2: 递归的拆解
        for(int i = startIndex; i < nums.size(); i++)
        {
            if(target < nums[i])
                break;

            subset.push_back(nums[i]);
            dfs(subset, nums, i, target - nums[i], results);
            subset.pop_back();
        }
    }

};
