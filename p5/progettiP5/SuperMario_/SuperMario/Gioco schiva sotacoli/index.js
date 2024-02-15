//creo le variabili che mi sevono

let player;
let mImg;
let oImg;
let sImg;

//creo un array ostcolo

let ostacolo = [];

//funzione che carica prima dell'inizio del gioco le immagini 

function preload() {

    //Definizione delle immagini, le carico prima dell'inizio del gioco
    
    mImg = loadImage("img/mario.png");
    oImg = loadImage("img/ostacolo.png");
    sImg = loadImage("img/sfondo.png");

}

//funzione in cui creo il canvas e la variabile player

function setup() {

    createCanvas(1300, 700);
    player = new Player();

}

function gotCommand(error, results) {
  
    if (error) {
    
        console.error(error);
  
    }
  
    console.log(results[0].label, results[0].confidence);
  
    if (results[0].label == "up") {
 
        player.jump();
 
    }
}

//funzione che alla pressione della tastirea fa saltare il giocatore

function keyPressed() {
  
    if (key == " ") {
 
        player.jump();
 
    }
}

function draw() {

    //nell'if crea in maniera randomica tra 1 0.005 l'arrivo di un nuovo ostacolo, 
    //modificando la percentuale arrivano un maggiore numero di ostacoli
 
    if (random(1) < 0.010) {
 
        ostacolo.push(new Ostacolo());
 
    }

    //imposta lo sfondo del gioco

   background(sImg);

   //La funzione let dichiara una variabile locale dell'ambito del blocco,
   //inizializzandola facoltativamente su un valore

   for (let ost of ostacolo) {
        
        ost.move();
        ost.show();

        //se il plaier colpisce l'ostacolo il gioco finisce 
        
        if (player.hits(ost)) {

            //funzione che stampa un messaggio sulla console web del propio browser
            
            console.log("game over");

            //interrompe il ciclo, termina il gioco

            noLoop();
        }   
    }

    //mostra il plaier e il movimento che svolge

    player.show();
    player.move();

}