For this project, I can't just head straight into the development of the final project. Some integral parts need to be developed first on the host platform. Such is the case for the AI that will eventually play the game. It first needs to be trained, which is very computationally expensive and only then can the trained "brain" be ported to the embedded target. So to sum it up, I can't immediately build the final product (embedded microcontroller application on a circuit board), but rather then that I first need to create a support structure in order to move further towards my goal. These support structures need the same attention as the final product itself. That means requirements, use-cases, user stories, architecture. 

(Insert Image of support structure)

Did you ever think of how the Romans constructed all these large arches that they have on their Aqueducts? They also used carefully planned out support structures for that matter. 

(Insert Image of Arch-supports for romans)

The used a wooden structure which made it possible to lay all the bricks to their destined location. Only after the final brick was inserted, the arc was complete and able to carry its own weight and also the weight of aqueducts. Without this contraption it would not have been possible to build these arches. 

I will need a couple of support contraptions in order to assemble the entire "Arch" - the Pacman AI Business Card. So for example, I will need the following support structures:
1. A system to train the AI: For that I will need the game and the AI running on the host for training
2. A Hardware development kit on which I can test and verify that it is actually working also on the target. These kits are usually cheap to acquire from the microcontroller vendors. They serve a good first step to port my Pacman AI implementation to the low level hardware. 
3. A PCBA which makes the entire setup more compact and which has the appearance and usablity of the final product. I will now move the already ported implementation to the final Hardware.

In order to keep track of the "support structures", I moved each of them into their own phases. I think in the agile context, you could name them epics. So these are the phases that I came up with:

- [[MS - Phase 0 - Project scope planning|Phase 0 - High level planning]] is the phase I am currently in. This is about the **high level planning** and getting a grip of the project
- [[Phase 1 - a host beginning]] is about developing Pacman and its controlling AI on the Host platform. Developing on the host is quicker and it also forces me to develop my baseline software hardware independent, so that I can port it later to the embedded target
- [[MS - Phase 2 - Devkit Adventures|Phase 2 - Devkit Adventures]] is about running the Pacman AI on a DevKit. Whereas phase 1 is about creating the Application software, phase 2 is about porting the software application on the embedded target. For that the existing code base will need to be expanded by the hardware drivers.
- [[MS - Phase 3 - Serious production|Phase 3 - serious production]]: Now the project moves more to the hardware design domain. The Pacman AI Software is already ported to a microcontroller. Now all hardware components from [[MS - Phase 2 - Devkit Adventures|Phase 2]] are ported into one proper circuit board.

See? Easy peasy ... a simple 4 stage process. For now this plan is good enough to start. Of course it will need refactoring later on. 