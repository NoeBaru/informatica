import java.io.IOException;

public class ValoreNonValido extends IOException { //controllata
    public ValoreNonValido(){ //messaggio predefinito
        super("Valore non valido!");
    }
    public ValoreNonValido(String errore) {
        super(errore); //messaggio di errore personalizzato
    }
}
