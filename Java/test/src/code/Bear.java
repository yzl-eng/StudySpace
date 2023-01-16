package code;

public class Bear extends Animal implements iact.IACT {
    public Bear(String name, int age) {
        super(name, age);
    }

    @Override
    public void love() {
        System.out.println("爱好：喜欢卖萌");
    }

    @Override
    public void skill() {
        System.out.println("技能：挽着花篮，打着雨伞，自立走秀");
    }

    @Override
    public void act() {
        introduce();
        skill();
        love();
    }

    public void introduce() {
        System.out.println("表演者：" + this.getName());
        System.out.println("年龄：" + this.getAge() + "岁");
    }
}
