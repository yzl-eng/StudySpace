package datamanage;

import java.util.*;

/**
 * @author lms
 */
public class DataManage {
    /**
     * 创建一个Scanner对象用来输入
     */
    Scanner scan = new Scanner(System.in);

    /**
     * 插入数据
     */
    public int[] insertData() {

        int[] arr = new int[10];
        for (int i = 0; i < arr.length - 1; i++) {
            System.out.println("请输入第" + (i + 1) + "个数据:");
            int x = scan.nextInt();
            //保证输入的数据没有0
            if (x != 0) {
                arr[i] = x;
            } else {
                System.out.println("输入数据不能为0，请重新输入！");
                i--;
            }
        }
        return arr;
    }

    /**
     * 打印所有数据
     */
    public void showData(int[] a, int length) {
        if (a[0]==0){
            System.out.println("无数据，请先插入数据！！");
            return;
        }
        System.out.println("所有的数据为：");
        for (int i = 0; i < length; i++) {
            if (a[i] != 0) {
                System.out.print(a[i] + " ");
            } else {
                break;
            }
        }
        System.out.println();
        System.out.println();
    }

    /**
     * 在指定位置插入数据
     * a：目标数组，n：插入位置，k:插入数据
     */
    public void insertAtArray(int[] a, int n, int k) {
        //判断插入位置是否合法
        if (n > 10 || n < 0) {
            System.out.println("插入位置超出范围！！");
            return;
        }
        for (int i = a.length - 1; i > n - 1; i--) {
            a[i] = a[i - 1];
        }
        a[n - 1] = k;
        System.out.println("插入数据完成");
    }

    /**
     * 查寻能被3整除的数据
     */
    public void divThree(int[] a) {
        System.out.println("能被3整除的数据为：");
        int flag = 0;
        for (int i : a) {
            if (i % 3 == 0 && i != 0) {
                flag = 1;
                System.out.print(i + " ");
            }
        }
        System.out.println();
        if (flag == 0) {
            System.out.println("没有被3整除的数据！！");
        }
    }

    /**
     * 显示提示信息
     */
    public void notice() {
        System.out.println("**************************************************");
        System.out.println("\t\t\t\t1----插入数据");
        System.out.println("\t\t\t\t2----显示所有数据");
        System.out.println("\t\t\t\t3----在指定位置数据");
        System.out.println("\t\t\t\t4----查询能被3整除的数据");
        System.out.println("\t\t\t\t0----退出");
        System.out.println("**************************************************");
        System.out.print("请输入对应的数字进行操作：");
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        //创建一个DataManage对象
        DataManage dataManage = new DataManage();
        int[] array = new int[10];
        while (true) {
            dataManage.notice();
            int ch = scan.nextInt();
            switch (ch) {
                case 1:
                    array = dataManage.insertData();
                    dataManage.showData(array, array.length);
                    break;
                case 2:
                    dataManage.showData(array, array.length);
                    break;
                case 3:
                    System.out.println("输入要插入的位置和数据：");
                    int pos = scan.nextInt();
                    int val = scan.nextInt();
                    dataManage.insertAtArray(array, pos, val);
                    dataManage.showData(array, array.length);
                    break;
                case 4:
                    dataManage.divThree(array);
                    break;
                case 0:
                    System.exit(0);
                    break;
                default:
                    System.out.println("输入错误，请输入0-4之间的数字");
                    break;
            }
        }

    }
}

