package Textone;

import java.util.Scanner;
public class text1 {
    public static void main(String[] args){
        Scanner in=new Scanner(System.in);
        int x,y;
        x=in.nextInt();
        if(x>0){
            y=2*x+1;
        }
        else{
            y=x+5;
        }
        System.out.println("x="+x);
        System.out.println("y="+y);
    }

}
