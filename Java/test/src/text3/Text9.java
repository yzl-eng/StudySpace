package text3;
class T extends Thread{
    @Override
    public void run() {
        for(int i=1;i<11;i++){
            System.out.println("打印机正在打印"+i);
        }

    }
}
public class Text9 {
    public static void main(String[] args) {
        T t1=new T();
        T t2=new T();
        t1.start();
        t2.start();
    }
}

