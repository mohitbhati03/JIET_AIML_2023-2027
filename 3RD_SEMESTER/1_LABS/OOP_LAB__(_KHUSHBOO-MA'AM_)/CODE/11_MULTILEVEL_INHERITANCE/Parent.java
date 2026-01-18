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

class GrandChild extends Child {
    private int GrandChildNo;

    GrandChild() {
        GrandChildNo = 3;
    }

    int Add_GrandChild() {
        return (GrandChildNo + Add_Child());
    }
}

class MainClass {
    public static void main(String args[]) {
        GrandChild g = new GrandChild();
        System.out.println("Sum of parent, child and grandchild class numbers = " +
            g.Add_GrandChild());
    }
}