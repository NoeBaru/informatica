public class Frazione {
    private int denominatore;
    private int numeratore;
    private char segno;

    public Frazione(){
        this.denominatore = 0;
        this.numeratore = 0;
        this.segno = segno;
    }
    public Frazione(char segno, int numeratore){
        this.segno = segno;
        this.numeratore = numeratore;
    }
    public Frazione(char segno, int num, int den){
        this.denominatore = den;
        this.numeratore = num;
        this.segno = segno;
    }
    public float getValore(){
        float valore;
        return valore;
    }
    public boolean equals(Frazione f){
        boolean uguale = false;
        if(frazioni[nFraz].getValore().equals.(f)){
            uguale = true;
        }
        return uguale;
    }
    public String toString(){
        return "numeratore: " + numeratore + "denominatore: " + dneominatore + "Segno: " + segno + "valore: " + getValore();
    }
}
