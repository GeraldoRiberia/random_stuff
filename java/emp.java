import java.util.*;


class Employee{
    String name, designation;
    int salary, id;
    Employee(String name, String designation, int  salary, int id){
        this.name = name;
        this.designation = designation;
        this.salary = salary;
        this.id = id;
    }

    void displayInfo(){
        System.out.println("Employee name :"+this.name);
        System.out.println("Employee id : "+this.id);
        System.out.println("Designation : "+this.designation);
        System.out.println("Salary : "+this.salary);
    }


}


public class emp {
    public static void main(String[] args) {

        Employee e1 = new Employee("Adisankar L", "Software Dev", 80000, 515);
        e1.displayInfo();
    }
}
