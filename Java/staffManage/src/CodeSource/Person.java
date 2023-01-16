package CodeSource;

/**
 * 员工类
 * @author lms
 */
public class Person {
    private String name;
    private String sno;
    private String sex;
    private int age;
    private Department dept;
    private Position position;
    public void setSno(String sno) {
        this.sno = sno;
    }


    public String getName() {
        return name;
    }
    /**
     * 定义无参构造方法
     */
    public Person(){

    }
    //定义带参构造方法
    public Person(String sno, String sex, int age, String dept, String position, String name) {
        this.setSno(sno);
        this.setSex(sex);
        this.setAge(age);
        this.setDept(dept);
        this.setPosition(position);
        this.setName(name);
    }
    
    public void setName(String name) {
        this.name = name;
    }

    public String getSno() {
        return sno;
    }

    public String getSex() {
        return sex;
    }

    public void setSex(String sex) {

        String nan = "男";
        String nv = "女";
        if (!(sex.equals(nan)||sex.equals(nv))){
            System.out.println("性别只能为男或女，将默认设置为男！！");
            this.sex= nan;
            return;
        }
        this.sex = sex;
    }

    public int getAge() {
        return age;
    }
    /**
     * 设置年龄范围只能在18-65岁之间，超出范围初始为18
     */
    public void setAge(int age) {
        if(age<18||age>65){
            System.out.println("年龄只能在18-65岁之间，默认设置为18岁！！");
            this.age=18;
            return;
        }

        this.age = age;
    }

    public String getDept() {
        return dept.getDname();
    }

    public void setDept(String dept) {
        if (this.dept==null)
            this.dept=new Department();
        this.dept.setDname(dept);
    }

    public String getPosition() {
        return position.getPname();
    }

    public void setPosition(String position) {
        if (this.position==null)
            this.position=new Position();
        this.position.setPname(position);
    }

    public String indruduce() {
        return "姓名: "+ this.getName()+"\n工号: "+ this.getSno()+"\n性别: "+ this.getSex()+"\n年龄: "+ this.getAge()+"\n职务: "+ this.getDept() + this.getPosition();
    }
}
