package collectionTest;

import java.util.ArrayList;
import java.util.List;

class Employee{
    private int id;
    private String name;
    private double salary;

    public Employee(int id, String name, double salary) {
        this.id = id;
        this.name = name;
        this.salary = salary;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }
}
public class Text2 {
    public static void main(String[] args) {
        List employeelist=new ArrayList();
        Employee member1=new Employee(1,"张三",5000);
        Employee member2=new Employee(1,"李四",5500);
        Employee member3=new Employee(1,"赵六",4000);
        employeelist.add(member1);
        employeelist.add(member2);
        employeelist.add(member3);
        System.out.println("员工姓名\t员工薪资");
        for(Object i:employeelist){
            Employee member=(Employee)i;
            System.out.println(member.getName());
        }
//        for(int i=0;i<employeelist.size();i++){
//            Employee member=(Employee)employeelist.get(i);
//            System.out.println(member.getName()+"   "+ member.getSalary());
//        }

    }

}
