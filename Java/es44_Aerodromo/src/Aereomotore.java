public class Aereomotore {
    private double cv;

    public Aereomotore(double cv) {
        this.cv = cv;
    }

    public double getCv() {
        return cv;
    }

    @Override
    public String toString() {
        return "cv: " + cv;
    }
}
