import java.util.Vector;
public class Album{
    private String titolo;
    private Vector<Canzone> brani;
    private int numCanzoni;

    public Album(String titolo, String autore, int durataSec) {
        this.titolo = titolo;
        this.brani = new Vector<>();
        addCanzone(brani);
    }
    public void addCanzone(Canzone canzone){
        if(canzone != null){
            brani.add(canzone);
        }
    }

    @Override
    public String toString() {
        return "titolo: " + titolo + '\'' +
                "brani: " + brani;
    }
}
