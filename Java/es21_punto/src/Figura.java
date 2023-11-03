public class Figura {
    public String nome;
    public int numVertici;
    public final int TOT_VERTICI;
    public Punto[] vPunti; //vettore di punti

    public Figura(String nome, int numVertici) {
        this.nome = nome;
        if (numVertici > 0) {
            TOT_VERTICI = numVertici;
        } else {
            TOT_VERTICI = 1;
        }
        vPunti = new Punto[TOT_VERTICI];
        this.numVertici = 0;
    }

    public void add(Punto p) {
        if (p != null && numVertici < TOT_VERTICI) {
            vPunti[numVertici] = p;
            numVertici++;
        }
    }

    public int getNumVertici() {
        return numVertici;
    }

    public String getNome() {
        return nome;
    }

    public Punto[] getVertici() {
        return vPunti;
    }

    public float getPerimetro() {
        float perim = 0;
        if (numVertici == TOT_VERTICI) {
            for (int cont = 0; cont < numVertici - 1; cont++) {
                perim += vPunti[cont].getDistanza(vPunti[cont + 1]); //distanza punto corrente con punto successivo
            }
            if(numVertici > 2) { //se non è un segmento o un punto, ma è un'altra figura qualsiasi
                perim += vPunti[0].getDistanza(vPunti[numVertici - 1]); //NON CONT errore logico
            }
        }
        return perim;
    }

    public String toString() {
        String s = "";
        for (int cont = 0; cont < numVertici; cont++) {
            s += vPunti[cont].toString() + " ";
        }
        return s;
    }
}
