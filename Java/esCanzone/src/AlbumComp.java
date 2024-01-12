import java.util.Vector;
public class AlbumComp {
    private String titolo;
    private Vector<Canzone> brani;

    public AlbumComp(String titolo, String titoloCanzone, String autore, int durataSec, Canzone brani) {
        this.titolo = titolo;
        this.brani = new Vector<>();
        addCanzone(titoloCanzone, autore, durataSec);
    }
    public void addCanzone(Canzone canzone){
        this.brani.add(new CanzoneComp(titolo, autore, durataSec));
    }
    private class CanzoneComp{

    }

    public String getTitolo() {
        return titolo;
    }

    public Vector<Canzone> getBrani() {
        return brani;
    }

    @Override
    public String toString() {
        return " titolo: " + titolo + '\'' +
                " brani: " + brani;
    }
}
