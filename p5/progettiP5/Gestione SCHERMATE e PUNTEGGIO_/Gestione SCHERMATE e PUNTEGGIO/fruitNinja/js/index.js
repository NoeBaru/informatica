//immagini
let sfondoGioco
let frutta
let colpito
let sfondoIniziale
let sfondoGameOver

//oggetti
let cocomero //questo non serve è solo di prova
let frutti = []

//dimenione finestra
let width = 1300
let height = 700

//schermata
let schermata = 0;

//parametri per i frutti
let posX
let posY
let maxH

//parametri per posizione e dimensione punteggio
let scoreX
let scoreY
let scoreDim

//altre variabili
let punteggio = 0
let numeroClick = 0

//i vari bottoni sono lunghi e larghi circa 80 pixel(?)
//da sistemare punteggio, game over 



function preload() {    
    sfondoGioco = loadImage("img/mainScreen.jpg");
    frutta = loadImage("img/cocomero.png");
    colpito = loadImage("img/explo.png");
    sfondoIniziale = loadImage("img/startT.jpg");
    sfondoGameOver = loadImage("img/gameOver.jpg");
    sfondoPausa = loadImage("img/pausedGameS.jpg");
}

function setup(){
    createCanvas(width, height);
    frameRate(120);
    cocomero = new Frutta(460, 510, 550);  //non serve è di prova
}

function draw(){ 
    background(sfondoIniziale);
    funz = "screen" + (schermata + 1)
    window[funz]() //richiama la funzione chiamata cosi nella pagina

    //gestione varie schermate
    /*if(schermata == 0){
        screen1(); //start
    }else if(schermata == 1){
        screen2(); //gioco
    }else if(schermata == 2){
        screen3(); //game over
    }else if(schermata == 3){
        screen4(); //pausa
    }*/
}

//start
function screen1(){
    background(sfondoIniziale);
    punteggio = 0; //azzero punteggio
    frutti.pop(); //svouta l'array
}

//gioco
function screen2(){
    background(sfondoGioco);
    //cocomero.show();
    //cocomero.move();
    //cocomero.hit();

    //creo la frutta
    if (random(1) < 0.010) {
        posX = random(0, width);
        posY = random(height, height + 100);
        maxH = random(100, height - 300);
        frutti.push(new Frutta(posX, posY, maxH));
 
    }

    //visualizzo la frutta
    for (let fru of frutti) {
        fru.move();
        fru.hit();

        //gestione punteggio (da controllare)
        if(mouseIsPressed && mouseX >= fru.getXpos() - fru.getDim() && mouseX <= fru.getXpos() + fru.getDim() &&
            mouseY >= fru.getYpos() - fru.getDim() && mouseY <= fru.getYpos() + fru.getDim()){
                punteggio += 1;  
            } 
    }
    // x = width - 150, y = 100, dim = 50
    printScore(width - 150, 100, 50);
}

//game over
function screen3(){
    background(sfondoGameOver);
    textSize(50);
    fill('yellow');
    textStyle(BOLD);
    text('SCORE:', 430, 500);
    text(punteggio, width / 2, 500);
}

//pausa
function screen4(){
    background(sfondoPausa);
    // x = width - 150, y = 100, dim = 50
    printScore(width - 150, 100, 50);
    //cocomero.show(); //serve solo per misurare bottoni
}


//bottoni vari
function mousePressed(){
    //controllo pressione bottone start
    if(mouseIsPressed && mouseX >= 520 && mouseX <= 750 &&
        mouseY >= 580 && mouseY <= 650){
            if(schermata == 0){
                schermata = 1;
            }
    //messa in pausa
    }else if(mouseIsPressed && mouseX >= 70 && mouseX <= 180 &&
                mouseY >= 20 && mouseY <= 125){
                    if(schermata == 1){
                        schermata = 3;
                    }
    //toglie dalla pausa (bottone a triangolo)
    }else if(mouseIsPressed && mouseX >= 750 && mouseX <= 830 &&
                mouseY >= 430 && mouseY <= 510){
                    schermata = 1;
    //torna alla schermata principale (bottone freccina che gira su se stessa)
    }else if(mouseIsPressed && mouseX >= 610 && mouseX <= 685 &&
                mouseY >= 430 && mouseY <= 510){
                    schermata = 0;  
    //replay - rinizia da capo la partita (bottone a X)
    }else if(xButtonPressed() == true){
                    schermata = 1   //da guardare pk punteggio non si azzera
    }
}

//altre funzioni
function keyPressed() {
    if (key == " ") {
        schermata = 2;
    }else if(key == "x"){
        schermata = 0;
    }
}

function printScore(scoreX, scoreY, scoreDim){
    textSize(scoreDim);
    fill('yellow');
    textStyle(BOLD);
    text(punteggio, scoreX, scoreY);
}

function xButtonPressed(){
    let pressed = false;

    if(mouseIsPressed && mouseX >= 460 && mouseX <= 530 &&
        mouseY >= 430 && mouseY <= 510){
            pressed = true;   
    }
    return pressed;
}



