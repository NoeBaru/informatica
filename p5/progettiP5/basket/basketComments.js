let palloni = [];
let punteggio = 0;
let menu;
let inGioco = false;
let pausa = false;
let larghezza = 1536;
let altezza = 703;

/immagini/
let pausaImg;
let gameOverImg;
let sfondoImg;
let palloneImg;
let canestroVuotoImg;
let canestroPienoImg;
let menuImg;
let difficoltaMenuImg;

let font;

/suoni/
let canestroSound;
let menuSound;
let gameSound;
let gameOverSound;

/pulsanti/
let inizioPulsante;
let difficoltaPulsante;
let facilePulsante;
let medioPulsante;
let difficilePulsante;
let indietroPulsante;

/difficoltà/
const FACILE = 2;
const MEDIO = 3;
const DIFFICILE = 4;
let velocitaPalloni = MEDIO; // Impostato il valore di default su "MEDIO"


/timer/
let canestroTimer = 0;
let canestroTempoLimite = 15;
let intervalloPalloni = 6000;
let gameOverTempoLimite = 6000;
let gameOverTimer = 0;
let tempoCorrente;

let ultimoPallone = 0;
let distanza;

let proporzionaleLarghezzaPieno;
let proporzionaleLarghezzaVuoto;
let proporzionaleDiametro;

/pt/
let punteggioMassimo;
let ultimoPunteggio;

/MENU/
class Menu {
  constructor() {
    this.stato = 'principale';
  }

  mostra() {
    background(sfondoImg);

    if (this.stato === 'principale') {
      this.mostraMenuPrincipale();
    } else if (this.stato === 'difficolta') {
      this.mostraMenuDifficolta();
    }
  }

  mostraMenuPrincipale() {
    image(menuImg, 0, 0, larghezza, altezza);
    //permette di premere i due tasti "play" e "options"
    inizioPulsante.show();
    difficoltaPulsante.show();
    facilePulsante.hide();
    medioPulsante.hide();
    difficilePulsante.hide();
  }

  mostraMenuDifficolta() {
    image(difficoltaMenuImg, 0, 0, larghezza, altezza);

    //crea il pulsante indietro
    indietroPulsante = createButton('Indietro');
    indietroPulsante.position(larghezza / 2 - 50, altezza / 1.41);
    indietroPulsante.size(100, 30);
    if(indietroPulsante.mousePressed) {
      menu.stato = 'principale';
    }

    //mostra i pulsanti delle varie opzioni del gioco
    facilePulsante.show();
    medioPulsante.show();
    difficilePulsante.show();
  }

  //controlla quale pulsante viene premuto e agisce di conseguenza
  gestisciClick() {
    if (this.stato === 'principale') {
      this.gestisciClickMenuPrincipale();
    } else if (this.stato === 'difficolta') {
      this.gestisciClickMenuDifficolta();
    }
  }

  //fa partire il gioxo
  gestisciClickMenuPrincipale() {
    if(inizioPulsante.mousePressed){
      menu.avviaGioco();
    }

    if(difficoltaPulsante.mousePressed){
      menu.stato = 'difficolta';
    }
  }

  //gestisce il click della difficoltà scelta e in base a ciò imposta i parametri della velocità di caduta delle palline
  gestisciClickMenuDifficolta() {
    if(facilePulsante.mousePressed){
      velocitaPalloni = FACILE;
    }
    
    if(medioPulsante.mousePressed){
      velocitaPalloni = FACILE;
    }
    
    if(difficilePulsante.mousePressed){
      velocitaPalloni = FACILE;
    }
  }

  //fa iniziare il gioco
  avviaGioco() {
    menuSound.stop();
    inGioco = true;
    if (inizioPulsante) {
      //nasconde i pulsanti durante il gioco
      inizioPulsante.hide();
      difficoltaPulsante.hide();
      facilePulsante.hide();
      medioPulsante.hide();
      difficilePulsante.hide();
    }
    loop();
    gameSound.loop();
  }
}

function preload() {
  //carica le immagini del gioco
  sfondoImg = loadImage('./img/stadiumBasket.png');
  palloneImg = loadImage('./img/basketball.png');
  pausaImg = loadImage('./img/pauseBasket.png');
  gameOverImg = loadImage('./img/gameoverBasket.png');
  menuImg = loadImage('./img/homeBasket.png');
  canestroVuotoImg = loadImage('./img/basketEmpty.png');
  canestroPienoImg = loadImage('./img/basketFull.png');
  difficoltaMenuImg = loadImage('./img/difficoltaMenu.png');

  font = loadFont('./Basket.ttf');

  //carica i suoni del gioco
  soundFormats('mp3', 'ogg');
  canestroSound = loadSound('./sound/canestro.mp3');
  menuSound = loadSound('./sound/backgroundMenu.mp3');
  gameSound = loadSound('./sound/backgroundGame.mp3');
  gameOverSound = loadSound('./sound/gameOverSound.mp3');
}

function setup() {
  createCanvas(larghezza, altezza);
  menu = new Menu();

  //crea il pulsante di inizio
  inizioPulsante = createButton('');
  inizioPulsante.style('background', 'rgba(0, 0, 0, 0)');
  inizioPulsante.style('border', '0');
  inizioPulsante.position(larghezza / 2 - 635, altezza / 2.17);
  inizioPulsante.size(418, 86);
  inizioPulsante.mousePressed(avviaGioco);

  //crea il pulsante delle opzioni di difficoltà
  difficoltaPulsante = createButton('');
  difficoltaPulsante.style('background', 'rgba(0, 0, 0, 0)');
  difficoltaPulsante.style('border', '0');
  difficoltaPulsante.position(larghezza / 2 - 630, altezza / 1.57);
  difficoltaPulsante.size(408, 80);
  difficoltaPulsante.mousePressed(mostraMenuDifficolta);

  //crea il pulsante difficoltà facile
  facilePulsante = createButton('');
  facilePulsante.style('background', 'rgba(0, 0, 0, 0)');
  facilePulsante.style('border', '1');
  facilePulsante.position(larghezza / 2 - 183, altezza / 2.08);
  facilePulsante.size(388, 80);

  //crea il pulsante difficoltà media
  medioPulsante = createButton('');
  medioPulsante.style('background', 'rgba(0, 0, 0, 0)');
  medioPulsante.style('border', '0');
  medioPulsante.position(larghezza / 2 - 283, altezza / 2.08);
  medioPulsante.size(388, 80);

  //crea il pulsante difficoltà difficile
  difficilePulsante = createButton('');
  difficilePulsanteImg.style('background', 'rgba(0, 0, 0, 0)');
  difficilePulsanteImg.style('border', '0');
  difficilePulsanteImg.position(larghezza / 2 - 383, altezza / 2.08);
  difficilePulsanteImg.size(388, 80);

  noLoop();
}

function draw() {
  menu.mostra();
}

//se il mouse viene cliccato gestisce il click nei diversi pulsanti
function mouseClicked() {
  menu.gestisciClick();
}

/CANESTRO/
class Canestro {
  constructor() {
    this.x = larghezza / 2;
    this.y = altezza - 50;
    this.larghezza = 60;
    this.altezza = 70;
  }

  //gestisce il movimento delle coordinate x in base alle x del mouse
  update(mouseX) {
    this.x = mouseX;
  }

  display() {
    if (canestroTimer > 0) {
      proporzionaleLarghezzaPieno = canestroPienoImg.width * (this.altezza / canestroPienoImg.height);
      image(canestroPienoImg, this.x - proporzionaleLarghezzaPieno / 2, this.y - this.altezza / 2, proporzionaleLarghezzaPieno, this.altezza);
    } else {
      proporzionaleLarghezzaVuoto = canestroVuotoImg.width * (this.altezza / canestroVuotoImg.height);
      image(canestroVuotoImg, this.x - proporzionaleLarghezzaVuoto / 2, this.y - this.altezza / 2, proporzionaleLarghezzaVuoto, this.altezza);
    }
  }

  //gestisce le collisioni
  intersects(pallone) {
    distanza = dist(this.x, this.y, pallone.x, pallone.y);
    return distanza < pallone.diametro / 2 + this.altezza / 2 && pallone.y + pallone.diametro / 2 > this.y - this.altezza / 2;
  }
}

/PALLONE/
class Pallone {
  constructor() {
    this.x = random(larghezza);
    this.y = 0;
    this.diametro = 40;
    this.velocita = velocitaPalloni;
  }

  update() {
    this.y += this.velocita;
  }

  display() {
    proporzionaleDiametro = palloneImg.width * (this.diametro / palloneImg.height);
    image(palloneImg, this.x - proporzionaleDiametro / 2, this.y - this.diametro / 2, proporzionaleDiametro, this.diametro);
  }

  fuoriSchermo() {
    return this.y > altezza;
  }
}

//durante il gioco aumenta sempre di più la velocità di discesa dei palloni
function aumentaVelocita() {
  for (let pallone of palloni) {
    pallone.velocita += 0.1;
  }
}

function gameOver() {
  pausa = false;
  inGioco = false;
  salvaPunteggio();
  visualizzaPunteggiMassimi();
  gameOverSound.play();
  image(gameOverImg, 0, 0, larghezza, altezza);

  //scritta punteggio in corso
  fill(0);
  textSize(32);
  textAlign(CENTER, CENTER);
  text(punteggio, altezza + 120, larghezza / 2 - 202);
  text(punteggioMassimo, altezza + 120, larghezza / 2 - 168);

  noLoop();
}

//gestisce il menu della pausa
function mostraMenuPausa() {
  gameSound.stop();
  image(pausaImg, 0, 0, larghezza, altezza);
}

//imposta la velcotà di discesa dei palloni in base alla velocità data dal click della scelta di difficoltà oppure rimarrà il parametro di default su medio
function impostaVelocita(difficolta) {
  velocitaPalloni = difficolta;
  avviaGioco();
}

//salva il punteggio massimo effettuato e lo stampa nella console
function visualizzaPunteggiMassimi() {
  punteggioMassimo = localStorage.getItem('punteggioMassimo') || 0;
  ultimoPunteggio = localStorage.getItem('ultimoPunteggio') || 0;

  console.log('Punteggio massimo:', punteggioMassimo);
  console.log('Ultimo punteggio:', ultimoPunteggio);
}

//salva il punteggio e lo stampa nella console
function salvaPunteggio() {
  punteggioMassimo = localStorage.getItem('punteggioMassimo') || 0;

  if (punteggio > punteggioMassimo) {
    localStorage.setItem('punteggioMassimo', punteggio);
  }

  localStorage.setItem('ultimoPunteggio', punteggio);
}
