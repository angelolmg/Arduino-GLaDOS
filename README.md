# Arduino-GLaDOS
A prototype animatronic of GLaDOS (from the game Portal 2) that uses voice commands to control different outputs.

It's pretty straight forward.
The main components of this project are: the Arduino UNO, Voice Macro and a simple python TCP server.

Voice Macro listens your voice and can bind different spoken words to actions on the computer (macro).
I'm using voice commands to open client scripts, that call for commands on the server.
The server listens to those commands and talks to the uno to control outputs, like toggling LEDS.

Voice Macro also allow you to play sounds, hence the "Sounds" folder. The profile with the commands 
can be found here as well.