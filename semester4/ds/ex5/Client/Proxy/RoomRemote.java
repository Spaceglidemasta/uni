package Proxy;

import java.rmi.Remote;

public interface RoomRemote extends Remote{

    public String getName();

    public int getFloor();

    public double getSize_sqm();

    public void setSize_sqm(double size_sqm);
    
}
