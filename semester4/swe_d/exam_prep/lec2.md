# lecture 2 architecture

## software architecture definition

"organisatorial structure of a system or component"

architecture encompasses:

1. Components
2. Relationship between components
3. Legend / explanation

feedback loop:
Analysis -> Design -> Build -> tests -> run -> (back again)


## Architecture styles:

### Dataflow centric

seq. of data and ops: pipes, filters -> byte by byte, word by word, ...

### Data centric

shared data source: repository, blackboard, shared filed

### Hierarchical

Hierachal Layers, master slave, controllers that controll controllers, ...

    SimulationController
    ├── TrafficController
    │   ├── VehicleController
    │   │   ├── Car
    │   │   ├── Bus
    │   │   └── Truck
    │   └── RoadController
    │       ├── Road
    │       └── Intersection
    └── RenderController

### Dist. systems

Client-Server, Cloud arch. (network), ...

### Event-based

Calling each other via events

Message queue, observer pattern,

### Service oriented

Multiple small services that communicate trough standard protocols

cat actors.txt | grep "Tom " | uniq | wc -l

## MVC
### Model
state of the to be modeled object
sends .update() to View (observer pattern)

### View
Renders the object / model
sends user events to controller

### Controller
Controlls the model, maps user action to the model

Controller <-> View <-> Model <- Controller

### Blackbox

...


## 4 + 1 View model

logical View:
objects, classes

process view:
different processes inside the system, performance, scalability, seq diagram

development view:
Component / packages / modules

physical view:
server, hardware, deployment diagram, network

+1 User Case View:
End user, everything together, software as a whole