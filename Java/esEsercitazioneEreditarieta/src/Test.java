public class Test {
    public static void main(String[] args) {
        Persona p1 = new Persona()("Noemi, Baruffolo");
        Studente s1 = new Studente("Martina", "Baruffolo", "matricola");
        Docente d1 = new Docente("Anna", "Baruffolo");

        ElencoPersone e1 = new ElencoPersone(10);
        e1.add(p1);
        e1.add(s1);
        e1.add(d1);

        System.out.println(e1.toString());
    }
}
