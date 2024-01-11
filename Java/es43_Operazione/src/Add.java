public class Add implements Operazione{
    private double x;
    private double y;
    @Override
    public double getRisultato(double x, double y) {
        return 0;
    }
    public double getRisultato(){
        return x + y;
    }
}
