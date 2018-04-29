import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

public class NextGreaterElementI {

    /*Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
    Output: [-1,3,-1]
    Explanation:
        For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
        For number 1 in the first array, the next greater number for it in the second array is 3.
        For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
    */

    //思路：对nums2中每一个元素去维护一个decreasing stack, 只能和stack.peek()比，
    // 如果当前num比stack.peek()大， -》num must be the first larger integer of stack.peek()-find it--> store the entry in hashMap


    public int[] nextGreaterElement(int[] nums1, int[] nums2) {


        //考点： 单调stack
        //用一个stack去维护一个decreasing 顺序，{6, 5, 4, 3, 2, 1, 9}
        //hashMap 保存 num： num's next larger number
        //每个数字只进栈一次

        Stack<Integer> stack = new Stack<>();
        Map<Integer, Integer> hashMap = new HashMap<>();

        for(int num:nums2){
            while(!stack.isEmpty() && stack.peek() < num)
                hashMap.put(stack.pop(), num);
            stack.push(num);
        }


        int i = 0;
        for(int n: nums1){
            if(hashMap.containsKey(n))
                nums1[i++] = hashMap.get(n);
            else
                nums1[i++] = -1;
        }

        return nums1;

    }
}
