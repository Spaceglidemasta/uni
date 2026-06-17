
<%@ page import="pckg.Building"%>
<%@ page import="pckg.Room"%>
<%@ page import="java.util.ArrayList"%>
<%@ page session="true"%>
<%@ page contentType="text/html; charset=UTF-8" language="java" %>

<html>

<%

    ArrayList<Building> g_buildings = (ArrayList<Building>) session.getAttribute("buildings"); 
    


%>


<link rel="stylesheet" type="text/css" href="style.css">
<body bgcolor="white">

    <h1> Change Room Size of  <%= %></h1>


    <form method = "post">

        <input type="text", name = "bname">

        <input type="submit", value = "Add building">

    </form>

    <%

        String name = request.getParameter("bname");

        if (name != null) {
            g_buildings.add(
                new Building(name)
            );
        }

        
    %>
    

    <form action="builman.jsp" method="post" >

        <input type="submit" value="Abort" class="travelbox">

    </form>



</body>
</html>