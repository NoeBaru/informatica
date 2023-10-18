public class Mostro {
    private String nome;
    private int vita;
    private int forza;

    private static final int MIN_VITA = 0;
    private static final int MAX_VITA = 100;
    private static final int MIN_FORZA = 5;
    private static final int MAX_FORZA = 10;
    private final int FACCE;
    private final static int DEFAULT_FACCE = 6;

    public Mostro(String nome, int forza, int vita, int facce){
        this.nome = nome; //this rappresenta l'oggetto su cui si sta applicando il metodo
        //operatore ternario y = (x > 0)?5:10; confronta quello che c'è nelle parentesi
        FACCE = (facce >= DEFAULT_FACCE)? facce : DEFAULT_FACCE; //se è vero fa come se facessimo così:
        /*if(facce >= DEFAULT_FACCE) {
            FACCE = facce;
        }else{
            FACCE = DEFAULT_FACCE;
        }
        */
        if(forza >= MIN_FORZA) {
            this.forza = forza;
        } else if (forza < MIN_FORZA) {
            this.forza = MIN_FORZA;
        } else if(forza > MAX_FORZA) {
            this.forza = MAX_FORZA;
        }

        if(vita >= MIN_VITA) {
            this.vita = vita;
        } else if (vita < MIN_VITA) {
            this.vita = MIN_VITA;
        } else if(vita > MAX_VITA) {
            this.vita = MAX_VITA;
        }
    }

    public Mostro(String nome, int facce){ //passando solo il nome, gli altri parametri sono casuali
        this.nome = nome;
        FACCE = (facce >= DEFAULT_FACCE)? facce : DEFAULT_FACCE; //se è vero fa come se facessimo così:

        this.vita = (int)(Math.random()* (MAX_VITA - MIN_VITA + 1)) + MIN_VITA; //genera da 1 a 6
        this.forza = (int)(Math.random()* (MAX_VITA - MIN_VITA + 1)) + MIN_FORZA; // genera da 5 a 10

    }
    public String toString() { //over reading, riscrittura di un metodo che già esiste
    return nome + ": forza = " + forza + ", vita = " + vita + " dado da = " + FACCE; //restituisce nome, vita e forza del mostro
    }

    public int getVita(){ //restituisce le vita perché get prende
        return vita;
    }

    public int getForza(){ //restituisce le forza perché get prende
        return forza;
    }

    public String getNome(){
        return nome;
    }
    public void setVita(int vita){ //restituisce le vita perché get prende
        if(vita >= MIN_VITA && vita <= MAX_VITA) {
            this.vita = vita;
        } else if (vita < MIN_VITA) {
            this.vita = MIN_VITA;
        } else if(vita > MAX_VITA) {
            this.vita = MAX_VITA;
        }
    }

    public void setForza(int forza){ //restituisce le vita perché get prende
        if(forza >= MIN_FORZA) {
            this.forza = forza;
        } else if (forza < MIN_FORZA) {
            this.forza = MIN_FORZA;
        } else if(forza > MAX_FORZA) {
            this.forza = MAX_FORZA;
        }
    }

    private int getLancio(){
        return (int)(Math.random()* FACCE )+ 1; //genera da 1 a 6
    }

    public void attaccatoDa(Mostro m){
        int dado = getLancio();
        System.out.println(">>>" + dado);
        setVita(vita - dado * m.getForza());
    }

    public void gioca(Mostro m){
        while(vita > 0 && m.getVita() > 0){
            attaccatoDa(m);
            System.out.println(this);

            if(this.vita > 0) {
                m.attaccatoDa(this);
                System.out.println(m);
            }
            System.out.print("Ha vinto " + m.getNome());

            if(vita == 0){
                System.out.println(m.getNome());
            } else{
                System.out.println(nome);
            }
        }
    }
}
