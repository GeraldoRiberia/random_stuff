package AllwinNebu;


import java.util.Scanner;

class Vechile
{
    String make;
    int model;
    Vechile(String make,int model)
    {
        this.make=make;
        this.model=model;
    }
    void displayInfo()
    {
        System.out.println("Make: "+ make);
        System.out.println("model : "+model);
    }
}

class Car extends Vechile
{
int numDoors;
Car(int numDoors,int model,String make)
{
    super(make,model);
    this.numDoors=numDoors;
}
void displayInfo()
{
    super.displayInfo();
    System.out.println("Number of doors : " + numDoors);
}
}

class Bycycle extends Vechile
{
int numGears;
Bycycle(int numGears,int model,String make)
{
    super(make, model);
    this.numGears=numGears;
}
void displayInfo()
{
    super.displayInfo();
    System.out.println("Numbr of Gears : " + numGears);
}
}
public class Transportation {
    public static void main(String args[])
    {
      Scanner sc =new Scanner(System.in);
      System.out.println("Enter the Car details");
      System.out.println("Enter the Make : ");
      String make=sc.nextLine();
      System.out.println("Enter the Model : ");
      int model=sc.nextInt();
      System.out.println("Enter the NUmber of Doors : ");
      int numDoors=sc.nextInt();
      Car c=new Car(numDoors, model,make);
      c.displayInfo();
      System.out.println("Enter the Bycycle details");
      System.out.println("Enter the Make : ");
      sc.next();
      String make1=sc.nextLine();
      System.out.println("Enter the Model : ");
      int model1=sc.nextInt();
      System.out.println("enter the number of Gears : ");
      int gear=sc.nextInt();
      Bycycle b = new Bycycle(gear, model1, make1);
      b.displayInfo();
      sc.close();
    }
}