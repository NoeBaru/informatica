let canestro;
let palloni = [];
let punteggio = 0;
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

let font;

/suoni/
let canestroSound;
let menuSound;
let gameSound;
let gameOverSound;

let inizioPulsante;

/timer/
let canestroTimer = 0;
let canestroTempoLimite = 15;
let intervalloPalloni = 6000;
let gameOverTempoLimite = 6000;
let gameOverTimer = 0;

let ultimoPallone = 0;
let distanza;
let tempoCorrente;

let proporzionaleLarghezzaPieno;
let proporzionaleLarghezzaVuoto;
let proporzionaleDiametro; 

/pt/
let punteggioMassimo;
let ultimoPunteggio;

function preload() {
  //carica le immagini del gioco
  sfondoImg = loadImage('./img/stadiumBasket.png');
  palloneImg = loadImage('./img/basketball.png');
  pausaImg = loadImage('./img/pauseBasket.png');
  gameOverImg = loadImage('./img/gameoverBasket.png');
  menuImg = loadImage('./img/homeBasket.png');
  canestroVuotoImg = loadImage('./img/basketEmpty.png');
  canestroPienoImg = loadImage('./img/basketFull.png');

  font = loadFont('./Basket.ttf'); //font scritte incollate sullo sfondo (i numeri non potevano essere usati)

  //carica i suoni del gioco
  soundFormats('mp3', 'ogg');
  canestroSound = loadSound('./sound/canestro.mp3');
  menuSound = loadSound('./sound/backgroundMenu.mp3');
  gameSound = loadSound('./sound/backgroundGame.mp3');
  gameOverSound = loadSound('./sound/gameOverSound.mp3');
  gameOverTrumpetSound = loadSound('./sound/gameOverTrombaSound.mp3');
}

//fa iniziare il gioco
function avviaGioco() {
  menuSound.stop();
  inGioco = true;
  if (inizioPulsante) {
    //nasconde il pulsante durante il gioco
    inizioPulsante.hide();
  }
  loop();
  gameSound.loop();
}

/CANESTRO/
class Canestro {
  constructor() {
    this.x = larghezza / 2;
    this.y = altezza - 50;
    this.larghezza = 60;
    this.altezza = 70;
    //console.log("" + this.x + this.y + this.altezza + this.larghezza);
  }

  //gestisce il movimento delle coordinate x in base alle x del mouse
  update(mouseX) {
    this.x = mouseX;
  }
  //mostra il canestro
  display() {
    proporzionaleLarghezzaVuoto = canestroVuotoImg.larghezza * (this.altezza / canestroVuotoImg.altezza);
    image(canestroVuotoImg, this.x - proporzionaleLarghezzaVuoto / 2, this.y - this.altezza / 2, proporzionaleLarghezzaVuoto, this.altezza);
  }

  //gestisce le collisioni
  intersects(pallone) {
    distanza = dist(this.x, this.y, pallone.x, pallone.y);
    return distanza < pallone.diametro / 2 + this.altezza / 2 &&
      pallone.y + pallone.diametro / 2 > this.y - this.altezza / 2;
  }
}

/PALLONE/
class Pallone {
  constructor() {
    this.x = random(larghezza);
    this.y = 0;
    this.diametro = 40;
    this.velocita = 3;
  }

  //gestisce il movimento delle coordinate x in base alle x del mouse
  update() {
    this.y += this.velocita;
  }

  //mostra i palloni
  display() {
    proporzionaleDiametro = palloneImg.width * (this.diametro / palloneImg.height);
    image(palloneImg, this.x - proporzionaleDiametro / 2, this.y - this.diametro / 2, proporzionaleDiametro, this.diametro);
  }
  //controlla se il pallone finisce fuori dallo schermo
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

//gestisce la fine del gioco se si esce o se si perde
function gameOver() {
  pausa = false;
  inGioco = false;
  salvaPunteggio();
  visualizzaPunteggiMassimi();

  //gestisce i suoni
  gameOverSound.play();
  gameOverTrumpetSound.play();
  //imposta lo sfondo
  image(gameOverImg, 0, 0, larghezza, altezza);

  //scritta punteggio in corso
  fill(0);
  textSize(32);
  textAlign(CENTER, CENTER);
  text(punteggio, altezza + 120, larghezza / 2 - 202);
  text(punteggioMassimo, altezza + 120, larghezza / 2 - 168);

  //per restart game, ma ha bug
  /*inizioPulsante = createButton('');
  inizioPulsante.style('background', 'rgba(0, 0, 0, 0)');
  inizioPulsante.style('border', '0');
  inizioPulsante.position(larghezza / 2 - 198, altezza / 1.33);
  inizioPulsante.size(358, 117);
  inizioPulsante.mousePressed(avviaGioco);*/
  
  noLoop();
}

//gestisce il menu della pausa
function mostraMenuPausa() {
  gameSound.stop();
  image(pausaImg, 0, 0, larghezza, altezza);
}

function togglePausa() {
  pausa = !pausa;

  if (pausa) { //se è in pausa
    //mostra il pulsante invisibile per continuare la partita
    continuaImgButton = createButton('');
    continuaImgButton.style('background', 'rgba(0, 0, 0, 0)');
    continuaImgButton.style('border', '0');
    continuaImgButton.position(larghezza / 2 - 183, altezza / 2.08);
    continuaImgButton.size(388, 80);
    continuaImgButton.mousePressed(continuaGioco);
    gameSound.play();

    //mostra il pulsante invisibile per uscire dalla partita
    esciImgButton = createButton('');
    esciImgButton.style('background', 'rgba(0, 0, 0, 0)');
    esciImgButton.style('border', '0');
    esciImgButton.position(larghezza / 2 - 185, altezza / 1.41);
    esciImgButton.size(390, 80);
    esciImgButton.mousePressed(esciDalGioco);

    noLoop();
  } else {
    //nasconde i pulsanti invisibili
    continuaImgButton.hide();
    esciImgButton.hide();
    loop();
    gameSound.play(); //gestisce il suono del gioco
  }
}

//fa continuare il gioco, riprendendo la musica e nascondendo i pulsanti invisibili
function continuaGioco() {
  pausa = false;
  gameSound.play();
  continuaImgButton.hide();
  esciImgButton.hide();
  loop();
}

//fa uscire dal gioco cambiando musica e uscendo dal gioco
function esciDalGioco() {
  noLoop();
  continuaImgButton.hide();
  esciImgButton.hide();
  gameSound.stop();
  gameOver();
}

//salva i punteggi fatti nel corso della partita
function salvaPunteggio() {
  punteggioMassimo = localStorage.getItem('punteggioMassimo') || 0;

  if (punteggio > punteggioMassimo) {
    localStorage.setItem('punteggioMassimo', punteggio);
  }

  localStorage.setItem('ultimoPunteggio', punteggio);
}

//stampa i punteggiMassimi nella consoleLog
function visualizzaPunteggiMassimi() {
  punteggioMassimo = localStorage.getItem('punteggioMassimo') || 0;
  ultimoPunteggio = localStorage.getItem('ultimoPunteggio') || 0;

  console.log('Punteggio massimo:', punteggioMassimo);
  console.log('Ultimo punteggio:', ultimoPunteggio);
}

function setup() {
  createCanvas(larghezza, altezza);

  canestro = new Canestro(); //crea il canestro
  palloni = []; //crea l'array di palloni

  //crea il pulsante pausa invisibile
  pauseButton = createButton('');
  pauseButton.style('background', 'rgba(0, 0, 0, 0)');
  pauseButton.style('border', '0');
  pauseButton.position(larghezza - 264, altezza / 20);
  pauseButton.size(237, 50);
  pauseButton.mousePressed(togglePausa);
}

function draw() {
  background(sfondoImg); //imposta lo sfondo del gioco

  if (!inGioco) {
    //menuSound.play(); //fa andare tutto a scatti se lo attivo
    image(menuImg, 0, 0, larghezza, altezza); //imposta lo sfondo del menu

    //crea il pulsante invisibile di inizio del gioco
    inizioPulsante = createButton('');
    inizioPulsante.style('background', 'rgba(0, 0, 0, 0)');
    inizioPulsante.style('border', '0');
    inizioPulsante.position(larghezza / 2 - 635, altezza / 2.17);
    inizioPulsante.size(418, 86);
    inizioPulsante.mousePressed(avviaGioco);
    return;
  }

  if (pausa) {
    mostraMenuPausa();
    return;
  }
  
  /*gestisce l'animazione del canestro pieno e vuoto in base a se passsa il pallone  nel canestro vuoto o meno, mette il canestro pieno, dopo tot secondi
  toglie il canestro pieno e rimette quello vuoto*/
  if (canestroTimer > 0) {
    canestroTimer--;
    proporzionaleLarghezzaPieno = canestroPienoImg.width * (canestro.altezza / canestroPienoImg.height);
    image(canestroPienoImg, canestro.x - proporzionaleLarghezzaPieno / 2, canestro.y - canestro.altezza / 2, proporzionaleLarghezzaPieno, canestro.altezza);
  } else {
    proporzionaleLarghezzaVuoto = canestroVuotoImg.width * (canestro.altezza / canestroVuotoImg.height);
    image(canestroVuotoImg, canestro.x - proporzionaleLarghezzaVuoto / 2, canestro.y - canestro.altezza / 2, proporzionaleLarghezzaVuoto, canestro.altezza);
  }

  //aggiorna le correnti coordinate x del canestro abbinandole a quelle correnti del mouse
  canestro.update(mouseX);
  canestro.display();

  tempoCorrente = millis();

  //gestisce il flusso dei palloni nuovi
  if (tempoCorrente - ultimoPallone > intervalloPalloni) {
    palloni.push(new Pallone());
    ultimoPallone = tempoCorrente;
  }

  for (let i = palloni.length - 1; i >= 0; i--) {
    palloni[i].update();
    palloni[i].display();
    if (canestro.intersects(palloni[i])) { //gestisce le collisioni del pallone i con il canestro
      canestroSound.play();
      palloni.splice(i, 1);
      palloni.push(new Pallone());
      punteggio++;
      aumentaVelocita();
      canestroTimer = canestroTempoLimite;
    } else if (palloni[i].fuoriSchermo()) {
      gameOverTimer = millis();
      gameSound.stop();
      gameOver();
    }
  }

  fill(0);
  textSize(35);
  text(punteggio, 260, 70);

  if (gameOverTimer > 0) {
    if (millis() - gameOverTimer < gameOverTempoLimite) {
      gameOver();
    } else {
      gameOverTimer = 0;
      inGioco = false;
      visualizzaPunteggiMassimi();
    }
  }
}
