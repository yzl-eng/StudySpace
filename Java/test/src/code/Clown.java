package code;

public class Clown extends Animal implements iact.IACT {
    private int years;

    public Clown(String name, int age, int years) {
        super(name, age);
        this.setYears(years);
    }

    public int getYears() {
        return years;
    }

    public void setYears(int years) {
        this.years = years;
    }

    public void dress() {
        System.out.println("着装：身穿五彩服装，头上戴着彩色的帽子，脸上画着夸张的彩妆");
    }

    @Override
    public void love() {

    }

    @Override
    public void skill() {
        System.out.println("技能：脚踩高跷，进行杂技魔术表演");
    }

    @Override
    public void act() {
        introduce();
        dress();
        skill();

    }

    public void introduce() {
        System.out.println("表演者：" + getName());
        System.out.println("艺龄：" + getYears() + "年");
    }
}
