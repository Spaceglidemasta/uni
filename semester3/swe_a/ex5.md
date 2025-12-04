# Exercise 5

## 1
- The Bank Server is not an Actor
- There is no connection between the receiver
and the rest of the Diagram. There should be a line connected from the second block of Bank Server to the reciever, starting notifyMoneyTransfer()
- bankingApp.startServer() is not supposed to <\<destroy>> the Bank Server
- the (X) under the second block of bankingApp is wrong, as the timeline is not supposed to end there. Also:
    + 17.12.6 DestructionOccurrenceSpecification ... 17.12.6.4 Constraints
    no_occurrence_specifications_below
    No other OccurrenceSpecifications on a given Lifeline in an InteractionOperand may appear below a DestructionOccurrenceSpecification.
- There is an unconnected line at the bottom of bankingApp
- receiver has an unconnected activation bar
- bankingApp.startServer is started directly at the beginning of block 2, which is confusing. What does the block do for the rest of the time?
- Why is Actor.startApp a discrete line? It should be continuous with an open arrow-head, symbolizing an asynchronous message, as the process of starting the app as an Actor is of undefined / trivial lenght.
- Actor.enterReceiverAdress should have a filled arrow-head, as its not asynchronous and needs to be awaited.
- The arrow and block over bankingApp.stopApp should not be there, as they serve no purpose and / or meaning.
