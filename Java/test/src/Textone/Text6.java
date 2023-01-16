package Textone;

class Students {
    String name;
    int age;
    String department;

    public void introduce() {
        System.out.println("name:" + name + "  age:" + age + " department:" + department);
    }
}
class Books{
    String title;
    int pageNum;
    String type;
    public void detail(){
        System.out.println("title:"+title+"  pageNum:"+pageNum+"  type:"+type);
    }

}

    public class Text6 {
        public static void main(String[] args) {
            Books book1=new Books();
            book1.title="数据库原理";
            book1.pageNum=534;
            book1.type="计算机类教材";
            book1.detail();

        }
    }


