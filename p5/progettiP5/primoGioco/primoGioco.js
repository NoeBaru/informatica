let bgimg; //immagine di sfondo
let omino; //immagine omino

let width = 400;
let height = 400;

let x = 200;
let y = 300;

function preload(){
    bgimg = loadImage('./img/street.png');
    omino = loadImage('./img/porsche.png');
}

//setUp code
function setup(){
    createCanvas(bgimg.width, bgimg.height); //grandezza sfondo
    frameRate(24); //numero di fotogrammi
}

//drawing code
function draw(){
    let cont = 0;
    if(cont > 14){
        background(bgimg);
        image(omino, x, y);
        x -= 1;
    } else if(cont < -14){
        background(bgimg);
        image(omino, x, y);
        x += 1;
    } else{
        background(bgimg);
        image(omino, x, y);
        x += 1;
    }
    cont ++;
}