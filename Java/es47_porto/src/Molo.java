import java.util.Vector;

public class Molo {
    private double tariffa;
    private int progPosto;
    private int indice;
    private final float MAXlUNG;
    private final float MAXLARG;
    private Vector<PostoBarca> vPostiBarca;

    public Molo(double tariffa, float MAXlUNG, float MAXLARG) {
        this.tariffa = tariffa;
        this.MAXlUNG = MAXlUNG;
        this.MAXLARG = MAXLARG;
        indice = 0;
        vPostiBarca = new Vector<PostoBarca>();
        progPosto = 0;
        addPosto();
    }

    public double getTariffa() {
        return tariffa;
    }

    public int getIndice() {
        return indice;
    }

    public float getMAXlUNG() {
        return MAXlUNG;
    }

    public float getMAXLARG() {
        return MAXLARG;
    }

    public void setTariffa(double tariffa) {
        this.tariffa = tariffa;
    }

    public void setIndice(int indice) {
        this.indice = indice;
    }
    public void addPosto(){
       vPostiBarca.add(new PostoBarca());
    }
    public void passatoUnGiorno(){
        for(PostoBarca p: vPostiBarca){
            if(p.isOccupato())
                p.setNumGiorni(p.getNumGiorni() - 1);
        }
    }
    public Vector<PostoBarca> getvPostiBarca(){
        return vPostiBarca;
    }
    public String getPostiLiberi(){
        String str = "";
        for(PostoBarca p: vPostiBarca){
            if(!p.isOccupato()){
                str += "Molo: " + indice + " Posto: " + p.getIndice();
            }
        }
        return str;
    }
    @Override
    public String toString() {
        String str = "";
        for(int k = 0; k < vPostiBarca.size(); k++){
            str += vPostiBarca.get(k).toString() + "\n";
        }
        return "Molo{" +
                "tariffa=" + tariffa +
                ", indice=" + indice +
                ", MAXlUNG=" + MAXlUNG +
                ", MAXLARG=" + MAXLARG +
                str +'}';
    }
    private class PostoBarca{
        private int indice;
        private int numGiorni;
        private Barca barca;

        public PostoBarca() {
            this.indice = progPosto;
            progPosto++;
            this.numGiorni = 0; //libero
            this.barca = null;
        }

        public int getIndice() {
            return indice;
        }
        public int getNumGiorni() {
            return numGiorni;
        }
        public Barca getBarca() {
            return barca;
        }

        public void setNumGiorni(int numGiorni) {
            this.numGiorni = numGiorni;
        }

        public boolean isOccupato(){
            return barca != null;
        }
        public double barcaIn(Barca b, int numGiorni){
            if (!isOccupato() && b.getLUNG() <= MAXlUNG && b.getLARG() <= MAXLARG){
                this.barca = b;
                this.numGiorni = numGiorni;
            } else {
                //eccezione
            }
            return tariffa * numGiorni;
        }
        public void barcaOut(){
            this.numGiorni = 0;
            this.barca = null;
        }

        @Override
        public String toString() {
            return "PostoBarca{" +
                    "indice=" + indice +
                    ", numGiorni=" + numGiorni +
                    ", barca=" + barca +
                    '}';
        }
    }
}
