public class Test {
    public static void main(String[] args) {
        Lavoratore l1 = new Lavoratore("Luigi", 10);
        System.out.println(l1.toString());
        LavoratoreConStraordinariPagati l2 = new LavoratoreConStraordinariPagati("Matteo", 1, 2);
    }
}
