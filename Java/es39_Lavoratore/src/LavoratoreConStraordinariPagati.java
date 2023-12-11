public class LavoratoreConStraordinariPagati extends Lavoratore{
    private int oreStraordinario;
    private static float retribuzioneOraria = 10.0f;
    public LavoratoreConStraordinariPagati (String nome, int livello, int numH){
        super(nome, livello);
        if(numH > 0)
            oreStraordinario = numH;
    }
    private int getOreStraordinario(){return oreStraordinario;}
    private void setOreStraordinario(int numH){
        if(numH > 0)
            oreStraordinario = numH;
    }
    public float getStipendio() {
        return super.getStipendio() + retribuzioneOraria * oreStraordinario;
    }

    public static void setRetribuzioneOraria(float retribuzioneOraria) {
        LavoratoreConStraordinariPagati.retribuzioneOraria = retribuzioneOraria;
    }
}
