public class Punto {
    private float x;
    private float y;

    public Punto(float x, float y){
        this.x = x;
        this.y = y;

    }
    public Punto(){
        this.x = 0;
        this.y = 0;

    }
    public void setX(){

    }
    public void setY(){

    }
    public float getX(){
        return x;
    }
    public float getY() {
        return y;
    }
    public String toString(){
        return "[x: " + getX() + "y: " + getY() + "]";
    }
}
