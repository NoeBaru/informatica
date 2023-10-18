public class Test { //utilizzata dal mostro
    public static void main(String[] args) { //pswm e crea il main
        Mostro mio; //occupa lo spazio di una variabile di tipo oggetto
        mio = new Mostro("Noemi", 10, 100, 6); ///metodo costruttore, ho creato il mostro che occupa spazio in memoria, è quello predefinito
        //scrivo sout e tabbo. println va a capo (lo \n funziona anche), print scrive di seguito
        System.out.println("il mio mostro ora è " + mio.toString()); //si aspetta una stringa, .toString converte mostro in stringa
        //in C avremmo scritto str = toString(mio); qui invece s = mio.toString();

        //Mostro tuo = mio; //puntano alla stessa aria, copia il riferimento o il valore della stessa area

        //mio.setVita(mio.getVita() +1);

        Mostro tuo = new Mostro("Gabriele", 8);
        System.out.println("il mio mostro ora è " + mio.toString());
        System.out.println("il tuo mostro ora è " + tuo.toString());

        mio.gioca(tuo);


    }
}
