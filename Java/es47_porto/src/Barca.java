public class Barca {
    private String nome;
    private String nazionalita;
    private String proprietario;
    private final float LUNG;
    private final float LARG;
    
    public Barca(String nome, String nazionalita, 
    String proprietario, float lUNG, float lARG) throws ValoreNonValido {
        this.nome = nome;
        this.nazionalita = nazionalita;
        this.proprietario = proprietario;
        if(lUNG > 0){
            LUNG = lUNG;
        }
        else{
            throw new ValoreNonValido("la lunghezza deve essere positiva");
        }
        if(lARG > 0){
            LARG = lARG;
        }
        else{
            throw new ValoreNonValido("la larghezza deve essere positiva");
        }
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public void setProprietario(String proprietario) {
        this.proprietario = proprietario;
    }

    public String getNome() {
        return nome;
    }

    public String getNazionalita() {
        return nazionalita;
    }

    public String getProprietario() {
        return proprietario;
    }

    public float getLUNG() {
        return LUNG;
    }

    public float getLARG() {
        return LARG;
    }
}
