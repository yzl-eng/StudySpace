package Textone;

public class Text13 {
    public  void get(){

    }
    public static double get(double r)
    {
        return Math.PI*r*r;
    }
    public static float get(float a,float b)
    {
        return a*b;
    }
    public static void main(String[] args)
    {
        System.out.println("圆的面积："+get(4.5));
        System.out.println("长方形面积："+get(8f,5f));
    }

}
