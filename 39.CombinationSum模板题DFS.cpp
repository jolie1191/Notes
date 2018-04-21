/*
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
*/

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
        //此处： i = startIndex; 同义化[1, 1, 2] 和[1, 2, 1]是一样的
        //如果是： i = 0； 区分了[1, 1, 2] 和[1, 2, 1] 是不一样的
        //所以看清题意： 同义化i = startIndex, 区分i = 0
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
