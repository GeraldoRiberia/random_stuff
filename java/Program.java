
class Vehicle {
    String make,model;
    void displayInfo()
    {
        System.out.println("Make : "+make);
        System.out.println("Model : "+model);
    }
}

class Car extends Vehicle{
    int numDoors;
    @Override
    void displayInfo() {
        super.displayInfo();
        System.out.println("Number of Doors : "+numDoors);
    }
}

class Bicycle extends Vehicle{
    int numGears;
    @Override
    void displayInfo() {
        super.displayInfo();
        System.out.println("Number of Gears : "+numGears);
    }
}
class Program{
    public static void main(String args[]){
        Car cr = new Car();
        Bicycle bi = new Bicycle();
        cr.make = "Dodge";
        cr.model="Charger";
        cr.numDoors = 2;
        bi.make = "Yamaha";
        bi.model = "R1";
        bi.numGears = 6;
        cr.displayInfo();
        bi.displayInfo();
    }
}