import java.io.IOException;

public class ErroreValoreNonValido extends IOException {
    public ErroreValoreNonValido() {
        super("valore non valido");
    }

    public ErroreValoreNonValido(String message) {
        super(message);
    }
}
