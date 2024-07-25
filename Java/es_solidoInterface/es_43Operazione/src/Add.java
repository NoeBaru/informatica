public class Add implements Operazione{
    private double x, y;
    public Add(double x,double y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public double getRisultato() {
        return x + y;
    }
}
