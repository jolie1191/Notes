/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        if(n == 0)
            return {};

        vector<int> permutation;
        vector<vector<string>> boards;
        vector<bool> visited(n, false);

        dfsPermutation(permutation, n, boards, visited);
        return boards;
    }

    void dfsPermutation(vector<int> &permutation, int n, vector<vector<string>> &boards, vector<bool> &visited)
    {
        if(permutation.size() == n)
        {
            boards.push_back(drawBoard(permutation));
            return;
        }

        for(int i = 0; i < n; i++)
        {
            if(visited[i] == true)
                continue;
            if(!isAttack(permutation, i))
            {
                visited[i] = true;
                permutation.push_back(i);
                dfsPermutation(permutation, n, boards, visited);
                permutation.pop_back();
                visited[i] = false;

            }
        }
    }

    vector<string> drawBoard(vector<int> &permutation)
    {
        vector<string> board;
        int n = permutation.size();
        for(int i = 0; i < n; i++)
        {
            string str(n, '.');
            int col = permutation[i];
            str[col] = 'Q';
            board.push_back(str);
        }

        return board;
    }

    bool isAttack(vector<int> &permutation, int col)
    {
        bool isAttack = false;
        //permutation.push_back(col);
        if(permutation.size() == 0)
            return false;

        int lastIndex = permutation.size();
        for(int i = 0; i < permutation.size(); i++)
        {
           if(permutation[i] + i == col + lastIndex || permutation[i] - i == col - lastIndex)
               isAttack = true;
        }

        //permutation.pop_back();

        return isAttack;
    }
};
