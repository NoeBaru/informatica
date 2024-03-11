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

let font;

let canestroSound;
let menuSound;
let gameSound;
let gameOverSound;

let inizioPulsante;

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
    this.velocita = 3;
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

function togglePausa() {
  pausa = !pausa;

  if (pausa) {
    continuaImgButton = createButton('');
    continuaImgButton.style('background', 'rgba(0, 0, 0, 0)');
    continuaImgButton.style('border', '0');
    continuaImgButton.position(larghezza / 2 - 183, altezza / 2.08);
    continuaImgButton.size(388, 80);
    continuaImgButton.mousePressed(continuaGioco);
    gameSound.play();

    esciImgButton = createButton('');
    esciImgButton.style('background', 'rgba(0, 0, 0, 0)');
    esciImgButton.style('border', '0');
    esciImgButton.position(larghezza / 2 - 185, altezza / 1.41);
    esciImgButton.size(390, 80);
    esciImgButton.mousePressed(esciDalGioco);

    noLoop();
  } else {
    continuaImgButton.hide();
    esciImgButton.hide();
    loop();
    gameSound.play();
  }
}

function continuaGioco() {
  pausa = false;
  gameSound.play();
  continuaImgButton.hide();
  esciImgButton.hide();
  loop();
}

function esciDalGioco() {
  noLoop();
  continuaImgButton.hide();
  esciImgButton.hide();
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

  pauseButton = createButton('');
  pauseButton.style('background', 'rgba(0, 0, 0, 0)');
  pauseButton.style('border', '0');
  pauseButton.position(larghezza - 264, altezza / 20);
  pauseButton.size(237, 50);
  pauseButton.mousePressed(togglePausa);
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