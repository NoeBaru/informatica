public interface Comparabile {

    boolean isSuperiore(Comparabile x){
        boolean sup = false;
        if(x == null){
            sup = false;
        }
        return sup;
    }

}
