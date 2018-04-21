/*
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
*/

<<<<<<< HEAD
=======
/*
注意点：
1. 思考return结果是vector<int>
2. 考虑string只有数字的情况
3. atoi(char *): 把string str类型转化char *s1 : str.c_str()

*/

>>>>>>> 7b8904c435b5b96d69d983541cdc526d1d8e9f69
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> results;



        //处理含有+， -， * 的字符串 & 放入结果中
        for(int i = 0; i < input.length(); i++)
        {
            if(isOperator(input[i]))
            {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));

                //int result = calculate(left, right, input[i]);
                for(auto m: left)
                {
                    for(auto n:right)
                    {
                        int result = calculate(m, n, input[i]);
                        results.push_back(result);
                    }
                }
            }
        }

        //这句是重点！！！string中只含有数字"1234"--> 1234
        //conquer
        if (results.empty())
            results.push_back(atoi(input.c_str()));

        return results;
    }

    bool isOperator(char op)
    {
        if(op == '-' || op == '+' || op == '*')
            return true;
        else
            return false;
    }

    int calculate(int m, int n, char op)
    {
        if(op == '-')
            return m - n;
        else if(op == '+')
            return m + n;
        else if(op == '*')
            return m*n;
    }
};
