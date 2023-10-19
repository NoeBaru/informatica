public class Test {
    public static void main(String [] args){
        Temperatura tTemp1;
        tTemp1 = new Temperatura();
        tTemp1.setTempC(44);
        System.out.println(tTemp1.getTempC());
        Temperatura tTemp2;
        tTemp2 = new Temperatura();
        tTemp2.setTempF(tTemp1.getTempC());
        System.out.println(tTemp2.getTempF());
    }
}
