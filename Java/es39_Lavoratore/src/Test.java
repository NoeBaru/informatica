public class Test {
    public static void main(String[] args) {
        LavoratoreConStraordinariPagati l1 = new LavoratoreConStraordinariPagati("Luigi", 10, 10);
        l1.setStipendio(1100);
        System.out.println(l1.getStipendio());
        l1.setRetribuzioneOraria(20.0f);
        l1.setStipendio(1100);
        LavoratoreConStraordinariPagati l2 = new LavoratoreConStraordinariPagati("Matteo", 5, 10);
        System.out.println(l1.getStipendio());
        Lavoratore l1, l2;
        LavoratoreConStraordinariPagati lv1, lv2;
        lv1 = new LavoratoreConStraordinariPagati("ciao", 4, 2400);
        l2 = new Lavoratore("Giuseppe", 7);
        l2.setStipendio( 2333);
        //DOWN casting non possibile lv2 = new Lavoratore("Mario", 1);
        l1 = lv1; //up casting sempre possibile, come facesse così: l1 = (Lavoratore)lv1
        //DOWN casting: lv2 = (LavoratoreConStraordinariPagati)l2;
        lv1 = (LavoratoreConStraordinariPagati)l1;
        Azienda a1 = new Azienda("Baruffolo", "ViaRoma");
        a1.add(l1);
        a1.add(lv1);
        System.out.println(a1.toString());
    }
}
