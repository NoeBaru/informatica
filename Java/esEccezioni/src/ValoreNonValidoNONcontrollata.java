public class ValoreNonValidoNONcontrollata extends RuntimeException { //NON controllata
    public ValoreNonValidoNONcontrollata(){ //messaggio predefinito
        super("Valore non valido!");
    }
    public ValoreNonValidoNONcontrollata(String errore) {
        super(errore); //messaggio di errore personalizzato
    }
}
