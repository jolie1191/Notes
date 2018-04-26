import java.util.Arrays;

public class JavaSkill {

    public static void main(String[] args){
        //String
       String str = "hot";
       char[] charArr = str.toCharArray(); //{'h', 'o', 't'}

        String.valueOf(charArr);//"offer";
        String str2 = new String(charArr); //str2 = "offer";

        Arrays.toString(charArr);//"[h, o, t]"
        //System.out.print(charArr);




    }
}
