public class Carburante {
    public float prezzo;
    public String tipo = ["benzina", "diesel", "GPL", "metano"];
    public final int MAX = 10;
    public Carburante(){
        for(int cont = 0; cont < MAX; cont++) {
            if (tipo[cont] == "benzina") {
                prezzo = 1.5;
            }
        }
    }
    public Carburante(float prezzo){

    }
    private void setPrezzo(){

    }
    public void setTipo(){

    }
    private float getPrezzo(){

    }
    private String etTipo(){

    }
    private boolean equals(char carburante){

    }
    private String toString(){

    }
}
