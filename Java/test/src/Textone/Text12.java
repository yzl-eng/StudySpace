package Textone;

class Calculat{
    int a;
    int b;
    public Calculat(int num1,int num2){
        this.a=num1;
        this.b=num2;
    }
    public int addAB(){
        return a+b;
    }
    public int subAB(){
        return a-b;
    }
    public int multiAB(){
        return a*b;
    }
    public int divAB(){
        return a/b;
    }

}

public class Text12 {
    public static void main(String[] args){
        Calculat AB=new Calculat(10,5);
        System.out.println("addAB:"+AB.addAB());
        System.out.println("subAB:"+AB.subAB());
        System.out.println("multiAB:"+AB.multiAB());
        System.out.println("divAB:"+AB.divAB());
    }

}
