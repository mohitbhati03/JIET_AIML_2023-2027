class Parent {
    private int ParentNo;
    public int num1;

    Parent() {
        ParentNo = 1;
        num1 = 10;
    }

    int Add_Parent() {
        return (ParentNo + num1);
    }
}

class Child extends Parent {
    private int ChildNo;

    Child() {
        ChildNo = 2;
    }

    int Add_Child() {
        return (ChildNo + Add_Parent());
    }
}

class GrandChild1 extends Child {
    private int GrandChildNo1;

    GrandChild1() {
        GrandChildNo1 = 13;
    }

    int Add_GrandChild1() {
        return (GrandChildNo1 + Add_Child());
    }
}

class GrandChild2 extends Child {
    private int GrandChildNo2;

    GrandChild2() {
        GrandChildNo2 = 31;
    }

    int Add_GrandChild2() {
        return (GrandChildNo2 + Add_Child());
    }
}

class MainClass {
    public static void main(String args[]) {
        GrandChild1 g1 = new GrandChild1();
        GrandChild2 g2 = new GrandChild2();
        System.out.println("Sum of parent, child and grandchild class numbers = " +
            g1.Add_GrandChild1() + " and " + g2.Add_GrandChild2());
    }
}