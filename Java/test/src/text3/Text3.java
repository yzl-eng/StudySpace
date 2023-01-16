package text3;

import java.io.File;
import java.io.IOException;

public class Text3 {
    public static void main(String[] args) {
        int flag;
        String str1="可读";
        String str2="可写";

        File file1=new File("D:/File/Monday.docx");
        if(!file1.exists())
        {
            try{
                file1.createNewFile();
                System.out.println("创建文件成功！");
            }
            catch (IOException e){
                e.printStackTrace();
            }

        }
        else
        {
            System.out.println("文件已存在");
        }
        System.out.println("文件名称"+file1.getName());
        System.out.println("文件上一级目录"+file1.getParent());
        if(file1.isDirectory())
        {
            System.out.println("文件/目录:这是一个目录");
        }
        else if(file1.isFile()){
            System.out.println("文件/目录:这是一个文件");
        }
        file1.setReadable(false);
        file1.setWritable(true);
        if(!file1.canRead()){
            str1="不可读";
        }
        if(!file1.canWrite())
        {
            str2="不可写";
        }

        System.out.println("可读性：这个文件"+str1+str2);

    }
}
