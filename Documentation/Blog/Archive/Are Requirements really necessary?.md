7 years back, I started to work on a project. The task was to build an engine controller for a RC-Plane Jet engine. Pretty niche application, but this is very common for embedded system. 

We came up with a small proof of concept for this engine controller (a lot of breadboards and loose wiring screwed onto a wooden board), which showed that in theory that this project is feasible. We did not specify any requirements but rather then that we working with an ever-expaning wish-list of the customer.
Rather then reflecting on exactly what we had to build a lot of ideas were constantly floating in the room:
- "We need a BLDC Controller there on too, because the expensive pumps also need one" - so we added an extra microcontroller to stem this "easy" task.
- "We also need an embedded GUI on which we can see all the relevant settings" - say no more - noted
- "We need a disconnection detection" - sure as hell we do.
We also received a ton of new feature requests every time we went there.
Since the instruction from the top was: "the customer is king - do as they tell you", we crammed everything into the next prototype. 

The result: we tried to do it all and we failed. The project was canceled after we blew the schedule and the budget, even though the first features started to come to live.

So how could we have saved the project from a technical perspective?
- We should have defined EXACTLY the most important features for the next iteration of the product
- We should have understood these features as much as possible and document these. (Hint: These are the requirements and the software architecture)
- We should have focussed on shipping Minimal Valuable Products (MVPs) rather then trying to ship the entire thing all at once.

In the upcoming section, I will discuss how to come to the MVPs, how to derive Requirements, and when is it enough?