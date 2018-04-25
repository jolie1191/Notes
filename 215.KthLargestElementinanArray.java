public class KthLargestElementinanArray {

    public int findKthLargest(int[] nums, int k) {


        //参照二分法思路， 不断比较K - 1 和pIndex， 再不断缩小范围，直到找到为止
        int start = 0;
        int end = nums.length - 1;

        while(start <= end){
            int pIndex = partition(nums, start, end);

            if(k - 1 == pIndex)
                return nums[pIndex];
            else if(k - 1 < pIndex)
                end = pIndex - 1;
            else
                start = pIndex + 1;
        }

        return nums[k - 1];

    }


    // 在nums中的start 到end， 找到一个pivot，是的pivot左边大于pivot，左边小于pivot
    //return pIndex;
    public int partition(int[] nums, int start, int end){

        int pivot = nums[end];
        int pIndex = start;

        for(int i = start; i < end; i++)
        {
            if(nums[i] >= pivot){
                swap(nums, i, pIndex);
                pIndex++;
            }
        }

        swap(nums, pIndex, end);

        return pIndex;
    }

    public void swap(int[] nums, int a, int b){
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }

}
