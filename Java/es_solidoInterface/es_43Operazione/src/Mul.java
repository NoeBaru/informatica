public class Mul implements Operazione{
    private double x, y;
    public Mul(double x,double y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public double getRisultato() {
        return x * y;
    }
}
