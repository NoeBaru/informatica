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
    if(volumeMax <= 1){
        this.VOLUME_MAX = VOLUME_DEFAULT;
    } else{
        this.VOLUME_MAX = volumeMax;
    }

    }

    public void setOnOff(){

    }

    public void alzaVolume(){

    }

    public void abbassaVolume(){

    }

    public void alzaCanale(){

    }

    public void abbassaCanale(){

    }
}
