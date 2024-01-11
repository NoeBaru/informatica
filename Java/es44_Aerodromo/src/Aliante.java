public class Aliante extends Aereomobile{
    private int aereodinamica; //efficienza aereodinamica

    public Aliante(String sigla, int aereodinamica) {
        super(sigla);
        this.aereodinamica = aereodinamica;
    }

    public int getAereodinamica() {
        return aereodinamica;
    }

    @Override
    public String toString() {
        return super.toString() + "aereodinamica: " + aereodinamica;
    }
}
