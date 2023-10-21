public class Telecomando {
    public boolean acceso;
    public boolean mute;
    public int canale;
    public int volume;
    private final int VOLUME_MAX;
    private final int CANALE_MAX;
    private static int VOLUME_DEFAULT = 100;
    private static int CANALE_DEFAULT = 999;

    public Telecomando(int volumeMax, int canaleMax){
        CANALE_MAX = canaleMax;
        if(volumeMax <= 1){
            this.VOLUME_MAX = VOLUME_DEFAULT;
        } else{
            this.VOLUME_MAX = volumeMax;
        }

        if(canaleMax <= 1){
            this.CANALE_MAX = CANALE_DEFAULT;
        } else{
            this.CANALE_MAX = canaleMax;
        }

    }

    public void setOnOff(){

    }

    public void alzaVolume(){
        if(volume < VOLUME_MAX) {
            volume += 1;
        } else{
            System.out.println("Il volume è già al massimo");
        }
    }

    public void abbassaVolume(){
        if(volume > 0) {
            volume -= 1;
        } else{
            System.out.println("Il volume è già al minimo");
        }
    }

    public void alzaCanale(){
        if(canale < CANALE_MAX) {
            canale += 1;
        } else{
            canale = 1;
        }
    }

    public void abbassaCanale(){
        if(volume > 0) {
            volume -= 1;
        } else{
            canale = CANALE_DEFAULT;
        }
    }

    public void setCanale(int canale){

    }
    public boolean isAcceso(){
        if(acceso == false){
            acceso = true;
        } else if(acceso){
            acceso = false;
        }
    }
    public int getVolume(){
        return volume;
    }
    public int getCanale(){
        return canale;
    }
    public boolean isMuto() {
        if(mute == false){
            mute = true;
        } else if(mute){
            mute = false;
        }
    }
    public void muteOnOff(){

    }
    public String toString(){
        return "il volume e': " + volume + "il canale e': " + canale;
    }
}
