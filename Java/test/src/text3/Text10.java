package text3;

class Cat implements Runnable{
    @Override
    public void run() {
        for(int i=1;i<4;i++){
            System.out.println(Thread.currentThread().getName()+"A Cat");
        }

    }
}
class Dog implements Runnable{
    @Override
    public void run() {
        for(int i=1;i<4;i++){
            System.out.println(Thread.currentThread().getName()+"A Dog");
        }
    }
}
public class Text10{
    public static void main(String[] args) {
        Dog dog=new Dog();
        Cat cat=new Cat();
        Thread t1=new Thread(dog);
        Thread t2=new Thread(cat);
        for(int i=1;i<4;i++){
            System.out.println("main Thread");
        }
        t1.start();
        t2.start();
    }
}
