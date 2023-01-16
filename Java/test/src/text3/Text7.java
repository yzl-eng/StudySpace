package text3;

import java.io.*;

public class Text7 {
    public static void main(String[] args) throws IOException {
        InputStream input=System.in;
        InputStreamReader fr=new InputStreamReader(input);
        BufferedReader frb=new BufferedReader(fr);
        String n;
        StringBuffer str=new StringBuffer();
        PrintWriter pw=new PrintWriter("D:/File/speech.txt");
        while (true){
            n = frb.readLine();
            if (n.equals("exit")){
                break;
            }
            str.append(n);
            str.append("\r\n");
        }
        System.out.println(str);
        pw.write(String.valueOf(str));
        pw.flush();
        pw.close();
    }
}
