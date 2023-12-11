public class Test {
    public static void main(String[] args) {
        LavoratoreConStraordinariPagati l1 = new LavoratoreConStraordinariPagati("Luigi", 10, 10);
        l1.setStipendio(1100);
        System.out.println(l1.getStipendio());
        l1.setRetribuzioneOraria(20.0f);
        l1.setStipendio(1100);
        LavoratoreConStraordinariPagati l2 = new LavoratoreConStraordinariPagati("Matteo", 5, 10);
        System.out.println(l1.getStipendio());
    }
}
