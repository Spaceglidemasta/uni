
<%@ page import="pckg.Building"%>
<%@ page import="pckg.Room"%>
<%@ page import="java.util.ArrayList"%>
<%@ page session="true"%>
<%@ page contentType="text/html; charset=UTF-8" language="java" %>

<html>

<%

    ArrayList<Building> g_buildings = (ArrayList<Building>) session.getAttribute("buildings"); 

    String bname = request.getParameter("bname");
%>


<link rel="stylesheet" type="text/css" href="style.css">
<body bgcolor="white">


    <h1> Add a Room to <%=bname%></h1>
    

    <form action="builman.jsp" method="post" class="travelbox">

        <input type="submit" value="Abort">

    </form>



</body>
</html>