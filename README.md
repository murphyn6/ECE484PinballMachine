# ECE484PinballMachine
Pinball Machine Project Designed by Parker Murphy, Frederick Levins, Jacob Bowens, and Carlo Buelvas


This repo is the central location for work contributed to the overall team project of Miami University Spring 2024 ECE 484 Class Final Project. The project involves development of a baseball themed pinball machine with the objective of successfully creating a fun and enticing game that is playable by all common pinball players. The project involves design, development, and integration of various functioning systems within the complete pinball machine, which allows for simulation of a real life industry system development cycle and project. As whole, this allows for us to be able to practice applying individual skills to a team orientated project which teaches us important skills ranged in communication, development, and team-work preparing us for the future in industry and allowing for us to explore and develop our team and individual skills.

Allocation of jobs and increased integration aspects:

Fred - Gamefield

Development 
- Combination of various sensors and buttons with intent to be used as "triggers" for interaction, responce upon completion of game designed goals
- Buttons to be used upon applied pressure from ball to signify a point increase and flasing of LEDs/LCD screen prompt
- Motion Sensors (infrared, microwave, PIR) to be able to detect motion of ball in correlation to field for stats of distance of "hit" and rewards correlated
- Pressure Sensors are considered as well to make "outs" where a player hits a pre determined spot to lose points/balls - under consideration due to cost and complex
- Interaction compiled through Arduino or possible RSBPI
- All development and component usage is possible to change during testing and implementation cycle depending on prefernce and strenght of each item

Integration
- Implementation onto to field using the base of the game machine: buttons in back to get hit, motion sensors along sides to track and detect motion
- LEDs and responce will be placed in various locations to celebrate success and give player feedback
- The outcomes and prompts will be baseball centric and correlated to the them to continue continuity and game design.

Parker - Multiball Feature
The plan for this design piece is to create a multiball mode for a larger pinball project.
This will be achieved using an Arduino Uno R3, two servo motors, cardboard, two touch sensitive buttons, and an infrared sensor.

Once both buttons are hit by the pinball the outer servo motor will raise the gate of the "Multiball Area".
After that the ball must be hit into the "Multiball Area" in order to trigger the infrared sensor.
Once the infrared sensor is triggered the outer servo motor will close the gate while the inner servo motor releases the second ball into the "Multiball Area" with the first.
Then, after a moment has passed, the first servo motor will reopen the gate and release both of the balls.
Currently the extra ball will have to be manually placed back into the "Multiball Area" between each play.
Multiball mode is a must-have for any exciting pinball machine. It gives the player something extra to keep up with. It is a little extra challenge for a chance at a greater reward.

Carlo - Paddle and Ball Return System

Jacob - Scoring System/ Display
Please also reference prior individual submissions for overall ideas. 

Design
Focuses on adding to UX and appealingness of continued play
- Cubs theme
- Ivy background and baseball diamond
- Score noises correlated to locational successes and multiball
- Raspberry PI/Arduino used to play sound effects and Go Cubs Go at certain threshold win

*all aspects of design are first to go if project timeline starts to fail because functionality is more essential*

Each individual is tasked to specifically focus on their aspect while also supporting the integration and development of the project overall. The estimated timeline is described below

Rough Timeline:

Begin: 

Start: 03/03/24

Revised Proposal: 3/10/24

Finished Physical Setup of Machine: 3/14

Design and Layout Finished: 3/24

Spring Break: 03/25-03/31

Group Check In on Individual Development: 04/03

(1)Second Group Check In on Individual Development: 04/12

(2)Third Group Check In on Individual Development: 04/17

(3)Fourth Group Check In on Individual Development: 05/01

Final Integration and Testing of Machine: 05/01-05/08

Report, Demo, and Submission: 05/09-05/15

Hard Deadline: 05/17

(1) We will focus on checking in on progress, offering support, and wholly considering the further steps of integration. The most important aspect is focusing on staying on time.
(2) This is more trending toward complete finalization of each individual component. We will begin integrating our aspects.
(3) Finalization of integration and begin testing of overall play and success. Look more depthly into continuity and making sure the game has a fun and useful function. This should be near complete for entire project.
