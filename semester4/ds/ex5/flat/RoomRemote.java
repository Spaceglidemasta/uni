

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface RoomRemote extends Remote{

    public String getName() throws RemoteException;

    public int getFloor() throws RemoteException;

    public double getSize_sqm() throws RemoteException;

    public void setSize_sqm(double size_sqm) throws RemoteException;
    
}
