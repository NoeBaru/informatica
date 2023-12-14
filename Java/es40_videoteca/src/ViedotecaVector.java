import java.util.Vector;

public class ViedotecaVector {
    private String nome;
    private String indirizzo;
    private Vector<Cassetta> cassette; //Vector<Tipo> nome;

    public ViedotecaVector(String nome, String indirizzo) {
        this.nome = nome;
        this.indirizzo = indirizzo;
        cassette = new Vector<Cassetta>(); //Vector<Tipo> nome;
    }
    public void add(Cassetta c){
         if(c != null)
            cassette.add(c);
    }

    public double getValoreNegozio(){
        double tot = 0.0;
        for(int cont = 0; cont < cassette.size(); cont++){
            if(cassette.elementAt(cont) instanceof DVD) {
                tot +=  DVD.getPrezzo()//down casting, fattibile anche così ((DVD) cassette.elementAt(cont)).getPrezzo()
                        * cassette.elementAt(cont).getnCopie();
            }else{
                tot +=  CD.getPrezzo()//down casting, fattibile anche così  ((CD) cassette.elementAt(cont)).getPrezzo()
                        * cassette.elementAt(cont).getnCopie();
            }
        }
        return tot;
    }
    private int cercaCodice(int cod){
        int cont = 0;
        int tro = -1;
        while(tro == -1 && cont < cassette.size()){
            if(cassette.get(cont).getMioCodice() == cod)
                tro = cont;
            cont++;
        }
        return tro;
    }
    public void compro(int cod){
        int tro = cercaCodice(cod);
        if(tro != -1){
            cassette.get(tro).setnCopie(cassette.get(tro).getnCopie() + 1);
        }
    }
    public void vendo(int cod){
        int tro = cercaCodice(cod);
        if(tro != -1){
            cassette.get(tro).setnCopie(cassette.get(tro).getnCopie() - 1);
        }
    }
}
