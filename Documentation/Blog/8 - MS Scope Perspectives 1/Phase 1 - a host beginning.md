As mentioned in the [[On the value of support structures - Implementation phases|previous article]] Phase 1 is about the creation of the Pacman Game and the AI, which will eventually control the game.

I will start with the implementation of the Pacman Game. But before I do that, I first again need to understand what it is EXACTLY that I am going to build. The game does not stand by itself. 

It also needs to be embedded in the context of an AI agent controlling the game. So I need to craft the interfaces for that too. 

I also want to be able to play the game for myself, to verify that the game is actually playable and what the AI shall be trained on. This is like an integration test, where my manual "labour" verifies the game's proper functionality. This is a very fancy and technical term for me playing a couple of Pacman Games. Life is tough man ...!

So again there are a couple of things to consider first, before I jump into the code editor. In the [[Software Architecture - Pacman Game|next article]] I will investigate those things in more detail. Probably while creating the software architecture, the interface spec and the execution flow, I will learn a couple new things about my existing requirements, so I will again update these. 

