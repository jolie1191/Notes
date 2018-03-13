/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        if(s.size() == 0)
            return {};

        vector<vector<string>> results;
        vector<string> subset;

        dfs(subset, s, 0, results);
        return results;
    }

    void dfs(vector<string> &subset, string s, int startIndex, vector<vector<string>> &results)
    {
        //step 3: exit什么时候要把结果放到results中
        if(startIndex == s.length())
        {
            results.push_back(subset);
            return;//????????
        }

        for(int i = startIndex; i < s.length(); i++)
        {
            //str.substr(pos, size);
            string substring = s.substr(startIndex, i - startIndex + 1);

            if(isPallindrome(substring))
            {
                subset.push_back(substring);
                dfs(subset, s, i + 1, results);
                subset.pop_back();
            }
        }
    }

    bool isPallindrome(string &substring)
    {
        for(int i = 0, j = substring.length() - 1; i < j; i++, j--)
        {
            if(substring[i] != substring[j])
            {
                return false;
            }
        }

        return true;
    }
};
