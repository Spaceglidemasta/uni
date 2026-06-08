# Exercise 7
## 1

#### Mainframe
The Mainframe model aims to have most if not all computing power on one singular system, which then has very thin input & output sources (terminals), which are used to interact with the mainframe. 

Example: Banks, which used to have everything centralized on the local server, which money input / withdrawl only beeing possible on ATMs which only render UI and send / recieve requests. Almost all computing power was on the local or (inter-)national server.

#### Cloud model
The Cloud model uses multiple, __distributed systems__ to operate. In this model, the service is split over multiple different systems, which oftentimes include devices from the user itself.

Example: Videogames, which store important states like player position (unprecise) and player currency values on the server, but keep ever-changing data like player position (precise), graphical aspects like texures and shaders or view of direction (precise) on each of the clients machines, which also use computing power to support the main server. 

#### Changes
This changed over time so dramatically for multiple reasons. One of them is, that Mainframes where never designed to support hundreds of millions of users. This however, was never an issue for cloud services, as they use computing power from each client.

$\rightarrow$ Better scaling, faster execution, less upfront hardware cost

This got even better for cloud services, when the average device each user used got stronger and stronger computing power over time, which could be used to keep more computing weight on the user, and not on the main server.

Also, because every person has access to multiple independent devices which __could__ connect to cloud services, the demand for said services grew and grew.

## 2



## 3

#### Amazon SQS

![]()

## 4

On the 7th of June I searched for an explation for why my python virtual enviorement wasnt working with Tensoflow and keras. I searched for an explanation for one hour, bombarding chatgpt with prompts and error logs. 

The problem was the deprecated library requests, which I never noticed or mentioned, but was always visible in the provided error logs.

Despite this effort, it was I who noticed this error and fixed it, while ChatGPT was giving me false effort like "reinstall ur venv for the 3rd time".

The problem here is that the LLM only looked at things I specifcally mentioned, instead of searching for problems in deeper layers of abstraction.
