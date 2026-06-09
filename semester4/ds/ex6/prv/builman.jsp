
<%@ page import="pckg.Building"%>
<%@ page import="pckg.Room"%>
<%@ page session="true"%>
<%@ page contentType="text/html; charset=UTF-8" language="java" %>

<html>

<% Building b = new Building("FRA UAS"); %>


<link rel="stylesheet" type="text/css" href="style.css">
<body bgcolor="white">

    <h1>Manage your buildings</h1>

    <h2>Building: <%= b.getName() %></h2>
    <h3>Rooms:</h3>
    <ul>
        <% for (Room r : b.getRooms()) { %>
            <li><%= r.getName() %> - Capacity: <%= r.getCapacity
            () %></li>
        <% } %>
    </ul>

</body>
</html>