TLDR: Breaking it down from "insurmountable" to "big chunks" to "smaller digestible chunks".

# 1 Divide and conquer
The answer to the headline question: 
> "How does one eat an elephant?" -> "Piece by piece". 

Divide and conquer is the name of the game. I make it so small, that I can actually get started working on it. However I keep track of the other pieces too. 

I look at the project not only from the system perspective but I also think about in which increments (planing domain) I can build it.

The system perspective includes for me and for this project a component diagram, some pseudocode to understand how the application is executed.

The implementation domain is about how I can build this system in very high level terms. 

None of these steps are set in stone. This is just an approach which worked in the past for me.

# 2 System Perspective
## 2.1 Hardware Components
First I need to understand how this would look like on the physical business card - the embedded system itself. For that, again I create a block diagram, which shows all the relevant physical components on a high level.

![[Diag - Component System Block Diagram]]

Nothing fancy here for the current time being, but I do it anyway, just so that I get no surprises later on. In later phases of the project, I will revisit this concept.

## 2.2 Software Components
Next I need to learn which "Makro" Software Modules can achieve these [[Req - Software Requirements]] in order to implement the business logic:
![[(Diag) - Software Components]]
The Game Runner executes the entire flow - so it runs the Pacman game, runs the AI and the User Interface

## 2.3 Software Execution
For that I need a "Makro" Software Flow Chart, or what I personally prefer: Pseudo Code. (There is no real standard for how to write pseudocode - the represenation I am using works fine for me.)

![[PC - GameRunner]]

For the execution flow I follow the approach of the so called Game Loop implementation, which can work in the following way:
1. Initialize the system
2. Run the loop:
	- Fetch the inputs
	- Update the Game's state with these inputs
	- render the current Game State
## 2.4 Data Pipeline
This shows the Data Pipeline (how and when the most important data is read and updated in one iteration of the loop (see [[PC - GameRunner|Loop]])).

![[Diag - Data Pipeline Pacman AI]]

Basically we have 2 variables, which are accessed by 3 software components:
1. The Control Signal: This is the input that is used in the game to control Pacman's movement on the canvas
2. The environment: This is the current game state. It contains everything that is to be rendered on the GUI and all the inputs which are necessary for the AI to determine its next step 