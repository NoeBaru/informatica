public class Test {
    public static void main(String[] args) {
        Animale s = new Scoiattolo("ciao");
        Zoo zoo = new Zoo("Mio", 5);
        zoo.add(new Scoiattolo("Cip"));
        zoo.add(new Scoiattolo("Ciop"));
        zoo.presentatevi();

        Cane c = new Razza1();
        Razza1 r = (Razza1) c; //si
        Razza2 r2 = (Razza2) c; //no c razza1(effettivo) e non Cane(apparente)
    }
}
