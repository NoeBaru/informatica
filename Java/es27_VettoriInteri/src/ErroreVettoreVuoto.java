public class ErroreVettoreVuoto extends RuntimeException { //non controllata
    public ErroreVettoreVuoto() {
        super("Il vettore e' vuoto!");
    }

    public ErroreVettoreVuoto(String message) {
        super(message);
    }
}
