public class Zoo {
    public static void main(String[] args) {
        Animale[] gabbie = new Animale[3];
        gabbie[0] = new Scoiattolo();
        gabbie[1] = new Cane();
        gabbie[2] = new Leone();
        for(int k = 0; k < gabbie.length; k++) {
            gabbie[k].verso();
            if (gabbie[k] instanceof Cane)
                ((Cane) gabbie[k]).ringhiare(); //downcasting
        }
    }
}
