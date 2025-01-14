- This shall be about the implementation of Pacman itself. This will result in several chapters each laying out different aspects of this

- I will describe the Build System
- I will describe how to set this up with a Docker Container
- I will describe how to run Unit Tests and how to integrate this with each other.

- I will describe the Game's Logic
	- [How the game works approximately](https://pacman.holenet.info/)
	- How the [Ghosts are working](https://gameinternals.com/understanding-pac-man-ghost-behavior)
	- What is the current high score is

- I will then discuss my code and how I went about the implementation

---

Wie soll ich jetzt weitermachen?
- Bevor ich mit der eigentlichen Implementierung anfangen kann muss das build system stehen
- Und das Spiel will verstanden sein und aufs wesentlichste kondensiert sein. 
- Ich will mal ein wenig Abwechslung reinbringen. Vor Allem hinsichtlich Build System
- Auch will ich endlich mal das Publishing vorran treiben.

--- 
Build System
1. Kompilierung vom Hello world und einem externen Module mit CMake in der Ordner-Struktur, die ich mir anlegen will.
2. Kompilieren mit CppUTest mit dem Hello World Project
3. Integration von Beidem in VSCode