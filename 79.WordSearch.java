public class WordSearch {

    /*
    * Given a 2D board and a word, find if the word exists in the grid.

        The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

        Example:

        board =
        [
          ['A','B','C','E'],
          ['S','F','C','S'],
          ['A','D','E','E']
        ]

        Given word = "ABCCED", return true.
        Given word = "SEE", return true.
        Given word = "ABCB", return false.
*/

    
    /*
    问题分析:
    这是一道二维DFS + 回溯 的题目。类似于用DFS走迷宫的问题。
    首先判断当前决策的可行性，若不可行，则不继续dfs，若可行，则当前决策由有四种选择，上下左右。进行四个方向的dfs，只要有一个方向找到即可，所以是或的关系
    
    因为一个元素不能多次使用，就相当于一个元素只能遍历一次，所以要对已遍历过的元素设置一个已遍历标志。以下三种方法可以做到 
        - 方法1 ：设置一个visit[i][j] 数组，用来标志 board[i][j] 是否已经遍历过。
        - 方法2 ：不用额外空间，若 board[i][j] 已经遍历过，那么将 board[i][j] = "#",*dfs之后再恢复，但这样做有局限性*，必须保证原二维数组中不含 "#"，防止造成冲突。
        - 方法3 ： 不用额外空间，若一个字符 ch（码值小于256） 与 256， 512..异或， ch ^= 256,那么 ch 的 码值一定大于等于了 256，变成了一个非法字符，这样也起到了设置标志的作用，dfs之后再异或回来即可。
   
   注意dfs之后，都要利用回溯恢复 当前元素是否遍历过的标志。
    
    经验教训: 
    二维DFS + 回溯 的套路。
    如何设置已遍历标志的三种做法
    */
    //罗列所有起点+回溯
    //回溯：一开始就对当前遍历元素的正确和错误状态指出，访问标记一定要先设置，然后回溯结束，重置 

    public boolean exist(char[][] board, String word) {

        if(board == null || board.length == 0)
            return false;

        //search(x, y, index)
        //以（x,y) 作为word.get(index)的起点，进行搜索。 return true if find whole sentence, else false.
        //搜索过程中，每个character只能count一次： 方法一： visited[][]; 方法二： Mark on original array, 没成功，记得Mark回来

        //扫描每个cell，以每个cell作为word[0]的起点进行搜索
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                if(search(board, word, 0, i, j))
                    return true;
            }
        }

        return false;
    }

    public boolean search(char[][] board, String word, int index, int x, int y){
        if( x< 0 || x >= board.length || y < 0 || y >= board[0].length) //当前起点越界
            return false;

        if(word.charAt(index) != board[x][y]) //当前起点character不等于要搜索char, 不用往后搜索了，直接返回false
            return false;

        if(index == word.length() - 1) //当前（x,y) 等于要搜索character，且这个character是Word中最后一个，直接返回true
            return true;

        // mark as (x,y) as visited
        char tmp = board[x][y];
        board[x][y] = 0;

        //以(x,y)为起点== word(index), 但是当前index不是最后一个character，继续四面搜索下一个character
        boolean res = search(board, word, index + 1, x, y+1);
        if(res)
            return true;

        res = search(board, word, index + 1, x + 1, y);
        if(res)
            return true;

        res = search(board, word, index + 1, x , y -1);
        if(res)
            return true;

        res = search(board, word, index + 1, x - 1, y);
        if(res)
            return true;

        board[x][y] = tmp; //回溯还原，即：以当前（x,y)为起点== Word[index], 也不能搜索到whole string --->还原
        return false;
    }

}
