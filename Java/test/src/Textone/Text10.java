package Textone;

import java.util.Scanner;
class Money{
    public void money(float n){
        float m=0.0f;
        if(n>200)
            m=n*0.85f;
        else if(n>100)
            m=n*0.95f;
        else
            m=n;
        System.out.println(m);

    }
    void print(){

    }
}

public class Text10 {

    public static void main(String[] args)
    {
        float sum=new Scanner(System.in).nextFloat();
        Money one=new Money();
        System.out.println("折后商品总价：");
        one.money(sum);
    }

}
