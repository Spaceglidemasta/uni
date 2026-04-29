public class Main {

    public static double getFullBuildingSqm(Building build){

        double all = 0;

        for(Room room : build.getRooms()){
            all += room.getSize_sqm();
        }

        return all;

    }


    public static void main(String[] args) {

        Room uebung = new Room("DistSys", 2, 30);
        

        Building gebeins = new Building("Gebäude 1");
        gebeins.addRoom(uebung);
        gebeins.addRoom(new Room("Rechner Arch.", 2, 40));

        System.out.printf("Total size of B. 1: %f\n", 
            getFullBuildingSqm(gebeins)
        );
        
        
    }
}