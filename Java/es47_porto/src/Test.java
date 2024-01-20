public class Test {
    public static void main(String[] args) {
        Barca b = new Barca("sciolla", "italiana", "prandi", 10, 50);
        Molo m = new Molo(20, 30, 40);
        Molo m1 = new Molo(30, 50, 60);
        Porto p = new Porto("armando", "cuneo", m);

        p.add(m1);
        System.out.println(p.toString());
        System.out.println(p.getPostiLiberi(b));
    }
}