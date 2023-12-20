/*
es: esEccezioni
text: se si vuole mandare un messaggio di valore errato inserito o altri errori,si sollevano eccezioni esistenti o meno e si gestiscono
*/
public class Test {
    public static void main(String[] args) {
        try{ //per gestire le eccezioni
            Cerchio c = new Cerchio(-1);
        } catch (IllegalArgumentException e){ //catturato l'eccezione sollevata
            System.out.println(e.getMessage());
        }
        try {
            CerchioIOException c1 = new CerchioIOException(-1); //controllato
        } catch (ValoreNonValido e) {
            System.out.println(e.getMessage());
        } finally{ //viene eseguito comunque
            System.out.println("passa di qua!");
        }
        CerchioRuntimeException c2 = new CerchioRuntimeException(-1); //NON controllato
    }
}
