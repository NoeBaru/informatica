import java.io.IOException;
public class ValoreNonValido extends IOException {
    public ValoreNonValido(){
        super("Errore valore non valido");
    }
    public ValoreNonValido(String message){
        super((message));
    }
}
