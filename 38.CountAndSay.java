public class CountAndSay {

    public String countAndSay(int n) {

        String res = "1";
        char prev = ' '; // char 此时为空
        //int count = 0;

        for(int i = 1; i < n; i++){
            StringBuilder str = new StringBuilder();
            char[] arr = res.toCharArray();
            prev = arr[0];


            int count = 0;
            for(int j = 0; j < res.length(); j++){

                if(prev == arr[j]){
                    count++;
                    prev = arr[j];
                }else{

                    str.append(count);
                    str.append(prev);
                    prev = arr[j];
                    count = 1;
                }

            }

            str.append(count);
            str.append(prev);

            res = str.toString();
        }

        return res;
    }
}
