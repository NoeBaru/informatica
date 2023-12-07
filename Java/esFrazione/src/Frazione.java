public class Frazione {
    private int denominatore;
    private int numeratore;
    private char segno;
    private static final char DEF_SEGNO = '+';
    private static final char DEF_NUM = 0;
    private static final char DEF_DEN = 1;

    public Frazione(){
        this(DEF_DEN, DEF_NUM, DEF_SEGNO);
    }
    public Frazione(char segno, int numeratore){
        this(DEF_DEN, numeratore, segno); //invoca il costruttore
    }
    public Frazione(char segno, int num, int den){
        if(den > 0) {
            this.denominatore = den;
        } else{
            this.denominatore = DEF_DEN;
        }
        if(num > 0) {
            this.numeratore = num;
        } else{
            this.numeratore = DEF_NUM;
        }
        if(segno == '') {
            this.segno =DEF_SEGNO;
        }else{
            this.segno = segno;
        }

    }
    public float getValore(){
        float valore;
        valore = (float)numeratore/denominatore;
        if(segno == '-'){
            valore *= -1;
        }
        return valore;
    }
    public char getSegno(){return segno;}
    public int getNumeratore(){return numeratore;}
    public int getDenominatore(){return denominatore;}
    public boolean equals(Frazione f){
        /*boolean uguale = false;
        if(getValore() == f.getValore()){
            uguale = true;
        }
        return valore */
        return getValore() == f.getValore();
    }
    public String toString(){
        return "numeratore: " + numeratore + "denominatore: " + denominatore + "Segno: " + segno + "valore: ";
    }
}
