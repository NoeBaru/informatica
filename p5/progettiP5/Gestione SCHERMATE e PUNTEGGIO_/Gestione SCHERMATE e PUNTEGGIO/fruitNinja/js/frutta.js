class Frutta{

    constructor(posX, posY, maxHeight){
        this.dim = 150;  //150
        this.xpos = posX;
        this.ypos = posY;  
        this.xspeed = 4;
        this.yspeed = 4;
        this.xdirection = 0.2;
        this.ydirection = -1;
        this.gravity = 5;
        this.altezzaMax = maxHeight;
    }

    show() {
        image(frutta, this.xpos, this.ypos, this.dim, this.dim);
    }

    getXpos(){
      return this.xpos;
    }

    getYpos(){
      return this.ypos;
    }

    getDim(){
      return this.dim;
    }

    move() {    
        // aggiorna posizione della figura
        this.xpos = this.xpos + this.xspeed * this.xdirection;
        this.ypos = this.ypos + this.yspeed * this.ydirection;

        //margine sopra e sotto
        if (this.ypos < this.altezzaMax) {
          this.ydirection *= -1;
          this.direction += this.gravity;
        }
        
        
        image(frutta, this.xpos, this.ypos, this.dim, this.dim);
      }

      
      hit(){
            if(mouseIsPressed && mouseX >= this.xpos - this.dim && mouseX <= this.xpos + this.dim &&
                mouseY >= this.ypos - this.dim && mouseY <= this.ypos + this.dim){
                    //this.hide(frutta);
                    image(colpito, this.xpos, this.ypos, this.dim, this.dim);
                } 
      }

      fruttaColpita(){
        image(colpito, this.xpos, this.ypos, this.dim, this.dim);
      }

    }




    
    

    

