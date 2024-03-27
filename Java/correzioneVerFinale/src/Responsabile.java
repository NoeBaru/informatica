public class Responsabile {
    private String nome;
    private String cognome;
    private String telefono;
    private int anniServizio;

    public Responsabile(String nome, String cognome, String telefono, int anniServizio) {
        this.nome = nome;
        this.cognome = cognome;
        this.telefono = telefono;
        this.anniServizio = anniServizio;
    }

    public void setTelefono(String telefono) {this.telefono = telefono;}
    public void setAnniServizio(int anniServizio) {this.anniServizio = anniServizio;}

    public String getNome() {
        return nome;
    }

    public String getCognome() {
        return cognome;
    }

    public String getTelefono() {
        return telefono;
    }

    public int getAnniServizio() {
        return anniServizio;
    }

    void annoPassato(){
        anniServizio++;
    }

    @Override
    public String toString() {
        return "Responsbile{" +
                "nome='" + nome + '\'' +
                ", cognome='" + cognome + '\'' +
                ", telefono='" + telefono + '\'' +
                ", anniServizio=" + anniServizio +
                '}';
    }
}