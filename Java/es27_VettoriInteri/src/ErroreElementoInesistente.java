import java.io.IOException;

public class ErroreElementoInesistente extends IOException { //controllata
    public ErroreElementoInesistente() {
        super("L'elemento e' inesistente!");
    }

    public ErroreElementoInesistente(String message) {
        super(message);
    }
}
