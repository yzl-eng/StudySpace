package code;
import java.util.*;
/**
 * @author lms
 */
public class Main {
    public static void menu() {
        System.out.println("*************欢迎来到太阳马戏团***********");
        System.out.println("*************  请选择表演者  ************");
        System.out.println("*************   1、棕熊  *************");
        System.out.println("*************   2、狮子  *************");
        System.out.println("*************   3、猴子  *************");
        System.out.println("*************   4、鹦鹉  *************");
        System.out.println("*************   5、小丑  *************");
        System.out.println("*************   0、退出  *************");
    }
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int choice;
        boolean flag;
        while(true){
            menu();
            flag=true;
            choice=scan.nextInt();
            switch (choice){
                case 1:
                    Bear bear=new Bear("Bill",1);
                    bear.act();
                    break;
                case 2:
                    Lion lion=new Lion("Lain",2,"灰色","公狮");
                    lion.act();
                    break;
                case 3:
                    Monkey monkey=new Monkey("Tom",1,"金丝猴");
                    monkey.act();
                    break;
                case 4:
                    Parrot parrot=new Parrot("Rose",1,"牡丹鹦鹉");
                    parrot.act();
                    break;
                case 5:
                    Clown clown=new Clown("Kahle",5,5);
                    clown.act();
                    break;
                case 0:
                    System.exit(0);
                default:
                    flag=false;
                    System.out.println("输入错误，请重新输入(请输入0-5之间的数字)！！");
                    break;
            }

            if (flag){
                System.out.println("**********  是否继续观看 (1 / 0) **********");
                while(true){
                    boolean t=true;
                    choice=scan.nextInt();
                    switch (choice){
                        case 1:
                            break;
                        case 0:
                            System.exit(0);
                        default:
                            t=false;
                            System.out.println("输入错误，请重新输入(请输入0 or 1)！！");
                            break;
                    }
                    if(t) {
                        break;
                    }
                }
            }
        }
    }
}


