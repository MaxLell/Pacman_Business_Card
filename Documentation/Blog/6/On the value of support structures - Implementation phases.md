
When bridges are built, often support structures are needed to accomplish the task. Sure at the end of the day you have a bridge over a river, but you need to get it there in the first place. Often support structures are needed, which in of itself also need to be planned out and assembled. 

I follow the same approach for this project. Even though I want to run the Pacman AI eventually on the embedded target, I first need to train it. For that I am building such a support structure on my host computer. Here I can train the AI to then later port it to the embedded target. 

I broke the project down into 5 phases (at least for now - I might need to refactor this later on):

Phase 0 is the phase I am currently in. This is about the high level planning and getting a grip of the project

Phase 1 is called "A host beginning" which is about developing Pacman and its controlling AI on the Host platform. From personal experience I can say, that developing a software application is way quicker to be done on the host then it is directly on the target. 

Phase 2 - "Devkit Adventures" is about running the Pacman AI on a DevKit. Whereas phase 1 is about creating the Application software, phase 2 is about porting the software application on the embedded target. For that the existing code base will need to be expanded by the hardware drivers.

Phase 3 is about serious production: Now the project moves more to the hardware domain. I will create a PCBA for the business card and incrementally resolve all the remaining issues there. 

Phase 4 is about releasing the business card into the wild. That means actually using it on a tradeshow or a maker faire.

See? Easy peasy ... a simple 5 stage process. For now this plan is good enough to start. Of course it will need refactoring later on. 