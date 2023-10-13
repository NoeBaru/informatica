public class Test { //utilizzata dal mostro
    public static void main(String[] args) { //pswm e crea il main
        Mostro mio; //occupa lo spazio di una variabile di tipo oggetto
        mio = new Mostro("Noemi", 10, 100); ///metodo costruttore, ho creato il mostro che occupa spazio in memoria, è quello predefinito
        //scrivo sout e tabbo. println va a capo (lo \n funziona anche), print scrive di seguito
        System.out.println("il mio mostro ora è " + mio.toString()); //si aspetta una stringa, .toString converte mostro in stringa
        //in C avremmo scritto str = toString(mio); qui invece s = mio.toString();

    }
}
