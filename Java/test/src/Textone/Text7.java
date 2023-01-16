package Textone;

import java.util.Scanner;
public class Text7 {
    public static void main(String[] args){
        System.out.println("请选择频道");
        int n = new Scanner(System.in).nextInt();
        switch (n){
            case 33:
                System.out.println("CCTV新闻频道");
                break;
            case 31:
                System.out.println("CCTV体育频道");
                break;
            case 30:
                System.out.println("CTV中文国际");
                break;
            case 55:
                System.out.println("CCTV综合");
                break;
            default:
                System.out.println("你选择的频道"+n+"不存在，请重新选择");
                break;
        }



    }
}
