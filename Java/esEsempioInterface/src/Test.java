import java.util.Vector;

public class Test {
    public static void main(String[] args) {
        Vector <Solido> solidi = new Vector <Solido>();

        solidi.add(new Cubo(2.0, 4.0));
        solidi.add(new Sfera(2.0, 3.0));

        for(int cont = 0; cont < solidi.size(); cont++){
            System.out.println("Solido: " + solidi.get(cont).getPeso());
            System.out.println("Cubo: " + );
            System.out.println("Sfera: " + );
        }
    }
}
