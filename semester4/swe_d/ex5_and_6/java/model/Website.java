package model;

import java.util.ArrayList;

public class Website implements Subject{


    private String url;
    private ArrayList<Observer> obs_list;

    public Website(String url){
        this.url = url;
    }

    public String getUrl(){
        return url;
    }


    public boolean detectUpdated(){

        //important update detection logic
        boolean updated = true;

        if(updated)
            notifyObservers();

        return true;

    }

    @Override
    public void attach(Observer obs){
        obs_list.add(obs);
    }

    @Override
    public void detach(Observer obs){
        obs_list.remove(obs);
    }
    
    @Override
    public void notifyObservers(){
        for(Observer o : obs_list){
            o.update();
        }
    }


}
