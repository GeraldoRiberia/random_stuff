import java.util.*;

public class stbf{
    public static void main(String[] args) {
        StringBuffer str = new StringBuffer();
        str.append("Hello");
        System.out.println(str);
        str.append("World");
        System.out.println(str);
        str.reverse();
        System.out.println(str);
        str.reverse();
        str.delete(1,3);
        System.out.println(str);
    }
}