public class ErroreUtenteGiaPresente extends RuntimeException { //NON controllata
    public ErroreUtenteGiaPresente(){ //messaggio predefinito
        super("Utente gia' prsente!");
    }
    public ErroreUtenteGiaPresente(String errore) {
        super(errore); //messaggio di errore personalizzato
    }
}