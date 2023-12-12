public class Scoiattolo extends Animale{
    public Scoiattolo(String nome) {
        super(nome);
    }

    @Override
    public void verso() {
        System.out.print("SQUIT SQUIT");
    }
}
