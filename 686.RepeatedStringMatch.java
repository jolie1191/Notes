public class RepeatedStringMatch {

    public int repeatedStringMatch(String A, String B) {

        //abcd
        //abcdabcd until the A at least has same length of B
        //check if sb.indexOf(B) return count;
        //
        StringBuilder sb = new StringBuilder();
        sb.append(A);
        int count = 1;

        while(sb.length() < B.length()){
            sb.append(A);
            count++;
        }

        if(sb.indexOf(B) >= 0)
            return count;

        //如果没有找到， sb = abcdabcd B = cdabcda, 再append一次
        sb.append(A);
        count++;

        if(sb.indexOf(B) >= 0)
            return count;

        return -1;

    }

}
