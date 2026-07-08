# lecture 4

## modular decomposition
\*modular programming\*

## SoC

seperation of concerns into single modules

Apply SOLID princriple

### Cohesion

do the methods of a class fullfill the same purpose / do they cohese together

### Coupling

Coupling between classes -> observer pattern is low coupling

#### Afferent coupling 
->  external classes depending on this module

#### Efferent Coupling
->  external dependencies

I = $\frac{EC}{EC + AC}$

1 is unstable

## Law of the Demeter

dont invoke random stuff completely outside the scope, who does this anyways

## Encapsulation Principle

complex systems should be encapsulated / abstracted away behind classes, no other object should need to interact with the core internal details of another object.

Observer pattern, pipes, getters, setters, initialisers / constructors, ...

## DIT Depth of Inheritance Tree

low number = less dependent & less error risk, but you need to write more code from scratch

high number = you can use parents methods & attributes and need to write less code, but more dependency & error risk

