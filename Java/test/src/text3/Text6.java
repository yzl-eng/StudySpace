package text3;

import java.io.*;


public class Text6 {
    public static void main(String[] args) {
        String file="D:\\File\\speech.txt";
        String file2="D:\\File\\speechcp.txt";
        transwriteByBuf(file2,transreadByBuf(file));
    }
    public  static String transreadByBuf(String file){
        StringBuffer str=new StringBuffer();
        String n=null;
        try {
            FileInputStream f=new FileInputStream(file);
            InputStreamReader fr=new InputStreamReader(f);
            BufferedReader frb=new BufferedReader(fr);
            while ((n= frb.readLine())!=null){
                str.append(n);
                str.append("\r\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        String b=new String(str);
        return b;
    }
    public static void transwriteByBuf(String file,String str){
        try {
            FileOutputStream f=new FileOutputStream(file);
            OutputStreamWriter fo=new OutputStreamWriter(f);
            BufferedWriter fow=new BufferedWriter(fo);
            fow.write(str);
            fow.flush();
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
