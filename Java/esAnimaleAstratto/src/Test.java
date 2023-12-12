public class Test {
    public static void main(String[] args) {
        Zoo zoo = new Zoo("Mio", 5);
        zoo.add(new Scoiattolo("Cip"));
        zoo.add(new Scoiattolo("Ciop"));
        zoo.presentatevi();
    }
}
