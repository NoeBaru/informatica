public class Telecomando {
    public boolean acceso;
    public boolean mute;
    public int canale;
    public int volume;
    private final int VOLUME_MAX;
    private final int CANALE_MAX;
    private static int VOLUME_DEFAULT = 100;
    private static int CANALE_DEFAULT = 999;

    public Telecomando(int volumeMax, int canaleMax){ //costruttore
        CANALE_MAX = canaleMax;
        if(volumeMax <= 1){
            this.volume = VOLUME_DEFAULT;
        } else{
            this.VOLUME_MAX = volumeMax;
        }

        if(canaleMax <= 1){
            this.canale = CANALE_DEFAULT;
        } else{
            this.CANALE_MAX = canaleMax;
        }

    }

    public void setOnOff(){
        if(acceso == false){
            acceso = true;
        } else{
            acceso = false;
        }

    }

    public void alzaVolume(){
        if(volume < VOLUME_MAX) {
            volume += 1;
        } else{
            System.out.println("Il volume è già al massimo");
        }
    }

    public void abbassaVolume(){
        if(acceso == true) {
            volume -= 1;
        }
        if(volume <= 0){
            volume = 0;
        }
    }

    public void alzaCanale(){
        if(acceso == true) {
            canale += 1;
        }
        if(canale <= 0){
            canale = CANALE_MAX;
        }
    }

    public void abbassaCanale(){
        if(volume > 0) {
            volume -= 1;
        } else{
            canale = CANALE_DEFAULT;
        }
    }

    public void setCanale(int canale){ //canale è quella locale, per usare quella sopra devo scrivere this. (riferimento all'oggetto su cui è invocato setCanale
        if(canale <= CANALE_MAX && canale > 0){
            this.canale = canale;
        }

    }
    public boolean isAcceso(){
        if(acceso == false){
            acceso = true;
        } else if(acceso){
            acceso = false;
        }
        return acceso
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
        return mute;
    }
    public void muteOnOff(){
        if(acceso){
            mute = !mute;
        }
    }
    public String toString(){
        return "il volume e': " + volume + "il canale e': " + canale;
    }
}
