```
GameRunner {
	Init
	Game Loop
}
```

```
Init {
	init the AI
	init the UI
	init the Game
}
```

```
Loop {
	if (Human Input enabled) {
		get control inputs from the UI
	}
	else // AI Input enabled {
		get control inputs from AI (which uses the previous game state)
	}
	
	Update game state with the control input
	
	if (rendering enabled) {
		Render the game state to the UI
		Wait for the right amount of time to satisfy the FPS
	}
}
```