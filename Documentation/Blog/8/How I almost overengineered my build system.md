
So the first thing is building the pacman game. But before I can actually write Software I need to create a build-system for proper compilation of the project and its tests.

I found myself diving deep into all different kinds of aspects of those build systems, but I quickly realized that this is way over the top for what I actually need to achieve.

For the current time being I need a build system that:
- compiles the tests
- compiles the main application

I already immersed myself in how to create a build system for 
- embedded hardware compilation
- integration of the build system into a docker container so that I can run it with GitHub Actions automatically, when I push a new version.
These things MIGHT be needed in the future, but what I try to follow is the approach: "Need to nerd". It is basically the same premise as the "YAGNI" principle. Only do what you need at the current time being. You can always make it more complicated and polished later on, should the necessity arise. 

So for the current time being, I am only using a build system that can build a basic Cpp project with its Unit Tests.

Again, I also thought about starting the build system from scratch - since this is a topic that I also want to become familiar with. But the reality with most development is, that you do it once properly and then for every other project you just copy paste it in and then adjust it from there. So in order to move fast, I decided to start with an existing template and not reinvent the wheel there. Along side adjusting it to my needs, I will learn more about this topic - AND THAT IS GOOD ENOUGH.

