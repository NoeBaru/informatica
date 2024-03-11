let canestro;
let palloni = [];
let punteggio = 0;
let inGioco = false;
let pausa = false;
let larghezza = 1536;
let altezza = 703;

let pausaImg;
let gameOverImg;
let sfondoImg;
let palloneImg;
let canestroVuotoImg;
let canestroPienoImg;
let menuImg;
let difficoltaMenuImg;

let font;

let canestroSound;
let menuSound;
let gameSound;
let gameOverSound;

let inizioPulsante;

let velocitaPalloni;
let FACILE = 2;
let MEDIO = 3;
let DIFFICILE = 4;

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

let punteggioMassimo;
let ultimoPunteggio;

function preload() {
  sfondoImg = loadImage('./img/stadiumBasket.png');
  palloneImg = loadImage('./img/basketball.png');
  pausaImg = loadImage('./img/pauseBasket.png');
  gameOverImg = loadImage('./img/gameoverBasket.png');
  menuImg = loadImage('./img/homeBasket.png');
  canestroVuotoImg = loadImage('./img/basketEmpty.png');
  canestroPienoImg = loadImage('./img/basketFull.png');
  difficoltaMenuImg = loadImage('./img/difficoltaMenu.png');

  font = loadFont('./Basket.ttf'); //font scritte incollate sullo sfondo (i numeri non potevano essere usati)

  soundFormats('mp3', 'ogg');
  canestroSound = loadSound('./sound/canestro.mp3');
  menuSound = loadSound('./sound/backgroundMenu.mp3');
  gameSound = loadSound('./sound/backgroundGame.mp3');
  gameOverSound = loadSound('./sound/gameOverSound.mp3');
  gameOverTrumpetSound = loadSound('./sound/gameOverTrombaSound.mp3');
}

function avviaGioco() {
  menuSound.stop();
  inGioco = true;
  if (inizioPulsante) {
    inizioPulsante.hide();
    difficoltaPulsante.hide();
    facilePulsante.hide();
    medioPulsante.hide();
    difficilePulsante.hide();
  }
  loop();
  gameSound.loop();
}

class Canestro {
  constructor() {
    this.x = larghezza / 2;
    this.y = altezza - 50;
    this.larghezza = 60;
    this.altezza = 70;
  }

  update(mouseX) {
    this.x = mouseX;
  }

  display() {
    proporzionaleLarghezzaVuoto = canestroVuotoImg.larghezza * (this.altezza / canestroVuotoImg.altezza);
    image(canestroVuotoImg, this.x - proporzionaleLarghezzaVuoto / 2, this.y - this.altezza / 2, proporzionaleLarghezzaVuoto, this.altezza);
  }

  intersects(pallone) {
    distanza = dist(this.x, this.y, pallone.x, pallone.y);
    return distanza < pallone.diametro / 2 + this.altezza / 2 &&
      pallone.y + pallone.diametro / 2 > this.y - this.altezza / 2;
  }
}

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
    proporzionaleDiametro = palloneImg.larghezza * (this.diametro / palloneImg.altezza);
    image(palloneImg, this.x - proporzionaleDiametro / 2, this.y - this.diametro / 2, proporzionaleDiametro, this.diametro);
  }

  fuoriSchermo() {
    return this.y > altezza;
  }
}

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
  gameOverTrumpetSound.play();
  image(gameOverImg, 0, 0, larghezza, altezza);

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

function mostraMenuPausa() {
  gameSound.stop();
  image(pausaImg, 0, 0, larghezza, altezza);
}

function mostraMenuDifficolta() {
  image(difficoltaMenuImg, 0, 0, larghezza, altezza);

  facilePulsante = createButton('');
  facilePulsante.style('background', 'rgba(0, 0, 0, 0)');
  facilePulsante.style('border', '1');
  facilePulsante.position(larghezza / 2 - 183, altezza / 2.08);
  facilePulsante.size(388, 80);
  if(facilePulsante.mousePressed()){
    velocitaPalloni = FACILE;
  }

  medioPulsante = createButton('');
  medioPulsante.style('background', 'rgba(0, 0, 0, 0)');
  medioPulsante.style('border', '0');
  medioPulsante.position(larghezza / 2 - 283, altezza / 2.08);
  medioPulsante.size(388, 80);
  if(medioPulsante.mousePressed()){
    velocitaPalloni = MEDIO;
  }

  difficilePulsante = createButton('');
  difficilePulsanteImg.style('background', 'rgba(0, 0, 0, 0)');
  difficilePulsanteImg.style('border', '0');
  difficilePulsanteImg.position(larghezza / 2 - 383, altezza / 2.08);
  difficilePulsanteImg.size(388, 80);
  if(difficilePulsanteImg.mousePressed()){
    velocitaPalloni = DIFFICILE;
  }
}

function togglePausa() {
  pausa = !pausa;

  if (pausa) {
    continuaPulsante = createButton('');
    continuaPulsante.style('background', 'rgba(0, 0, 0, 0)');
    continuaPulsante.style('border', '0');
    continuaPulsante.position(larghezza / 2 - 183, altezza / 2.08);
    continuaPulsante.size(388, 80);
    continuaPulsante.mousePressed(continuaGioco);
    gameSound.play();

    esciPulsante = createButton('');
    esciPulsante.style('background', 'rgba(0, 0, 0, 0)');
    esciPulsante.style('border', '0');
    esciPulsante.position(larghezza / 2 - 185, altezza / 1.41);
    esciPulsante.size(390, 80);
    esciPulsante.mousePressed(esciDalGioco);

    noLoop();
  } else {
    continuaPulsante.hide();
    esciPulsante.hide();
    loop();
    gameSound.play();
  }
}

function continuaGioco() {
  pausa = false;
  gameSound.play();
  continuaPulsante.hide();
  esciPulsante.hide();
  loop();
}

function esciDalGioco() {
  noLoop();
  continuaPulsante.hide();
  esciPulsante.hide();
  gameSound.stop();
  gameOver();
}

function salvaPunteggio() {
  punteggioMassimo = localStorage.getItem('punteggioMassimo') || 0;

  if (punteggio > punteggioMassimo) {
    localStorage.setItem('punteggioMassimo', punteggio);
  }

  localStorage.setItem('ultimoPunteggio', punteggio);
}

function visualizzaPunteggiMassimi() {
  punteggioMassimo = localStorage.getItem('punteggioMassimo') || 0;
  ultimoPunteggio = localStorage.getItem('ultimoPunteggio') || 0;

  console.log('Punteggio massimo:', punteggioMassimo);
  console.log('Ultimo punteggio:', ultimoPunteggio);
}

function setup() {
  createCanvas(larghezza, altezza);

  canestro = new Canestro();
  palloni = [];

  pausaPulsante = createButton('');
  pausaPulsante.style('background', 'rgba(0, 0, 0, 0)');
  pausaPulsante.style('border', '0');
  pausaPulsante.position(larghezza - 264, altezza / 20);
  pausaPulsante.size(237, 50);
  pausaPulsante.mousePressed(togglePausa);
}

function draw() {
  background(sfondoImg);

  if (!inGioco) {
    //menuSound.play();
    image(menuImg, 0, 0, larghezza, altezza);

    inizioPulsante = createButton('');
    inizioPulsante.style('background', 'rgba(0, 0, 0, 0)');
    inizioPulsante.style('border', '0');
    inizioPulsante.position(larghezza / 2 - 635, altezza / 2.17);
    inizioPulsante.size(418, 86);
    inizioPulsante.mousePressed(avviaGioco);

    difficoltaPulsante = createButton('');
    difficoltaPulsante.style('background', 'rgba(0, 0, 0, 0)');
    difficoltaPulsante.style('border', '0');
    difficoltaPulsante.position(larghezza / 2 - 630, altezza / 1.57);
    difficoltaPulsante.size(408, 80);
    difficoltaPulsante.mousePressed(mostraMenuDifficolta);
    return;
  }

  if (pausa) {
    mostraMenuPausa();
    return;
  }

  if (canestroTimer > 0) {
    canestroTimer--;
    proporzionaleLarghezzaPieno = canestroPienoImg.larghezza * (canestro.altezza / canestroPienoImg.altezza);
    image(canestroPienoImg, canestro.x - proporzionaleLarghezzaPieno / 2, canestro.y - canestro.altezza / 2, proporzionaleLarghezzaPieno, canestro.altezza);
  } else {
    proporzionaleLarghezzaVuoto = canestroVuotoImg.larghezza * (canestro.altezza / canestroVuotoImg.altezza);
    image(canestroVuotoImg, canestro.x - proporzionaleLarghezzaVuoto / 2, canestro.y - canestro.altezza / 2, proporzionaleLarghezzaVuoto, canestro.altezza);
  }

  canestro.update(mouseX);
  canestro.display();

  tempoCorrente = millis();
  if (tempoCorrente - ultimoPallone > intervalloPalloni) {
    palloni.push(new Pallone());
    ultimoPallone = tempoCorrente;
  }

  for (let i = palloni.length - 1; i >= 0; i--) {
    palloni[i].update();
    palloni[i].display();
    if (canestro.intersects(palloni[i])) {
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