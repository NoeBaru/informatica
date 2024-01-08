public class TestFinale {
    public static void main(String[] args) {
        VettoriInteri v = new VettoriInteri("1|2|3|");
        System.out.println(v.toString());
        int min = v.minimo();
        System.out.println("Il minimo e': " + min);
        int pos = v.cercaElemento(2);
        if(pos != -1){
            System.out.println("Elemento trovato in pos: " + pos + "!");
        } else {
            System.out.println("Elemento non trovato! ");
        }

        try {
            v.eliminaElemento(1);
            v.add(5);
        } catch (ErroreElementoInesistente | ErroreVettorePieno e) {
            System.out.println(e.getMessage());
        }

        System.out.println(v);
    }
}
