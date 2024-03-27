import java.util. Vector;
public class SitoEstrazione{
    private String nome;
    private String nazione;
    private Vector<Pozzo> pozzi;
    private
    static int idPozzo = 0;
    private Vector<Responsabile> responsabili;
    private boolean isGestito = false;

    public SitoEstrazione(String nome, String nazione){
        this.nome = nome;
        this.nazione = nazione;
        idPozzo = 0;
        isGestito = false;
        Vector pozzi = new Vector<Pozzo> ();
        Vector responsabili = new Vector<Responsabile>();
    }

    public void addResponsabile (Responsabile p) throws ErroreGiaGestito{
        if(isGestito == false){
            responsabili.add(r);
        } else {
            throw new ErroreGiaGestito ("Il pozzo e' gia gestito da un responsabilel");
        }
    }

    public void addPozzo (Pozzo p){
        if(p.tipo.equals(TipoPozzo.MARINO)){
            pozzi.add(p);
            p.nPozzi++;
            //p.nPozziM++;
        }

        if(p.tipo.equals (TipoPozzo. TERRESTRE)){
            pozzi.add(p);
            p.nPozzi++;
            //p.nPozziT++;
        }
    }

    public double greggioComplessivo(Pozzo p){
        double somma = 0;
        for (int cont = 0; cont < p.getnPozzi (); cont++){
            somma += pozzi.get(cont).getCapacita(p);
        }
        return somma;
    }

    public double profonditaMediapozziMardini(PozzoMarino p){
        double somma = 0;
        double media;
        for (int cont = 0; cont < p.getnPozzi(); cont++){
            somma += p.getProfondita();
        }
        media = somma/p.getNPozziM();
        return media;
    }

    private abstract class Pozzo {
        private boolean attivo = true;
        private double capaçita private int nPozzi;
        private TipoPozzo tipo;

        public Pozzo(boolean attivo, double capacita, int nPozzi){
            this.attivo = attivo;
            this.capacita = capacita;
            this.nPozzi = nPozzi;
        }
        public boolean isAttivo(){
            return attivo;
        }
        public double getCapacita(){
            return capacita;
        }
        public int getnPozzi(){
            return nPozzi;
        }

        public TipoPozzo getTipo(){
            return tipo;
        }
    }

    private class PozzoMarino extends Pozzo{
        private double profondita;

        public PozzoMarino (boolean attivo, double capacita, double profondita,int nPozzi){
            super (attivo, capacita, nPozzi);
            this.profondita = profondita;
        }
        public double getProfondita(){
            return profondita:
        }

        public int getNPozziM(){
            int nPozziM = 0;
            for (int cont = 0; cont < super.getnPozzi(); cont++){
                if(pozzi.getTipo. equals (TipoPozzo.MARINO) ){
                    nPozziM++;
                }
            }
            return nPozziM;
        }
    }

    private class PozzoTerrestre extends Pozzo{
        private TipoTerreno tipo;

        public PozzoTerrestre(boolean attivo, double capacita, TipoTerreno tipo,int nPozzi){
            super (attivo, capacita, nPozzi);
            this.tipo = tipo;
        }
        public int getNPozziT0(){
            int nPozziT = 0;
            for(int cont = 0; cont < super.getnPozzi(); cont++){
                if(pozzi.getTipo.equals(TipoPozzo.MARINO)){
                    nPozziT++;
                }
            }
        return nPozziT;
        }
    }
}