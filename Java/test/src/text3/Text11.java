package text3;
class Letter implements Runnable{
    char[] letter=new char[26];

    public Letter() {
        for(int i=0;i<26;i++)
        {
            letter[i]= (char) ('a'+i);
        }
    }

    @Override
    public void run() {

        for (char c : letter) {
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            System.out.print(c+" ");
        }

    }
}
public class Text11 {
    public static void main(String[] args) {

        Letter l=new Letter();
        Thread t=new Thread(l);
        t.start();
    }
}
