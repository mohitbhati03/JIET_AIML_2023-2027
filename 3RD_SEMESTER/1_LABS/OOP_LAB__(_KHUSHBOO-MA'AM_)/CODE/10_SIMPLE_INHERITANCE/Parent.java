class Parent {
    private int parentNo; 
    public int num1;

    Parent() {
        parentNo = 1;
        num1 = 10;
    }

    int addParent() { 
        return (parentNo + num1);
    }
}

class Child extends Parent {
    private int childNo; 

    Child() {
        childNo = 2;
    }

    int addChild() {
        return (childNo + addParent());
    }
}

class MainClass {
    public static void main(String[] args) {
        Parent p = new Parent();
        Child c = new Child();

        System.out.println("Sum of parent class and child class numbers = " + c.addChild());
    }
}