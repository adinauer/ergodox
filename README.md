Custom Ergodox Keyboard Layout
==============================

How to compile the layout to a .hex file
----------------------------------------

* You need Docker and Docker-Compose
* Run `docker-compose build && docker-compose run ergodoxcompiler`


How to install the layout on the keyboard
-----------------------------------------

* You need the teensy flash tool
* Drag the .hex file into teensy [https://www.pjrc.com/teensy/loader.html]
* Hit the teensy/reset button on your ergodox
* If nothing happens enable auto mode and the keyboard should flash and reboot

