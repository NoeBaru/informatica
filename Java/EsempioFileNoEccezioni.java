import java.io.*;

public class EsempioFileNoEccezioni {
    public static void main(String[] args) throws IOException {
        String nomeFile = "esempio.txt";  //nella directory del progetto

        //apertura in scrittura
        // creo un oggetto FileWriter...
        FileWriter fw = new FileWriter(nomeFile);
        // ... che incapsulo in un BufferedWriter...
      //  BufferedWriter bw = new BufferedWriter(fw);
        // ... che incapsulo in un PrintWriter
      //  PrintWriter pw = new PrintWriter(bw);

        System.out.println("Scrivo nel file " + nomeFile);
        fw.write("Una stringa: ");
        fw.write("Prima riga\n");

        fw.write("Un numero: ");
        fw.write(""+ 1); //devo convertirlo in string
        fw.write("\n");

        fw.write("Ho finito.\n");
        fw.close();

        //apertura in APPEND
        fw = new FileWriter(nomeFile, new File(nomeFile).exists());  // se esiste già lo apre in append

        for (int k = 0; k < 3; k++) {
            fw.write(k + "\n");
        }
        fw.write("ultima riga\n");
        fw.close();

        System.out.println("Scrittura terminata");

        System.out.println("\nEcco il contenuto\n");

        /////////////LETTURA PER RIGHE//////////////
        BufferedReader br = new BufferedReader(new FileReader(nomeFile));
        String s = "";

        s = br.readLine();
        while (s != null) {//return null per EOF
            System.out.println(s);
            s = br.readLine();
        }

        //oppure come in C
        // while((s = fRead.readLine()) != null) {}

        br.close();

        /////////////LETTURA PER CARATTERE//////////////
        br = new BufferedReader(new FileReader(nomeFile)); //riapertura del file


        //conteggio caratteri
        char c;
        int cont = 0;

        int cod = br.read();    //return codice UNICODE,
        while (cod != -1) {        // return -1 per EOF
            c = (char) cod;
            if (c != ' ' && c != '\n' && c != '\r')
                cont++;
            cod = br.read();
        }
        System.out.println("\nIl file " + nomeFile + " ha " + cont + " caratteri");
        br.close();

        /// CREAZIONE DEL FILE ///
        /**
         * Il costruttore della classe File riceve in ingresso il path del file.
         * La creazione di un’istanza di File non genera la creazione fisica del file sul disco fisso;
         * occorre chiamare il metodo createNewFile() per crearlo fisicamente.
         * Questo metodo restituisce: true se il file è stato creato correttamente e false se il file esiste già.
         */
        nomeFile = "nuovo.txt";
        File f = new File(nomeFile);

        if (f.exists())
            System.out.println("\nIl file " + nomeFile + " esiste");

        if (f.createNewFile())
            System.out.println("Il file " + nomeFile + " è stato creato");
        else
            System.out.println("Il file " + nomeFile + " esiste già e non è stato creato");

    }
}
