# HelixAntennaCamera

This Repository contains Files for a self-made Helixantenna which, if build corretly is abled to detect WLAN (2.4Ghz) and display the intansity of the signal on a Monitor.

# How to get started

We will use a Helixantenna to catch the WLAN wavelengths. You can use another type of Antenna, but a Helixantenna is quite praticall. A Helixantenna is directonal, if we get a signal it always comes from a specific direction. This makes the Coding of the Camera script way easier.

<details>
 <summary>what do you need?</summary>
    - Copperwire <br>
    - Copperplate <br>
    - Cylinder/Tube <br>
    - Circular shaped plate <br>
    - Satellite finder <br>
    - Arduino <br>
    - Powersupply (for the Arduino and the Satellite finder)  
</details>

__Dimensions:__ Go to the following Website: 

https://www.changpuak.ch/electronics/calc_12a.php 

and enter the specs you need, this should give you all the measures you'll need.
I entered the following specs:
```
Freq. [MHz] = 2000
Turns n = 8
```
if λ [mm] = 150.00 Wavelength, then you should be good to go. 

# Building the Helixantenna

I recommend watching a Youtube video of how to build a Helixantenna. I will just cover a few tips you should keep in mind and how to connect the electronics. 

<h4>Tips</h4> 

1. Before you start with the building process make 100% sure that your copper parts are made out of copper and not just coloured like copper. I've made the mistake twice and let me tell you, Aluminuim does not work... <br>
The easiest way of making sure that your copper is made 100% out of copper is to scrape into it. If the inside color is silver'ish you know, that you bought the wrong Item. <br>

2. Befor soldering the copper, scrape into it. Many copper elements got a layer on top of them which makes it hard to solder the element. 

3. There are many fancy SDR modules which you can plug in to your PC and read the signal from your antenna. But those are usually super expensive. I recommend taking an old signal finder. They are cheap and work really well, because the usall TV antenna converts the wavelengths it reseves, to a 2Ghz signal.

<h4>Connecting the parts</h4>

Let's first prep the signal finder.<br> <br>
Open the signal finder up and search for the speaker. It usually looks like a cylinder shaped knob. If you cannot find it, you can also look for the processor (I don't mean the display processor). Now power the signal finder and turn on the sensitivity wheel. It should make a noice if you max it out. know you need to be patient. Measure the volts of every contact next to the speaker/processor and write it down. Turn down the sensitivity, so the sounds stops and check the contacts again.<br> 
If you find a contact which changes the volts everytime when the sounds goes on and off, congratulations.<br>
Solder a wire to the contact and connect it to the Arduino. Use "Analog in" (A0 - A5) to contact the your wire to the Arduino.

# Using the Code

You probably wont need the "Arduino-Schloss" file. It contains a little script for 2 servo motors, which locked my portable WLAN-Camera modual. <br><br>
Open the "Arduino-Kamera" Directory. Load the "Arduino-Kamera.ino" file to the Arduino. You may want the change the Analog in pin. <br>
start the "Kamera.py" on your Computer. 
