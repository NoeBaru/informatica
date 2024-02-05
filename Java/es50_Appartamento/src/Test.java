/*
author: Noemi Baruffolo 4^AROB
date: 24/01/2024
es: 50_Appartamento
text:Un appartamento è composto da una o più stanze, ciascuna delle quali ha una lunghezza e una larghezza.
Un appartamento è posseduto da uno o più persone. Un palazzo ha un certo numero di piani ed è composto da
uno o più appartamenti. Gli appartamenti di un palazzo hanno un valore al metroquadro diverso per ogni piano.
Deve essere possibile conoscere il valore di un appartamento e il valore immobiliare complessivo posseduto
da una persona.
*/
import java.util.Vector;

public class Test {
    public static void main(String[] args) {
        Palazzo p1;
        Proprietario a1, a2, a3;
        p1 = new Palazzo("Casa Cuneo", 250);
        System.out.println(p1.toString());
        a1 = new Proprietario("Mario");
        a2 = new Proprietario("Giovanni");
        System.out.println(a1.toString());
        p1.addPiano(480);
        System.out.println(p1.toString());
        p1.addAppartamento(1, 5.7, 4.3);
        System.out.println(p1.toString());
        p1.addAppartamento(0, 2.75, 3.8);
        p1.addStanza(0, 0, 3.7, 2.8);
        System.out.println(p1.toString());
        System.out.println(p1.getValoreMQPiano(0));
        System.out.println(p1.getValoreMQPiano(1));
        p1.setValoreMQPiano(1, 500);
        System.out.println(p1.getValoreMQPiano(1));
        System.out.println(p1.getNome());
        System.out.println(p1.getNumPiani());
        System.out.println(p1.getNumAppartamenti());
        System.out.println(p1.getLarghezzaPianoAppartamentoStanza(0, 0, 0));
        System.out.println(p1.getLunghezzaPianoAppartamentoStanza(0, 0, 0));
        p1.addProprietarioPianoAppartamento(0, 0, a1);
        p1.addProprietarioPianoAppartamento(0, 0, a1);
        System.out.println(p1.toString());
        p1.addProprietarioPianoAppartamento(0, 0, a2);
        System.out.println(p1.toString());
        p1.addProprietarioPianoAppartamento(1, 0, a2);
        System.out.println(p1.toString());
        System.out.println(p1.getValoreTotale());
        System.out.println(p1.getValoreProprietarioPianiAppartamenti(a1));
        System.out.println(p1.getValoreProprietarioPianiAppartamenti(a2));
    }
}
