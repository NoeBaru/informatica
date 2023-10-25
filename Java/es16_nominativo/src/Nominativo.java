public class Nominativo {
    private String nome;
    private String cognome;
    private char sesso;
    private int giorno;
    private int mese;
    private int anno;

    public Nominativo(){
        nome = "";
        cognome = "";
        sesso = 'M';
        giorno = 1;
        mese = 1;
        anno = 2000;
    }

    private boolean sessoOk(char sesso){
        return sesso == 'M' || sesso == 'm' || sesso == 'F' || sesso == 'f';
    }

    public Nominativo(String nome, String cognome, char sesso, int giorno, int mese, int anno){
        this();

        this.nome = nome;
        this.cognome = cognome;
        if(sessoOk(sesso)){
            this.sesso = sesso;
        }
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public void setCognome(String cognome){
        this.cognome = cognome;
    }

    public void setSesso(char sesso){
        if(sessoOk(sesso)){
            this.sesso = sesso;
        }

    }

    /*public void setNascita(int giorno, int mese, int anno){
        if()
    }*/

    public String getNome(){return nome;}
    public String getCognome(){return cognome;}
    public char getSesso(){return sesso;}
    public int getGiorno(){return giorno;}
    public int getMese(){return mese;}
    public int getAnno(){return anno;}

    public String iniziali(){
        String nomeXXX = nome + "xxx";
        String cognomeXXX= cognome + "xxx";
        String iniz = nomeXXX.substring(0,3).toLowerCase() +
                cognomeXXX.substring(0,3).toUpperCase();
        return iniz;
    }

    private boolean isVocale(char car){
        return (car == 'a' || car == 'e' || car == 'i' || car == 'o' || car == 'u' ||
                car == 'A' || car == 'E' || car == 'I' || car == 'O' || car == 'U');
    }

    private boolean isConsonante(char car){
        return !isVocale(car) && ((car > 'a' && car <= 'z') || (car > 'A' && car <= 'Z'));
    }

    public String inizialiCF(){
        String CF = "";
        char car;
        int j = 0;
        int k = 0;
        String temp = "";

        while (k < cognome.length() && j < 3){
            car = cognome.charAt(k);
            if(isConsonante(car)){
                temp += car;
                j++;
            }

            k++;
        }
        k = 0;
        while (k < cognome.length() && j < 3){
            car = cognome.charAt(k);
            if(isVocale(car)){
                temp += car;
                j++;
            }
            k++;
        }

        CF = (temp + "xxx").substring(0,3);

        k = 0;
        j = 0;
        temp = "";
        while (k < nome.length() && j < 3){
            car = nome.charAt(k);
            if(isConsonante(car)){
                temp += car;
                j++;
            }
            k++;
        }

        while (k < nome.length() && j < 3){
            car = nome.charAt(k);
            if(isVocale(car)){
                temp += car;
                j++;
            }
            k++;
        }

        CF = CF + (temp + "xxx").substring(0,3);

        int cifreAnno = (anno % 100);

        if(cifreAnno < 10){
            CF = CF + 0 + cifreAnno;
        }else {
            CF = CF + cifreAnno;
        }

        String carattereMese = "ABCDEHLMPRST";

        CF = CF + carattereMese.charAt(mese - 1);

        if(sesso == 'M'){
            if(giorno < 10){
                CF = CF + 0 + giorno;
            }else {
                CF += giorno;
            }
        }else{
            CF = CF + (giorno + 40);
        }

        return CF.toUpperCase();
    }

    public boolean isOmocodice(Nominativo altroNom){
        return this.inizialiCF().equals(altroNom.inizialiCF());
    }

    @Override
    public String toString() {
        return "Il nome è: " + nome + " Il cognome è: " + cognome + " Il sesso è: " + sesso + " La data di nascita è: " + anno + "/" + mese + "/"+ giorno;
    }
}