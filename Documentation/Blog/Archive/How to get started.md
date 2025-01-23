# 1 How to get started?
TLDR: How do you start to translate the idea of a Pacman-AI business-card into something real?

"I want a business card on which the user shall be able to play pac-man" - All right, that's cool but what does that even mean? What we need is to characterize the system in a more detailed fashion so that we can start to build it from the bottom up. But you can't characterize everything from the very beginning. You need to find an entry point into narrowing this vague idea into something tangible.

There are many steps involved there, but for the start:
- I want to know how the product shall look like.
- I want to know how the product can be used.

## 1.1 How can I learn how the product shall look like?
For that I am doodling a lot on my tablet and create a couple of visual mocks. The current version, I will pursue for the project at the moment looks like as follows.

For answering both these leading questions, I usually go through several iterations. Most often I have the best ideas or answers to these questions, when I am doing something completely different (for example under the shower). 

For the Pacman business card, I came up with the following initial concept:

(ADD IMAGE HERE)

Beautiful, I know ... but its a start.

## 1.2 How can I learn how the product is used?
I usually create multiple identities / stakeholders / users and then imagine how they might use the business card. I create Use Cases. By doing this, I can shine light on things that I would otherwise not have anticipated. I go through a couple of examples how these things might play out. What I am doing is basically creating a vision of the product and then I reverse-engineer in the upcoming sections in ever more detail how this needs to be implemented in order to fulfill this vision.

Just to give you a short example how this might look like: In this use case the user wants to play the Pacman game manually on the business card. For this the following sequence happens:
1. User presses the "Power-On" Button on the edge of the board (the switch is slightly pulled in so that it does not get triggered by accident)
2. The system powers on and my contact information comes flowing in (like the Nintendo Logo on a Gameboy)
3. The system puts the user into a menu, in which he can start a new game when the game was started the ghosts are only spawned 2 seconds later, so that the user has time to familiarize himself with the environment
4. The user then plays the game (and loses eventually - the ghosts are real predators and the user has entered wolf territory by playing this game)

This can also be showcased using flow-charts or use-case diagrams. I personally prefer a more written approach. If you are curious how this might look like, have a look at the repo, where I collected a bunch of these.

## 1.3 Where do we stand now?
We now know how have a rough idea how the product might look like and how it might behave. 
Now for regular products you would ask: Does it still make sense to pursue the development of this product?

Since for me this is a technical learning project and not so much something that is actually useful, I will continue