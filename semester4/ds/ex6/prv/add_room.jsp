
<%@ page import="pckg.Building"%>
<%@ page import="pckg.Room"%>
<%@ page import="java.util.ArrayList"%>
<%@ page session="true"%>
<%@ page contentType="text/html; charset=UTF-8" language="java" %>


<html>

<%

    ArrayList<Building> g_buildings = (ArrayList<Building>) session.getAttribute("buildings"); 

    String bname = null;
    if(bname == null) {
        bname = request.getParameter("bname");
    }
    

    
%>


<link rel="stylesheet" type="text/css" href="style.css">
<body bgcolor="white">


    <h1> Add a Room to <%=bname%></h1>


    <form method = "post" >

        <br>
        Room name:
        <input type="text" name = "rname">

        <br>
        Size:
        <input type="number" name="rsize">

        <br>
        Floor:
        <input type="number" step="0.1" name="rfloor">
        <br>
        

        <input type="hidden" name="bname" value="<%=bname%>">
        <input type="submit" value = "Add Room" class="travelbox">

    </form>

    <%
        
        String rname = request.getParameter("rname");
        String rfloor = request.getParameter("rfloor");
        String rsize = request.getParameter("rsize");

        if(rname != null && rname.isEmpty()){
            %> <p class="warning">Raumname darf nicht leer sein! </p> <%
        }
        if(rfloor != null && rfloor.isEmpty()){
            %> <p class="warning">Floor darf nicht leer sein! </p> <%
        }
        if(rsize != null && rsize.isEmpty()){
            %> <p class="warning">Size darf nicht leer sein! </p> <%
        }



        if (
            rname != null
        && bname != null
        && rfloor != null
        && rsize != null
        && !bname.isEmpty()
        && !rname.isEmpty()
        ) {
            for (Building b : g_buildings) {
                if (b.getName().equals(bname)) {
                    b.addRoom(new Room(
                        rname,
                        Integer.parseInt(rfloor),
                        Double.parseDouble(rsize)));
                }
            }
        }
        

        
    %>
    

    <form action="builman.jsp" method="post" >

        <input type="submit" value="Abort" class="travelbox">

    </form>



</body>
</html>