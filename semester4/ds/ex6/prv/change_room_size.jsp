
<%@ page import="pckg.Building"%>
<%@ page import="pckg.Room"%>
<%@ page import="java.util.ArrayList"%>
<%@ page session="true"%>
<%@ page contentType="text/html; charset=UTF-8" language="java" %>

<html>

<%

    ArrayList<Building> g_buildings = (ArrayList<Building>) session.getAttribute("buildings");
    String rname = request.getParameter("rname");
    String bname = request.getParameter("bname");
    


%>


<link rel="stylesheet" type="text/css" href="style.css">
<body bgcolor="white">

    <h1> Change Room Size of  <%=rname%> (<%=bname%>)</h1>

    

    <form method = "post" >

        Size:
        <input type="number" name="rsize">

        <br>
        <input type="submit" value = "Change Size" class="travelbox">
        <input type="hidden" name="bname" value="<%=bname%>">
        <input type="hidden" name="rname" value="<%=rname%>">

    </form>

    <%
        
        String rsize = request.getParameter("rsize");

        if(rsize != null && rsize.isEmpty()){
            %> <p class="warning">Size darf nicht leer sein! </p> <%
            
        }

        if(rsize != null && !rsize.isEmpty())
        for(Building b : g_buildings){

            if(b.getName().equals(bname)){

                for(Room r : b.getRooms()){

                    if(r.getName().equals(rname)){

                        r.setSize_sqm(Double.parseDouble(rsize));
                        break;

                    }

                }
                break;


            }


        }


    %>

    <form action="builman.jsp" method="post" >

        <input type="submit" value="Abort" class="travelbox">

    </form>



</body>
</html>