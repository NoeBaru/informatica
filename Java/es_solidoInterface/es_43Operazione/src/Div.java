public class Div implements Operazione{
    private double x, y;
    public Div(double x,double y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public double getRisultato() {
        if (y != 0)
            return x / y;
        else return 0;
    }
}
