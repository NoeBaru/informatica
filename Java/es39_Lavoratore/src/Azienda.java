import java.util.Vector;

public class Azienda {
    private String nome;
    private String indirizzo;
    private Vector<Lavoratore> lavoratori; //Vector<Tipo> nome;

    public Azienda(String nome, String indirizzo) {
        this.nome = nome;
        this.indirizzo = indirizzo;
        lavoratori = new Vector<Lavoratore>(); //Vector<Tipo> nome;
    }

    public void add(Lavoratore l){
        if(l != null)
            lavoratori.add(l);
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getIndirizzo() {
        return indirizzo;
    }

    public void setIndirizzo(String indirizzo) {
        this.indirizzo = indirizzo;
    }

    public Vector<Lavoratore> getLavoratori() {
        return lavoratori;
    }

    public void setLavoratori(Vector<Lavoratore> lavoratori) {
        this.lavoratori = lavoratori;
    }

    @Override
    public String toString() {
        return super.toString() + "nome: " + nome + " indirizzo: " + indirizzo;
    }
}
