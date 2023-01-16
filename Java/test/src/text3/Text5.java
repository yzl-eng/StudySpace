package text3;

import java.io.*;

public class Text5 {
    public static void main(String[] args) {

        FileInputStream in = null;
        FileOutputStream out = null;
        try {
            in = new FileInputStream("D:/File/speech.txt");
            out = new FileOutputStream("D:/File/speechcp.txt");
            int p = 0;
            byte[] b = new byte[1024];
            while ((p = in.read(b)) != -1) {
                out.write(b, 0, p);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                in.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
            try {
                out.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
