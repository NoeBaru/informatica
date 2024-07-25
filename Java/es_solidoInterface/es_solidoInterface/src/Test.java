import java.util.Vector;

public class Test {
    public static void main(String[] args) {
        Vector<Solido1> solidi = new Vector<Solido1>();

        solidi.add(new Sfera(5, 3));
        solidi.add(new Cubo(6, 5));

        for(int k = 0; k < solidi.size(); k ++){
            System.out.println(solidi.get(k).toString());
        }
    }
}
