package text3;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Text4 {
    public static void main(String[] args) {
        File file1=new File("D:/File/speech.txt");
        try{
            FileInputStream fl=new FileInputStream(file1);
            int n=0;
            int count=0;
            StringBuffer str=new StringBuffer();
            while((n=fl.read())!=-1){
                count++;
                str.append((char) n);

            }
            System.out.println("文件中内容："+str);
            System.out.println("统计结果："+file1.getName()+"文件中共有"+count+"个字节");
            System.out.println(str.length());
        }
        catch (FileNotFoundException e)
        {

        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
