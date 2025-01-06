# A business card with AI you say? Shut up and take my money!
TLDR: Building a physical business card on which either you or a Neural Network play Pacman

(MEME IMAGE OF "SHUT UP AND TAKE MY MONEY").

## Learning
New year, new ... project - I guess. As I grow more mature as an embedded systems engineer, I find it more and more helpful to build a project for the sake of my own education and sharpening of skills.

I do not find it motivating to go through tutorials and read through books just for the sake of doing it. To which end am I doing this? "Consuming" a course (like coursera, udemy) and going through their cookie-cutter projects is not sufficient (at least for me) to grasp what is really going on. I need to toy around with these concepts on my own in order to really understand and learn these things.

Having a concrete problem against which I can compare my efforts against, offers me a solution to this problem. In this way, I am able to close the feedback loop and also check that I actually understood and learned the topic. Imagine you try to lose weight, but you do not have a scale. You can't progress, if you do not know whether you've already lost some weight in comparision to the week before. Same is true for knowledge and learning. Without testing it against a real scenario, you do not know what your head captured and what holes you still have in your understanding. This is why I am using a practical project for shining light into the gaps of my understanding and this is why I am launching this series. 

I also chose it explicitly as something that is not really useful. I work on useful stuff already in my day-job - and this is really more about playing with the tools, without having the restrictions that you would have with a commercial, "useful" product.

## Why Pacman?
Pacman is a fairly complex game for that matter, and since this is also a learning project for me, I do not want to build another cookie-cutter project. For the sake of stretching myself, I want to move away from my home ground (the C-Programming language) to Python and C++ for the implementation (Along the way, I will most likely need to familiarize myself with many more things).

So now you might ask, what is the project about?

## Pacman AI
Yep, you are goddamn right about that.

For this project, I want to create a physical business card, that I can hand out on trade shows, meetups, conferences, MakerFaires.... on which you can play Pacman on a small display. Furthermore I enjoy seeing systems solving problems by themselves. For that matter I want to add an additional button on the card, which toggles an "AI" which beats the crap out of the ghosts, if the user chooses to. 

Later I also want to create a physical product - somethings that I can actually hand out. 

This blog series shall serve as my record in the endeavor of building this thing. I will basically record all the steps that I am taking and my reasoning behind it. You can breathe over my sholder observing every step, I am doing. So far I did not find a lot of well documented embedded software projects, which take you all the way from the initial small beginnings to the very end of the shipment of the product, and I always wanted to follow along such projects - this is why I am creating one for myself.