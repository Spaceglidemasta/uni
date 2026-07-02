javac -d bin $(find src/java -name "*.java")

jar -cfe webmon.jar Main -C bin .
