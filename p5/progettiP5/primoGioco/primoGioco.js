let bgimg; //immagine di sfondo
let omino; //immagine omino
let ominoDistrutto;

let width = 400;
let height = 400;

let x = 200;
let y = 300;

let nFrame = 24;
let color = 'grey';
let r = 50;

function preload(){
    bgimg = loadImage('./img/street.png');
    omino = loadImage('./img/porsche.png');
    ominoOld = omino;
    ominoDistrutto = loadImage('./img/macchinaDistrutta.jpg')
}

//setUp code
function setup(){
    createCanvas(bgimg.width, bgimg.height); //grandezza sfondo
    frameRate(nFrame); //numero di fotogrammi
    background(bgimg);
    ominoDistrutto.resize(60, 100);
    x = 150;
    y = 150;
}

//drawing code
function draw(){
    background(bgimg);
    image(omino, x, y);

    fill(color) //colore cerchio
    ellipse(x, y, r, r)
    fill(color)
    ellipse(x+(x/2), y, r, r)    
}

function keypassed(){
    if(key = " "){
        if(bgImgAttuale == bgimg){
            bgImgAttuale = bgimgStart;
        } else{
            bgImgAttuale = bgimg;
        }
    }
}

function mouseClicked(){
    let d = dist(mouseX, mouseY, x, y); //la distanza
    if (d < r/2){
        if(color == 'yellow'){
            color = 'grey';
            omino = ominoDistrutto;
        } else{
            color = 'yellow';
            omino = ominoOld;
        }
    }
}