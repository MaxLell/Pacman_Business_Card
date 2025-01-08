# 1 Functional Requirements
## 1.1 Pacman Game Requirements

| Req ID | What do we want?              | Criticality | Rationale                                                             | How to verify?                                                      |
| ------ | ----------------------------- | ----------- | --------------------------------------------------------------------- | ------------------------------------------------------------------- |
| 4333   | Pacman Game playable          | Mandatory   | [[US - Playing Pacman]]<br>[[UC - User plays pacman on the card]]     | Game can be played on the device                                    |
| a3e9   | Pacman game plays itself      | Mandatory   | [[US - Toggling Pacman AI]]<br>[[UC - User plays pacman on the card]] | AI can play game itself on the device                               |
| 22bb   | Highscore for the player      | Optional    | [[US - Highscore System]]                                             | High score can be entered and is still available after restart      |
| 3644   | Highscore with the help of AI | Optional    | [[UC - Highscore with the help of AI]]                                | High score entry has a tag attached, which shows the help of AI     |
| 08f3   | Smooth gaming experience      | Mandatory   | [[UC - Smooth gaming expierience]]                                    | Timing on the target platform can be evaluated with debugging tools |

## 1.2 Handling Requirements

| Req ID | What do we want?                           | Criticality | Rationale                                                                   | How to verify?                                                                                                                                                                         |
| ------ | ------------------------------------------ | ----------- | --------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 2989   | Card must be pocketable                    | Mandatory   | [[US - Card shall be pocketable]]<br>                                       | 5 cards can be carried in one trouser pocket                                                                                                                                           |
| e0d6   | Contact Information Display                | Mandatory   | [[US - Contact Information display]]<br>[[UC - Contact info can be passed]] | - QR is displayed<br>- When the card is shaken the contact information is displayed as a Name / QR Code<br>- the card holds a QR Code of the contact information on the PCB Silkscreen |
| e583   | Field Self Test                            | Optional    | [[US - Preshow Autotest]]<br>[[UC - Final Field Tests]]                     | Device gives a go/no-go indication                                                                                                                                                     |
| ebff   | Card shall not be enabled by accident      |             | [[UC - Prevent Self-activation]]<br>[[US - Prevent Battery Drainage]]       | A card shall be carried around for a couple of days in the pocket.                                                                                                                     |
| 2589   | Card remains useful after being handed out | Optional    | [[US - Card remains relevant]]<br>[[UC - Not only paperweight]]             |                                                                                                                                                                                        |
|        |                                            |             |                                                                             |                                                                                                                                                                                        |

## 1.3 Business Requirements
| Req ID | What do we want?                                           | Criticality | Rationale           | How to verify?             |
| ------ | ---------------------------------------------------------- | ----------- | ------------------- | -------------------------- |
|        | Business Card shall be quick (less then 2 Min) to assemble | Mandatory   | <br>                | Measured with a stop watch |
|        | Total costs per card shall be less then 20€                | Optional    | [[UC - Many Cards]] |                            |

# 2 Learning Requirements
| Req ID | What do we want?                 | Criticality | Rationale                                                                                  | How to verify?                                                                                           |
| ------ | -------------------------------- | ----------- | ------------------------------------------------------------------------------------------ | -------------------------------------------------------------------------------------------------------- |
| 009b   | Learn a new programming language | Mandatory   | [[US - Learning new skills]]<br>[[UC - Technical topics worth exploring]]                  | The product is built with these technologies                                                             |
| f35c   | Learn Project Management         | Mandatory   | [[US - Learning Project Management]]<br>[[UC - Project Management exploration]]            | I can pick up the project and start working on things right away, without                                |
| 6a1c   | Learn Blogging                   | Mandatory   | [[US - Learning to Blog]]<br>[[UC - Blogging]]<br>[[UC - Marketing Potential of the blog]] | - Blog Articles are regularly published on my webpage<br>- A couple of people have read my blog articles |

# 3 Marketing Requirements
| Req ID | What do we want?                                                         | Criticality | Rationale | How to verify?                                        |
| ------ | ------------------------------------------------------------------------ | ----------- | --------- | ----------------------------------------------------- |
| 0c28   | Owner shall be knowledgeable when presenting the card about its features | Mandatory   |           | Elevator Pitch about the card is possible (2 minutes) |
