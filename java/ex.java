


public class ex{

    static void Validate(int age) throws Exception{
        if(age <0){
            throw new Exception("Age cannot be negative");
        }
    }
    public static void main(String[] args) {
        String str;
        str = "New thing";
        int len = str.length();
        for(int i =0; i <len; i++){
            System.out.print(str.charAt(i));
        }
        System.out.println();
        try{
        Validate(-1);
        }
        catch(Exception e ){
            System.out.println("Age cannot be negative");
        }
    }
}