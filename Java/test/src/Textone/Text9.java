package Textone;

class Monkey{
    String name;
    String feature;
    public Monkey(String name,String feature)
    {
        name=name;
        feature=feature;

    }
    public Monkey(){}

    void Print() {
        System.out.println("这是无参构造输出的结果\n名称："+name+"\n特征:"+feature);
    }

}

public class Text9 {
    public static void main(String[] args){
        Monkey one=new Monkey("长尾猴","尾巴长");
        System.out.println("这是带参构造输出的结果");
        one.Print();
        Monkey two=new Monkey();
        two.name="白头叶猴";
        two.feature="头上有白毛，喜欢吃树叶";
        System.out.println("这是无参构造输出的结果");
        two.Print();
    }
}
