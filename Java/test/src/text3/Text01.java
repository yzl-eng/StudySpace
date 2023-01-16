package text3;

public class Text01 {

    public static void main(String args[]) {

        String s1 = new String("good");

        String s2 = new String("GOOD");

        String s3 = new String("good");

        String s4 = "good";

        boolean b1 = s1.equals(s2);

        boolean b2 = s1.equalsIgnoreCase(s3);

        boolean b3 = s2.endsWith("oD");

        boolean b4 = (s1 == s4);

        System.out.println(b1);

        System.out.println(b2);

        System.out.println(b3);

        System.out.println(b4);

    }

}



