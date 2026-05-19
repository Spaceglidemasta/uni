package Objects;

import java.rmi.Remote;

public interface RoomProxy extends Remote{

    public String getName();

    public int getFloor();

    public double getSize_sqm();

    public void setSize_sqm(double size_sqm);
    
}
