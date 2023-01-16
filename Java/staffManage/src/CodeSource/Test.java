package CodeSource;
import java.util.*;
/**
 * 测试类
 * @author lms
 */
public class Test {
    public static void print(){
        System.out.println("========================");
    }
    public static void main(String[] args) {

        Position[] positions={
                new Position("P001","经理"),
                new Position("P002","助理"),
                new Position("P003","职员")
        };
        Department[] departments={
                new Department("D001","人事部"),
                new Department("D002","市场部")
        };
        Person[] people= {
                new Person("S001","男",29,"人事部","经理","张铭"),
                new Person("S002","女",21,"人事部","助理","李艾爱"),
                new Person("S003","男",29,"人事部","职员","孙超"),
                new Person("S004","女",26,"市场部","职员","张美美"),
                new Person("S005","男",37,"市场部","经理","蓝迪"),
                new Person("S006","女",24,"市场部","职员","米莉")
        };
//        Department de=new Department();
//        de.setPersons(people);
        for (Person p:people) {
            if(p.getDept().equals(departments[0].getDname())){
                departments[0].addPerson(p);
            }
            else {
                departments[1].addPerson(p);
            }
            System.out.println(p.indruduce());
            print();
        }
        for (Department d:departments) {
            System.out.println(d.getDname()+"总共有"+d.getPersonNum()+"名员工\n"+"他们分别是");
            for (Person p:d.getPersons()) {
                if (p!=null){
                    System.out.print(p.getName()+" ");
                }
               else {
                   System.out.println();
                   break;
                }
            }
        }
    }
}
