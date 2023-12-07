public class Vocabolario extends Libro{
    private int numDefinizioni;

    public Vocabolario(int numPagine, int numDefinizioni) {
        super(numPagine);
        this.numDefinizioni = numDefinizioni;
    }

    public int getNumDefinizioni() {
        return numDefinizioni;
    }
    public void definitionMessage(){
        pageMessage();
        System.out.println("Il vocabolario ha: " + numDefinizioni + " definizioni");
    }

    @Override
    public String toString() {
        return super.toString() + " numDefinizioni: " + numDefinizioni;
    }
}
