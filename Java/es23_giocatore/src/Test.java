public class Test {
    //modifico test e aggiungo else a controllo età
    public static void main(String[] args) {
        Giocatore g1 = new Giocatore("Luca", 17, Ruolo.BATTITORE);
        Giocatore g2 = new Giocatore("Giu", 0, 0, Ruolo.PRIMA_BASE);
        System.out.println(g1.getNome());
        g2.setEta(g2.getEta() + 1);
        System.out.println(g2.getEta());
        System.out.println(g1.toString());
        System.out.println(g2.toString());
        Squadra s1 = new Squadra("Boves");
        s1.addGiocatore(g1);
        s1.addGiocatore(g2);
        s1.setPunteggio("Luca",15);
        System.out.println(s1.toString());
    }
}