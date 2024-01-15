import java.util.*;

interface AnimalFn {
    void displaySound();
    void displayTrivia();
    
}

class poop{

}

class Animal{
    int legno;
    String speciesName;
    String anDiet;
}

class Cat extends Animal implements AnimalFn{

    public void displaySound(){
        System.out.println("Meow");
    }
    public void displayTrivia(){
        //random shit about cats
    }
    
}