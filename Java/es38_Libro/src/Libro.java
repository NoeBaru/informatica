public class Libro {
    private int numPagine;

    public Libro(int numPagine) {
        if(numPagine > 0)
            this.numPagine = numPagine;
        else
            this.numPagine = 1; //da mettere il default
    }

    public int getNumPagine() {
        return numPagine;
    }

    public void setNumPagine(int numPagine) {
        this.numPagine = numPagine;
    }
    public void pageMessage(){
        System.out.println("il libro ha: " + numPagine + " pagine");
    }

    @Override
    public String toString() {
        return "numPagine:" + numPagine;
    }

}
