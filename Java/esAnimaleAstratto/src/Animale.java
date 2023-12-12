public abstract class Animale {
    private String nome;
    public Animale(String nome){this.nome = nome;}
    public String getNome(){return nome;}
    public abstract void verso(); //senza corpo/vuoto, quindi astratto
    public void miPresento(){
        System.out.print("ciao, sono " + nome + " faccio "); // senza ln non va a capo almeno
        verso();
    }
}

