import Solido.*;

public class Test {
    public static void main(String[] args) {
        Solido[] solidi = new Solido[4];
        Sfera s1 = new Sfera(20, 5), s2 = new Sfera(10, 3);
        Cubo c1 = new Cubo(30, 10), c2 = new Cubo(15, -3);
        solidi[0] = s1;
        solidi[1] = s2;
        solidi[2] = c1;
        solidi[3] = c2;
        for(int k = 0; k < 4; k++){
            System.out.println(solidi[k].toString());
        }
    }
}