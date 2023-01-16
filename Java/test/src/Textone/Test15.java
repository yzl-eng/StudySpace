package Textone;

class Book{
    private String name;
    private String auther;
    private String press;
    private float price;
    public void setName(String name){
        this.name=name;

    }
    public String getName(){
        return name;
    }
    public void setAuther(String auther){
        this.auther=auther;

    }
    public String getAuther(){
        return auther;
    }
    public void setPress(String press){
        this.press=press;

    }
    public String getPress(){
        return press;
    }
    public void setPrice(float price){
        if(price<10)
            this.price=10f;
        else
            this.price=price;

    }
    public float getPrice(){
        return price;
    }
    public void introduce(){
        System.out.println("书名:"+getName());
        System.out.println("作者:"+getAuther());
        System.out.println("出版社:"+getPress());
        System.out.println("价格:"+getPrice());
    }

}

public class Test15 {
    public static void main(String[] args){
        Book book1=new Book();
        Book book2=new Book();
        book1.setName("红楼梦");
        book1.setAuther("曹雪芹");
        book1.setPress("人民文学出版社");
        book1.setPrice(5f);
        book1.introduce();

        book2.setName("小李飞刀");
        book2.setAuther("古龙");
        book2.setPress("中国长安出版社");
        book2.setPrice(55.5f);
        book2.introduce();
    }

}
