//Classe player, giocatore

class Player {
  
    //Dentro al costruttore inserisco

    constructor() {

        //r rappresenta la grandezza del mio player

        this.x = 150;
      
        //La posizione x del mio player e la posizione y (y = altezza)

        this.r = 120;
        this.y = height - this.r;

        //la variabile vy rappresenta la velocità, il movimento del mio player

        this.vy = 0;

        //creo la gravità, in quanto dopo il salto il palyer deve tornare a terra 

        this.gravity = 5;
    
    }
  
    //funzione salto che mi genera il salto del player

    jump() {
    
        //se il player è a terra enta nell'if quindi slta
        //controllo, permette al player di saltare solo una volta, 
        //impedende che il giocotore continui a saltare
        //Il pleyer potrà effettuare un novo salto solo dopo aver nuvamente toccato terra

        if (this.y == height - this.r) {
       
            this.vy = -60;
       
        }
    }

    //Funzione che mi gestisce lo scontro tra player e l'ostacolo
  
    hits(ostacolo) {
      
        let x1 = this.x + this.r * 0.5;
        let y1 = this.y + this.r * 0.5;
        let x2 = ostacolo.x + ostacolo.r * 0.5;
        let y2 = ostacolo.y + ostacolo.r * 0.5; 

        //ritorno la funzione collideCircleCircle che crea un cherchio, che il player può toccare/colpire
      
        return collideCircleCircle(x1, y1, this.r, x2, y2, ostacolo.r);
    }

    //fa muovere il persconaggio
  
    move() {
      
        //ogni volta che il mio playersalta y cambia posizione in base al salto

        this.y += this.vy;

        //la velocità aumenta dopo ogni slato in questo modo il player torna a terra

        this.vy += this.gravity;

        //La funzione constrain() vincola un valore compreso tra un valore minimo e massimo

        this.y = constrain(this.y, 0, height - this.r);
    
    }
  
    //Creo la figura del player (un rettangolo), e tramite la funzione image gli assegno l'immmagine di mario

    show() {

      image(mImg, this.x, this.y, this.r, this.r);
       
    }
  }