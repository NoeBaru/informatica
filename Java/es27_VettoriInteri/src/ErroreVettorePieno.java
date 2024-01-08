import java.io.IOException;
public class ErroreVettorePieno extends IOException { //controllata
    public ErroreVettorePieno() {
        super("Il vettore e' pieno!");
    }

    public ErroreVettorePieno(String message) {
        super(message);
    }
}
