public class FriendCircles {

    //这题和LeetCode 200 Number of Island 有明显 区别
    /*
    此处每个matrix中每个cell并不是一个节点！

    依据题意： 此题转化成图应该是一个无向连通图，我们要找的是有多少个连通分量
    - 图共有： n = M.size() 节点
    - 遍历每个节点， 找到关于当前此节点的朋友，继续下去DFS/BFS
    - 看一共调用了几次DFS/BFS
    */

    /*
    Space complecity: O(n)
    time complexity: O(n^2)
    */

    public int findCircleNum(int[][] M) {
        if(M.length == 0)
            return 0;

        int n = M.length;
        int count = 0;
        int[] visited = new int[n];
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                count++;
                dfs(M, i, visited);
            }
        }

        return count;
    }


    public void dfs(int[][] M, int cur, int[] visited){

        visited[cur] = 1;
        for(int i = 0; i < M.length; i++){
            if(visited[i] == 0 && M[cur][i] == 1){
                visited[i] = 1;
                dfs(M, i, visited);
            }
        }
    }
}
