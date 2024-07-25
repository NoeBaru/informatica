public class Test {
    public static void main(String[] args) {
        Solido[] solidi = new Solido[4];
        solidi[0] = new Cubo(10, 3);
        solidi[1] = new Cubo(20, 5);
        solidi[2] = new Sfera(30, 7);
        solidi[3] = new Sfera(40, 9);


        System.out.println("Caratteristiche dei solidi:\n");
        for (int k = 0; k < 4; k++) {
            System.out.println(solidi[k]);
            System.out.println("\n");
        }
    }
}