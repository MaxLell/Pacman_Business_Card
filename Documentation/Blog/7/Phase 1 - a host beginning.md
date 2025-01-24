In the first milestone, I create the AI and Pacman on the host platform. 

For embedded machine learning applications this is usually the case. You train the Neural Networks on a performant host platform and then port the trained model to the embedded target. 
The reason for that is that the training is a computationally expensive task and therefore it would take much longer to perform this task on the embedded target. 
On the other hand: running a trained neural network is pretty straight forward also on the embedded target. So this is the reason why I am building the game and the AI on the host first. 

While writing the previous blog article [[How can I eat an elephant? - about System Architecture]], I identified 4 Software Components:
1. The game runner
2. the Pacman game environment

