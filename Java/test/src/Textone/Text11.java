package Textone;

public class Text11 {
    public static void main(String[] args){
        float[] num={78.5f,98.5f,65.5f,32.5f,75.5f};
        average(num);
    }
    public static void average(float x[]){
        int i=0;
        float sum=0.0f,n=0.0f,aver=0.0f;
        for(i=0;i<x.length;i++)
        {
            sum=sum+x[i];
        }
        aver=sum/x.length;
        System.out.println("数组的平均值："+aver);

    }
}
