package Textone;

public class HelloWorld {
    public static void main(String[] args){
        double money=10000;
        System.out.println("本金："+money);
        System.out.println("活期1年本息总计："+Math.round(money+money*0.0035));
        System.out.println("活期2年本息总计："+Math.round(money+(money*0.0035)+(money+(money*0.0110))*0.00350));
        System.out.println("定期1年本息总计："+Math.round(money+(money*0.015)));
        System.out.println("定期2年本息总计："+Math.round(money+(money*0.021)+(money+(money*0.021))*0.021));
    }

}
