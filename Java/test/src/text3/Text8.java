package text3;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

class Apple implements Serializable {
    int ID;
    String name;
    String attribute;
    double price;

    public Apple(int ID, String name, String attribute, double price) {
        this.ID = ID;
        this.name = name;
        this.attribute = attribute;
        this.price = price;
    }

    public Apple() {

    }

    @Override
    public String toString() {
        return "产品ID："+ID+"\n产品名称："+name+"\n产品属性："+attribute+"\n产品价格："+price+"元";
    }
}
public class Text8 {
    public static void main(String[] args) {
        Apple product1=new Apple(123,"iphone","telephone",4888.0);
        Apple product2=new Apple(234,"ipad","computer",5088.0);
        Apple product3=new Apple(345,"macbook","computer",10688.0);
        Apple product4=new Apple(256,"iwatch","watch",4799.0);
        List<Apple> lst=new ArrayList<>();
        lst.add(product1);
        lst.add(product2);
        lst.add(product3);
        lst.add(product4);
        List<Apple> lst2=new ArrayList<>();
        try
        {
            FileOutputStream fileOut = new FileOutputStream("D:/File/speech.txt");
            ObjectOutputStream out = new ObjectOutputStream(fileOut);
//            out.writeObject(product1);
//            out.writeObject(product2);
//            out.writeObject(product3);
//            out.writeObject(product4);
            out.writeObject(lst);
            out.close();
            fileOut.close();
        }catch(IOException i)
        {
            i.printStackTrace();
        }
        try {
            FileInputStream filein=new FileInputStream("D:/File/speech.txt");
            ObjectInputStream in=new ObjectInputStream(filein);
            lst2=(List)in.readObject();
            filein.close();
            in.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        for (Apple a : lst2) {
            System.out.println(a);
        }
    }
}
