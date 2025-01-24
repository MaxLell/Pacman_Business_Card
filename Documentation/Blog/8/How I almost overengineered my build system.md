FIRST STOP: BUILD SYSTEM

![[9ho9zb.jpg]]

C and Cpp have the nasty characteristic that you can't just start to write code ... no you first need to think about how you need to set up the build system so that you can compile and run your code. 

I found myself diving deep into all different kinds of aspects of those build systems, but  "THIS IS SO EXCITING - THINK OF ALL THE POSSIBLITIES". And off I went into a rabbit hole of figuring out the "ins" and "outs" of build systems. I quickly realized that this is way over the top for what I actually need to achieve.

I already immersed myself in how to create a build system for 
- Building the application on the Host + Tests
- Building the application on the embedded target + Tests
- integration of the build system into a docker container so that I can run it with GitHub Actions automatically, when I push a new version.
- Fully integrating it with Plugins into VSCode (my development environment)
- Flying a spaceship
- Writing my entire code base in make instead of Cpp (I think you could that ... there are people writing doom in excel, so why would I not be able to do it in CMake and Make??)

I looked into a lot of bells and whistles that CMake has to offer. Eventually I got the tingling feeling that I am going way beyond what I need for the current milestone. This is yet another reason why some project preparation is such a valuable task: It shows you when you travel too far into the weeds. Before you can create a build system, you first need to understand how you need to build your code so that it can be used in the system context. 

And that is that. I try to follow the YAGNI principle there. Eventually the build system will become more complicated, but I would rather have the need to develop it, then implementing complex features, without anyone needing them.

In the next blog, I will dive into the actual build system.
