<<<<<<< HEAD
=======
/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

/*
注意点：
1. 题目中允许有重复，就要考虑选代表问题：  处理【1（1），1（2），2】和【1（1）， 1（3）， 2】选代表问题
            if(i != startIndex && nums[i] == nums[i-1])
                continue;


*/

>>>>>>> 7b8904c435b5b96d69d983541cdc526d1d8e9f69
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
<<<<<<< HEAD
            if(i != startIndex && nums[i] == nums[i-1])
                continue;
=======
            //题目中有重复： 处理【1（1），1（2），2】和【1（1）， 1（3）， 2】选代表问题
            if(i != startIndex && nums[i] == nums[i-1])
                continue;
            
>>>>>>> 7b8904c435b5b96d69d983541cdc526d1d8e9f69
            subset.push_back(nums[i]);
            dfs(subset, nums, i + 1, results);
            subset.pop_back();
        }
    }
};
