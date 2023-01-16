package CodeSource;

/**
 * 职务类
 *
 * @author lms
 */
public class Position {
    private String pno;
    private String pname;

    public Position(String pno, String pname) {
        this.setPname(pname);
        this.setPno(pno);
    }

    public Position() {

    }

    public String getPno() {
        return pno;
    }

    public void setPno(String pno) {
        this.pno = pno;
    }

    public String getPname() {
        return pname;
    }

    public void setPname(String pname) {
        this.pname = pname;
    }
}
