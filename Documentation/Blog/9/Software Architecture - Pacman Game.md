So now that the organizational stuff is handled lets dive into building the [[MS - Pacman Game can be played on the host|Pacman Game]], an integral part of [[MS - Phase 1 - A host beginning|Phase 1]]. 

So now I am at the point, where I do not know how Pacman is to be built. In order to do so, I need to understand the following points:

1. What is the context of the game? So how is it interconnected into the Pacman AI Business Card 
2. How does the Pacman game actually work - what is the logic behind it? 
	1. How is the game executed? - what is the sequence of steps?
	2. What objects are there most likely and how can I organize them into groups?
	3. How can I reduce dependencies between the software modules or objects?

I use Software Architecture diagrams and pseudocode to understand how things are supposed to work. It is way quicker to "prototype" with diagrams then it is to write the code right from the get go. 
I usually stop and jump into the implementation when I am confident to implement the software. However as it is always the case, when you are creating diagrams, you might miss things - these are just a quick concept. It happened to me before that I had the nicest looking architecture but in reality things were way different. THIS IS PERFECTLY NORMAL. None of us expects all the roadblocks there are. The only way around such a roadblock is to do an additional iteration.

So now that this is out of the way, lets dive right in. 
# 1 How Pacman works in high level terms
If I understand it correctly, then Pacman is a game of agents. 
- You control one agent - which is pacman, whereas the computer controls 4 agents - the ghost instances that chase pacman around in a maze. 
- Pacman (the player) wins, when he ate all the pellets on the field. 
- Pacman (the player) looses when Pacman touches one of the Ghosts (execept he found a power pellet).
- The ghosts go through different modes themselves. They alter between: Chase, scatter, caged and fear mode. These modes are altered by the game, or when Pacman eats a power pellet.

# 2 Context of the Pacman Game
![[Diag - Pacman AI Game Block Diagram]]

The Game environment needs to be exposed to the outside world. Therefore this is to be taken into account. The "outside world" (Game AI) needs to be able to see the entire game environment, so that the autonomous Pacman Agent can learn properly.

# 3 High Level Flow
I am using the concept of the game loop for that matter here. Furthermore I am using some Pseudocode instead of diagrams to show the steps that roughly happen after each other.
```
Game {
- Init
- Loop
}

Init {
- Init the environment
- Init Pacman
- Init the Ghosts
}

Loop {
- Fetch Keyboard Inputs
- Update the Game State
- Generate outputs (Logging, GUI, Public external interface)
- Wait for the next iteration
}
```

# 4 Model View Control
## 4.1 Overview
Model View Control can be used for that matter. The way, how I like to use it is to have the data and the functions that interact with it separated. Furthermore I also keep the interface to the outside world at another place. This helps with reducing decoupling at that point. Later this will become handy, since I will need to expand the game heavily. By using this architecture approach, I can do so, and will only require minimal changes in the view component. 

![[Diag - Model View Control Pacman Game]]

- Model -> this will be the object, that holds the game's data. I called it "the environment".
- Control -> these will be the actions that the agents of the game are doing
- View -> this groups the functionality that exposes the game to the outside world. That can be the rendering on a GUI or the Terminal. 

I can now decompose this high level groups into classes:

## 4.2 Model
This is the data pool for the entire game. It holds all the information at one place. Having the data floating all over the place in different classes and having copies there makes it difficult to maintain.
Having the data at one central place makes it easier. So this is a fairly powerful class. And since we all grew up with the teachings of Uncle Ben: ![[Pasted image 20250123184434.png]]
I will add some Interfaces that only expose the right data to the respective classes. So for example the ghost will not be able to read or write into the variable that contains the coordinates for the pellets.

- The **environment** - holds the entire game state: 
	- **Agents**
		- Pacman: coordinates
		- Ghosts: coordinates
	- **Maze**
		- This holds the wall coordinates of the maze (maze)
		- the pellet coordinates
		- The super pellet coordinates
	- **Game**
		- Current User Input
		- the current game score
		- the amount of lifes (attempts) that Pacman has
		- The current game mode
- **Interface Objects** that only expose certain aspects of the environment to the ghost class and the Pacman class. Furthermore this reduces the coupling of the objects.

## 4.3 Control
This group houses the game's logic. So that means the functions that act on the data, which is stored in the model.
- **Agents**
	- **Pacman** - this contains the player's functionalities: 
		- Handles Pacman's movement based on the user input
		- handles the collision detection with the ghosts
		- Updates the Score if a pellet was eaten
		- Updates the Game State when a super pellet was consumed
	- **Ghost** - this class contains the functions for the ghosts
		- Determine the target location to which the ghost is aiming at 
			- This is based on the current game mode
		- Handles the Ghost's movement for the next increment (A* Algorithm)
- The **game** - this executes the game
	- this holds the game loop that executes the game
## 4.4 View
This is about rendering and exposing the game's data to the outside world
- **GUI**
	- Renders the game environment to a graphical user interface
- **External Public Interface**: Exposes the environment to the outside world (Inputs and outputs)