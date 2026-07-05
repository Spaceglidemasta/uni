# lecture 3 notes


## UML

Straight filled arrow: Navigateablity, from A to B


Straight empty arrow: Inheritence

Dottet empty arrow: Interface, uses

empty diamond: Sender is part of Reciever, not fully, maybe pointer arith. (aggregation) (Team & Player)

full diamond: Sender is completely a part of reciever. Senders lifetime ends and stays with Reciever (Composition) (House & Room)

## GRASP

### Core Principles

Information Expert:

The class which has all information to fullfill a certain responsability should have the responsability

Creator:

Assign the responsability to create a new object to the class which works with the class of the object closely and aggregates all needed information

Controller:

Specialized class to controll the system flow, abstracting logic system logic away

## SOLID

- Single responsibility principle (SRP)

    a class should only to 1 thing

- Open-closed

    You can extend a module, but not change it

- Liskov substitution

    A Superclass object should be replaceable by a Subclass object and it should still work

- Interface Segregation

    No code should be dependent on methods / code it does not use,

    No class should implement interfaces / methods it does not need

- Dependency Inversion

    High level modules should not depend on low level modules, there should be an abstraction between them


## CRC card structure

Class Name

Responsibility / What does it do    |    Collaborators (classes, hardware) 