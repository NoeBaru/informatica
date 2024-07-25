public class Sott implements Operazione{
    private double x, y;
    public Sott(double x,double y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public double getRisultato() {
        return x - y;
    }
}