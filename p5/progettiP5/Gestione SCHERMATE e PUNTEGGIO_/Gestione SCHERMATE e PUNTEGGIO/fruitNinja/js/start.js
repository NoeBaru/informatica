class StartScree{

    constructor(){
        this.dim = 100
        this.x = width
        this.y = height - this.dim;
    }

    show(imgScreen) {
        background(imgScreen);
    }

    hide(){
        tint(255, 126);
    }
}