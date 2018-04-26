public class MedianofTwoSortedArrays {

    public double findMedianSortedArrays(int[] nums1, int[] nums2) {

        //cut1: # of numbers on the left side of the cut on nums1
        //cut1: range of cut [left, right]

        int N1 = nums1.length;
        int N2 = nums2.length;
        int size = N1 + N2;

        if(N2 < N1)
            return findMedianSortedArrays(nums2, nums1);


        if(N1 == 0){
            return ((double) nums2[(N2 - 1) / 2] + (double) nums2[N2 / 2]) / 2;
        }

        int left = 0;
        int right = N1;

        int cut1 = N1/2;
        int cut2 = size/2 - cut1;

        while(cut1 <= N1) {
            cut1 = (right - left) / 2 + left;
            cut2 = size / 2 - cut1;

            int L1 = (cut1 == 0)? Integer.MIN_VALUE : nums1[cut1 - 1];
            int R1 = (cut1 == N1)? Integer.MAX_VALUE : nums1[cut1];

            int L2 = (cut2 == 0)? Integer.MIN_VALUE :nums2[cut2 - 1];
            int R2 = (cut2 == N2)? Integer.MAX_VALUE :nums2[cut2];

            //如果切的正确， 则有 L1 <= R2 && L2 <= R1
            //其他情况： L1 > R2: cut1 左移
            //L2 > R1: cut1 右移
            if (L1 > R2) {
                right = cut1 - 1;
            } else if (L2 > R1) {
                left = cut1 + 1;
            } else {//cut1 切法正确
                if (size % 2 == 0) {
                    L1 = (L1 > L2) ? L1 : L2;
                    R1 = (R1 < R2) ? R1 : R2;
                    return (double)(L1 + R1) / 2;
                } else {
                    R1 = (R1 < R2) ? R1 : R2;
                    return (double)R1;
                }
            }
        }

        return -1;
    }

    public static void main(String[] args){
        //[3,4]
        //[1,2,5]
        int[] nums1 = {3,4};
        int[] nums2 = {1,2,5};

        MedianofTwoSortedArrays md = new MedianofTwoSortedArrays();
        double median = md.findMedianSortedArrays(nums1, nums2);

        System.out.print(median);

    }

}
