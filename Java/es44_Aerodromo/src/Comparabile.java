public interface Comparabile {

    boolean isSuperiore(Comparabile x){
        if(x == null || getClass() != x.getClass()){
            return false;
        }
        return true;
    }

}
