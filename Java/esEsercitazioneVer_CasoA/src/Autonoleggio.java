public class Autonoleggio {
    private String nome;
    private String indirizzo;
    private Responsabile responsabile;
    private Veicolo[] veicoli;
    public final int MAX_VEICOLI = 2000;

    public Autonoleggio(){

    }
    public Autonoleggio(String nome, String indirizzo, Responsabile responsabile){
        this.nome = nome;
        this.indirizzo = indirizzo;
    }
    public boolean aggiungiVeicolo(Veicolo veicolo) {
        if(veicoli.length != null){
            if(veicolo < MAX_VEICOLI){
                this.veicoli[veicoli.length] = veicolo;
            }
        }
        return;
    }
    public Veicolo trovaVeicolo(String targa) {
        for(int cont = 0; cont < veicoli.length; cont ++){
            if((veicoli[cont].getTarga().equals(targa))){
                veicoli[cont].toString();
            }
        }
        return;
    }
    public Veicolo[] trovaTuttiIVeicoli(){
        return;
    }
    public String toString(){
        String s = "";
        return s;
    }

    public String toString(){
        String s = "";
        return s;
    }
}
