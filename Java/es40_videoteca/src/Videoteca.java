public class Videoteca {
    private String nome;
    private String titolo;

    public Videoteca(String nome, String indirizzo) {
        this.nome = nome;
        this.indirizzo = indirizzo;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }
}
