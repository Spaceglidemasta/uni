public class Room {

    private String name;
    private int floor;
    private double size_sqm;

    public Room(String name, int floor, double size){
        this.name = name;
        this.floor = floor;
        this.size_sqm = size;
    }


    String getName() {
        return name;
    };

    public int getFloor() {
        return floor;
    }

    public double getSize_sqm() {
        return size_sqm;
    }

    public void setSize_sqm(double size_sqm) {
        this.size_sqm = size_sqm;
    }
    
}
