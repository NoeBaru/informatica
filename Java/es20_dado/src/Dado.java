public class Dado {
    private int num_facce;
    private int num_uscito;
    private static final int FACCE_DEFAULT = 6;

    public Dado(int num_facce){
        if(num_facce < 2){
            this.num_facce = FACCE_DEFAULT;
        }else{
            this.num_facce = num_facce;
        }
    }
    public Dado(){
        this.num_facce = FACCE_DEFAULT;

    }
    public int lanciaDado() {
        this.num_uscito = (int) (Math.random() * this.num_facce) + 1;
        return this.num_uscito;
    }
    public int getLancio() {
        return this.num_uscito;
    }
}
