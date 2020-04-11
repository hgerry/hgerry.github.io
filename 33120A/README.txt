How to upload arb data to 33120A
---------------------------------------------------
23:00 09/02/2020
This took longer than expected!

Note - the included Agilent function generator software is useful for drawing waveforms, but can't actually establish connection with an RS232 instrument.

1. Draw waveform using intuilink or calc in excel or python
2. End up with text file like

DATA VOLATILE,  .7880859375,  .4462890625,  .1259765625, -.11669921875, -.34619140625, -.52685546875, -.71142578125, -.80615234375, -.89111328125, -.93212890625, -.94970703125, -.96337890625, -.97216796875, -.97705078125, -.97705078125, -.95458984375, -.90478515625, -.86474609375, -.76123046875

n.b. you can open a csv in notepad++, do a line operation to flatten to a single line

3. Setup 33120A to 1200 baud (slow enough that input buffer won't overflow, no joy using hardware flow control)

4. Use realterm to talk to func gen. Set both realterm and windows com port settings to:

baud 1200
parity none
data bits 8
stop bits 2
hardware flow control none

Make sure you use com port 1 or 2

5. Open com port in realterm, on misc tab try sending *IDN? to see if you can talk to func gen. You should see data going out on RXD indicator.

6. Send ASCII commands (+LF should be selected)

SYSTEM:REMOTE
APPL:USER 10000, 1.0, 0.0

7. Send file

Use "Dump file to port", then send

8. Send blank line (i.e. "Send ASCII" with nothing in field), just so you send the write line termination chatacter

9. Finally, a couple of commands to output waveform:
FUNCtion:USER VOLATILE
FUNCtion:SHAPe USER




Notes:

It can be useful to read errors back from the unit, with SYST:ERR?
There can be multiple errors, multiple reads will unload them individually from the buffer.