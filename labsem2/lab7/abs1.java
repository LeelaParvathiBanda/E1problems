abstract class Animal {
    public  abstract void makeSound();
}
class Lion extends Animal {
    public  void makeSound(){
        System.out.println("sounds roar");
}
}
class Tiger extends Animal {
    public  void makeSound(){
        System.out.println("sounds loud");
}
}
public class abs1 {
    public static void main(String args[]){
        Animal A=new Lion();
        A.makeSound();
        A=new Tiger();
        A.makeSound();
    }
}