public class LavoratoreConStraordinariPagati extends Lavoratore{
    private int oreStraordinario;
    private final static float retribuzioneOraria = 10.0f;
    public LavoratoreConStraordinariPagati (String nome, int livello, int numH){
        super(nome, livello);
        oreStraordinario = numH;
    }
    private int getOreStraordinario(){return oreStraordinario;}
    private void setOreStraordinario(int numH){oreStraordinario = numH;}
}
