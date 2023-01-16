package code;

public class Monkey extends Animal implements iact.IACT {
    private String type;

    public Monkey(String name, int age, String type) {
        super(name, age);
        this.setType(type);
    }

    public String getType() {
        return type;
    }

    public void setType(String kind) {
        this.type = type;
    }

    @Override
    public void love() {
        System.out.println("爱好：喜欢模仿人的动作表情");
    }

    @Override
    public void skill() {
        System.out.println("技能：骑独轮车过独木桥");
    }

    @Override
    public void act() {
        introduce();
        skill();
        love();
    }

    public void introduce() {
        System.out.println("表演者：" + getName());
        System.out.println("年龄：" + getAge() + "岁");
        System.out.println("品种：" + getType());
    }
}
