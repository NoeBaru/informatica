public class Proprietario {
    private String nome;
    public Proprietario(String nome){
        if (nome != null){
            this.nome = nome;
        }else{
            System.out.println("Inserisci un nome corretto!");
        }
    }
    public String getNome(){
        return nome;
    }
    public String toString(){
        return "Nome: " + nome;
    }
}