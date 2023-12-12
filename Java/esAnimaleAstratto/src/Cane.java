public class Cane extends Animale{
    public Cane(String nome) {
        super(nome);
    }

    @Override
    public void verso() {
        System.out.print("BAU BAU");
    }
}
