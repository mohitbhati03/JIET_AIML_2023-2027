class OverloadConstructor {
    int a, b;

    OverloadConstructor() {
        a = b = 1;
    }

    OverloadConstructor(int x, int y) {
        a = x; 
        b = y;
    }

    OverloadConstructor(OverloadConstructor obj) {
        a = obj.a;
        b = obj.b;
    }

    void ShowValues() {
        System.out.println("Data Members are: " + a + " and " + b);
    }
}

class MainClass {
    public static void main(String[] args) {
        OverloadConstructor obj1, obj2, obj3;

        obj1 = new OverloadConstructor(); 
        obj2 = new OverloadConstructor(5, 10);
        obj3 = new OverloadConstructor(obj2);

        obj1.ShowValues();
        obj2.ShowValues();
        obj3.ShowValues();
    }
}