# Project 2
To begin the timerLib directory, its files, methods, and make file are all the
same from the examples given by Dr. Freudenthal
The make file is ran the same except with the exceptions of adding my program
etc.

# To Begin
Project is seperated into 4 different directories. 3 of them you are all
familiar with as they are exactly as those Dr. Freudenthal gave us in the
demos.
BlinkBuzz contains my project which within has make file as well.

# Within BlinkBuzz
After running the make file in the previous directory (project), run make all
in the current directory.
From there make load to use with your msp430 plugged in of course
Make clean is also available for the make file

# Using Program
All four buttons are active each with their own pattern of LEDS as well as a
sound frequency with each state.
State 1 is Sw1 and so on for all four buttons

# Future Plans
Within the next few days an implementation of a song will be attempted as well
as the assembly portion of the code

# Sunday 4/5 Update: Pt.2 Assembly Switch Statements
Translating the first state of the state machine was not too dificult. By
default this application already has the state activated to work with the
assembly. HOWEVER, the assembly portion of the code seems to not work how it
is suppose to
A persistent error of internal error unsupported relocation error was given
and with various debugging and online research no solution was found. The
correct working section of state one is simply commented out so that is what
the assembly is suppose to do.

# Update 4/14
Assembly has been fully implemented, error was corrected thanks to
Dr. Freudenthal. The correction was done with an align 2 after n is "declared".
