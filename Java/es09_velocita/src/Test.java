public class Test {
    public static void main(String [] args){
        Velocita velKmH;
        velKmH = new Velocita();
        velKmH.setVelKmH(44);
        System.out.println(velKmH.getVelKmH());
        Velocita velMs;
        velMs = new Velocita();
        velMs.setVelMs(velKmH.getVelKmH());
        System.out.println(velMs.getVelMs());
    }
}
