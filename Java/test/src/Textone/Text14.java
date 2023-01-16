package Textone;

import java.util.Scanner;
public class Text14 {
    public static void main(String[] arge){
        int temp;
        Scanner input=new Scanner(System.in);
        int nums[]=new int[7];
        System.out.println("请输入数字，用空格分开");
        for(int i=0;i<nums.length;i++)
        {
            nums[i]=input.nextInt();
        }
        for(int i=0;i<nums.length-1;i++){
            for(int t=i+1;t<nums.length;t++)
            {
                if(nums[i]>nums[t]){
                    temp=nums[i];
                    nums[i]=nums[t];
                    nums[t]=temp;
                }
            }
        }
        System.out.println("输出排序的结果：");
        for(int i=0;i<nums.length;i++)
        {
           System.out.print(nums[i]+" ");
        }
    }


}
