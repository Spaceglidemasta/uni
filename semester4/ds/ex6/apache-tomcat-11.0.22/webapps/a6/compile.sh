#!/bin/bash
javac -cp $CLASSPATH apache-tomcat-11.0.22/webapps/a6/*.java
mv apache-tomcat-11.0.22/webapps/a6/*.class apache-tomcat-11.0.22/webapps/a6/WEB-INF/classes/