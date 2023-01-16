package code;

/**
 * @author lms
 */
public abstract class Animal {
    /**
     * 姓名
     * 年龄
     */
    private String name;
    private int age;

    /**
     * 带参构造
     */
    public Animal(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    /**
     * 抽象方法
     */
    public abstract void love();
}
