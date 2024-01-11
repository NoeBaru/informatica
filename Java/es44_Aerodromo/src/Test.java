/*
autore: Noemi Baruffolo
data: 11/01/2024
es: 44
testo: In un aerodromo si vuol mantenere informazioni sugli aeromobili. Di ogni aeromobile si vuole sapere la sigla
(string) che lo identifica (univoca per ciascuno). Gli aeromobili si dividono in alianti e aerei a motore:
• Gli alianti sono aeromobili caratterizzati da un numero (int) che ne descrive l'efficienza aereodinamica.
• Degli aerei a motore si vuole sapere la potenza in CV del motore propulsore (double).
Un oggetto può essere confrontabile con un altro secondo specifiche caratteristiche. Gli aeromobili dello stesso tipo
devono essere confrontabili fra loro in modo da poter stabilire quale sia quello con prestazioni migliori: gli alianti
si confrontano in base all'efficienza; gli aerei a motore in base alla potenza in CV.
Crea un'interfaccia pubblica Comparabile contenente un metodo boolean isSuperiore (Comparabile x) per verificare se un
oggetto (this) è superiore ad un altro x. Il metodo deve sempre restituire false se x è null o se gli oggetti coinvolti
nel confronto non sono dello stesso tipo.
Scrivi tre classi pubbliche: Aeromobile, Aliante e Aereomotore ciascuna con un metodo get pubblico per accedere
all'attributo specifico della classe. Ogni classe deve fornire anche un costruttore, i metodi eLoStesso (se hanno la
stessa sigla) e toString.
*/
public class Test {
    public static void main(String[] args) {

    }
}
