public class Arma {
    private String nome;
    private int potenza;
    private int percRIcarica;

    public Arma(String nome, int potenza, int percRIcarica) {
        this.nome = nome;
        this.potenza = potenza;
        this.percRIcarica = percRIcarica;
    }

    public String getNome() {
        return nome;
    }

    public int getPotenza() {
        return potenza;
    }

    public int getPercRIcarica() {
        return percRIcarica;
    }
}
