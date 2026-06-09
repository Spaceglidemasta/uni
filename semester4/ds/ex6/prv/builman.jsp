
<%@ page import="pckg.Building"%>
<%@ page import="pckg.Room"%>
<%@ page import="java.util.ArrayList"%>
<%@ page session="true"%>
<%@ page contentType="text/html; charset=UTF-8" language="java" %>

<html>

<!-- init -->
<%
ArrayList<Building> g_buildings = (ArrayList<Building>) session.getAttribute("buildings");

if (g_buildings == null) {

    g_buildings = new ArrayList<>();
    session.setAttribute("buildings", g_buildings);

    Building frauas = new Building("FRA UAS");
    frauas.addRoom(new Room("Room 1",2,  15.0f));
    frauas.addRoom(new Room("Room 2",2,  30.0f));

    Building geb1 = new Building("Gebäude 1");
    geb1.addRoom(new Room("Room 1",2,  20.0f));
    geb1.addRoom(new Room("Room 2",2,  30.0f));
    geb1.addRoom(new Room("Room 3",1,  50.0f));

    g_buildings.add(frauas);
    g_buildings.add(geb1);

}



%>


<link rel="stylesheet" type="text/css" href="style.css">
<body bgcolor="white">

    <h1>Manage your buildings</h1>

    <% for (Building b : g_buildings) { %>

        <h2>Building: <%= b.getName() %></h2>
        <ul>
            <% for (Room r : b.getRooms()) { %>
                <li><%= r.getName() %> - Capacity: <%= r.getSize_sqm()%>m²</li>
            <% } %>

            <form action="add_room.jsp" method="post" class="travelbox">

                <input type="hidden" value="<%= b.getName()%>" name="bname">
                <input type="submit" value="Add a Room">

            </form>

        </ul>

    <% } %>

    

    <form action="add_building.jsp" method="post" class="travelbox">

        <input type="submit" value="Add a building">

    </form>





</body>
</html>