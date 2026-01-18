abstract class Parent {
    private int ParentNo;
    public int num1;

    Parent() {
        ParentNo = 1;
        num1 = 10;
    }

    abstract int Add();
}

class Child extends Parent {
    private int ChildNo;

    Child() {
        ChildNo = 2;
    }

    int Add() {
        return (ChildNo + num1);
    }
}

class MainClass {
    public static void main(String args[]) {
        Child c = new Child();
        System.out.println("Sum = " + c.Add());
    }
}