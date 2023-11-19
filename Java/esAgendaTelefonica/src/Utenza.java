public class Utenza {
    private String nome;
    private String cognome;
    private String numero;
    private String email;

    public Utenza(String nome, String cognome, String numero, String email) {
        this.nome = nome;
        this.cognome = cognome;
        this.numero = numero;
        this.email = email;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCognome() {
        return cognome;
    }

    public void setCognome(String cognome) {
        this.cognome = cognome;
    }

    public String getNumero() {
        return numero;
    }

    public void setNumero(String numero) {
        this.numero = numero;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String toString() {
        return "Nome: " + nome + ", Cognome: " + cognome + ", Telefono: " + numero + ", Email: " + email;
    }
}
