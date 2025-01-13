# 1 On exploding jet engines and critical bugs
Back in the day my uncle worked in the testing department of a jet engine supplier and they sometimes ran tests where the ran the turbines up to the point of self-destruction and they took measurements during that process. These engines would sometimes explode during these tests and after the experiments they would fish the engine blades out of the test bunker walls. So keep this in mind when I tell you about one of the first full projects I was working on when I stumbled out of university.

I was given the task of creating an entire embedded system from scratch. The system I had to build was a RC-Jet-Plane Engine Controller. 

(IMAGE of the RC Plane)

The engines, which are installed there work like real jet engines and they definitely require control over the fuel intake with respect to the current rpm of the engine. You can destroy these engines by having the RPM, temperatures too high. Same dangers as with the real thing. So this was the challenge I had to develop it. What person to do that then someone who is fresh out of university and having no real supervision on the project?

So I developed the first prototype on a breadboard and had the engine spin up to speeds, always having the power cable in my hand for the situation that I messed up something in the code or in the hardware. For said situation, I would have been able to shut down the system immediately. But that was it for the safety measure. It is not hard to tell, that I had some sweaty fingers when I plugged my "prototype" in and had it fire up the jet engine.

I was now able to verify my Proof of concept. And I had now to come up with a prototype (so a pcb and a more professional solution that went further into the direction of a real product). This is where everything went south.

