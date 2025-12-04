# Exercise 4

## 1

- The attributes of "Person" dont have types.
- There is a second, syntacticly wrong "Nurse" object on the right
- There is an infinite inheritance between "Doctor", "Nurse" and "Midwife". "Doctor" should not inherit "Midwife"
- "Midwife" should inherit "Person" and not "Nurse"
- "Nurse" is falsly flagged as public?
- "Nurse" should (probably) not inherit "Doctor"
- There is an empty, unrelated "Building" object on the bottom left, which is syntacticly correct, but redundant, altough "hospital" should inherit it.
- "hospital.number_of_rooms" should be an integer but is a float
- The line "+String ; type" in "Doctor" is syntacticly wrong. It should be "+type: String"
- "Doctor Trump" sounds more like an instance of "Doctor" then a class, as, logically, there arent multiple Doctor Trumps
- "operate()" is written as its own class instead of a method of "Doctor"
- There is an unconnected line going off the screen from "Midwife"
- ("hospital.ReportFire()" should be void, but is integer)
- "Person.jump()" should probably take a float as height and not int 
- "Person.name" and "Person.age" are missing types, String and int / float would be fitting.
- "Departmens.Hospital Name" needs an "_" and is missing a type. The same with "Nurse.age" & "Doctor Trump.name"
- "hospital" should not be related to only 1 Person instance
- "Doctor" should be related to "hospital"



