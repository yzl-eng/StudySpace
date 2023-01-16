package Textone;

import java.util.Scanner;
public class Text5 {
    public static  void main(String[] args){
        int sum1=0,average1=0,sum2=0,average2=0;
        char[] ch[]=new char[3][];
        int[][] students=new int[3][2];
      for(int t=0;t<students.length;t++)
          for(int i=0;i<students[t].length;i++){
              if(i%2==0)
              {
                  System.out.println("请输入第"+(t+1)+"个学生语文成绩：");
                  int score=new Scanner(System.in).nextInt();
                  sum1=sum1+score;
              }
              else{
                  System.out.println("请输入第"+(t+1)+"个学生数学成绩：");
                  int score=new Scanner(System.in).nextInt();
                  sum2=sum2+score;
              }
              average1=sum1/ students.length;
              average2=sum2/ students.length;
          }

        System.out.println("语文总成绩为："+sum1);
        System.out.println("语文平均分为："+average1);
        System.out.println("数学总成绩为："+sum2);
        System.out.println("数学平均分为："+average2);
    }
}
