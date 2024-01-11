public class Aereomobile {
    private String sigla;

    public Aereomobile(String sigla) {
        this.sigla = sigla;
    }

    public String getSigla() {
        return sigla;
    }
    public boolean eLoStesso(String s){
        boolean uguali = false;
        if(s.equals(sigla){
            uguali = true;
        }
        return uguali;
    }

    @Override
    public String toString() {
        return "sigla: " + sigla;
    }
}
