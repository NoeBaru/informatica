public class Responsabile{
    private String nome;
    private String cognome;
    private int telefono;
    private int anniservizio;

    public Responsabile(String nome, String cognome, int telefono, int anniServizio) {
        this.nome = nome;
        this.cognome = cognome;
        this.telefono = telefono;
        this.anniServizio = anniServizio;
    }
    public void setTelefono(int telefono){
        this.telefono = telefono;
    }
    public void setAnniServizio(int anniServizio){
        this.anniServizio = anniServizio;
    }
}