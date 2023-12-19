public class Test {
    public static void main(String[] args) {
        Libro l1 = new Libro("harry Potter", "J.K.ROwling", Generi.ROMANZO, 200, 22);
        Libro l2 = new Libro("ciao", "io", Generi.HORROR, 150, 14);
        if (l1.compareTo(l2) == 1){
            System.out.println(l1.getTitolo() + " e' più costoso di " + l2.getTitolo());
        } else if(l1.compareTo(l2) == 0){
            System.out.println(l1.getTitolo() + "" + l2.getTitolo() +  " costano uguali");
        } else{
            System.out.println("'" + l2.getTitolo() + "'" + " e' più costoso di " + "'" + l1.getTitolo() + "'");
        }
        Libreria l = new Libreria("wow", "Cuneo", 100, 2);
        l.add(l1);
        l.add(l2);
        l.statistica();
    }
}
