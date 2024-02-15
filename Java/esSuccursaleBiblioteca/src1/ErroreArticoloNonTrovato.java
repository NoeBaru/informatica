import java.io.IOException;

public class ErroreArticoloNonTrovato extends IOException { //controllata
    public ErroreArticoloNonTrovato(){ //messaggio predefinito
        super("Articolo non trovato!");
    }
    public ErroreArticoloNonTrovato(String errore) {
        super(errore); //messaggio di errore personalizzato
    }
}