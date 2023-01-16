package CodeSource;

/**
 * 部门类
 * @author lms
 */
public class Department {
    private String dno;
    private String dname;
    private int personNum;
    private Person[] persons;

    public Department() {

    }
    /**
     *获取部门编号
     */
    public String getDno() {
        return dno;
    }
    /**
     *设置部门编号
     */
    public void setDno(String dno) {
        this.dno = dno;
    }
    /**
     *获取部门名称
     */
    public String getDname() {
        return dname;
    }
    /**
     *设置部门名称
     */
    public void setDname(String dname) {
        this.dname = dname;
    }
    /**
     *带参构造方法
     */
    public Department(String dno, String dname) {
        this.setDname(dname);
        this.setDno(dno);
    }
    /**
     *获取部门人数
     */
    public int getPersonNum() {
        return personNum;
    }
    /**
     *设置部门人数
     */
    public void setPersonNum(int personNum) {
        this.personNum=personNum;
    }

    public Person[] getPersons() {
        if (this.persons==null){
            this.persons=new Person[100];
        }
        return persons;
    }
    /**
     * 添加一组员工
     */
    public void setPersons(Person[] persons) {
        this.persons = persons;
    }
    /**
     * 添加单个员工
     */
    public void addPerson(Person person){
        //当persons数组未满时可以插入一个新的员工
        if (this.getPersonNum()<this.getPersons().length){
            this.getPersons()[this.getPersonNum()]=person;
            this.setPersonNum(this.getPersonNum()+1);
        }
    }
}
