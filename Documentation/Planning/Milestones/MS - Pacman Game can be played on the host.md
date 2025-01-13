# 1 Context
This is about the Pacman Game that is to be implmented on the host. A constraint that is to be considered is that the User Interface is to be separated from the game's logic itself. The interaction between the 2 shall occur via an intermediate Data Buffer or communication channel.

## 1.1 Goals
What is completed after this stage?
- Game can process inputs and generate outputs
- Game can be displayed on the host and keyboard inputs can be captured
- Both software components exchange Data

# 2 Design
## 2.1 Block Diagram
- Everything besides the AI Component ([[Diag - Pacman AI Game Block Diagram|LINK]])
- The Pacman Game ([[Diag - Pacman Game|LINK]])

## 2.2 What Frameworks and Languages shall be used?
What technologies / frameworks are to be used to also fulfill the learning requirements? ([[Req - Learning Requirements|LINK]])
- C++ for the Pacman Game development
	- CppUTest for TDD
	- CMake for the build system
- Rendering of the game in Python 
- Sockets / Queues / Pipes für den Data Transfer (TBD)
- Bash Script for launching the processes and setting up the communication between the scripts

## 2.3 What are the Pacman Game Mechanics?

## 2.4 Testing and Verification
- I can play the game with a regular keyboard on my platform
- Pacman can blink on the edges of the canvas.