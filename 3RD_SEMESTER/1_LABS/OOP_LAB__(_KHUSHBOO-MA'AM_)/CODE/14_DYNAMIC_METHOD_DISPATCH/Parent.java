class Parent {
    private int ParentNo;
    public int num1;

    Parent() {
        ParentNo = 1;
        num1 = 10;
    }

    int Add() {
        return (ParentNo + num1);
    }
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
        Parent p, ref;
        p = new Parent();
        Child c = new Child();
        ref = p;
        System.out.println(ref.Add());
        ref = c;
        System.out.println(ref.Add());
    }
}