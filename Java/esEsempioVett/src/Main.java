public class Main {
    public static void main(String[] args) {
        int []vett = new int[5]; //invece che come su c int vett[5]
        System.out.println("vettori");

        System.out.println("\nfor classico: ");
        for (int k = 0; k < vett.length; k++){
            vett[k]++;
            System.out.println(vett[k] + " ");
        }

        int somma = 0;

        System.out.println("\nfor each: ");
        for (int el: vett){
            el++;
            System.out.println(el + " ");
            somma += el;
        }
        System.out.println("somma: " + somma);
    }
}
