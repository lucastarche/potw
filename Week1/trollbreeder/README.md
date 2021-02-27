# **FIZS**

## *Week 1 solution made in **ComputerCraft Lua***

### About it:

- Can handle spaces in modifier words (s_i)
- Can handle duplicate modifier words (s_i), duplicate modifier number (m_i), and both
- Tested with example input, matched expected output perfectly
- Can handle a large amount of numbers (n), but expect it to take its time if you input a really big amount, and please dont break your hand typing all of the modifiers
- Can handle really long strings for modifier words (try AAAAAAAAAAAAAAAAAAAAAAA)
- Can save output to a text file if so desired (the 10k EvenFizzBuzz was around 60 kb!)
- Press shift while fizzbuzzing to speed things up

### Wait, what's ComputerCraft? How do i run this thing? WHAT?!

Blablabla computer mod for minecraft and stuff. If you want to emulate it here's a quick guide on how

1. Download the **CCEmuX Launcher**. There are other emulators but this is the one i use and it's pretty reliable
2. It comes in a jar file, make sure you have java, ignore warnings about it being "dangerous"
3. Launch the launcher jar. If it asks you what version of computercraft to use, select **ComputerCraft: Tweaked**
4. A small window (called a computer) should now open on a text interface (called the shell). Time for some commands!
5. Enter `emu config` and set the resolution (in characters - yes welcome back to the days of MS-DOS and ascii art), select a different category like HTTP API for it to save, then close the config. Close and reopen CCEmuX. Repeat this step until the computer is in the resolution you want.
6. Enter `emu data`, a file explorer should now open in ccemux's data folder. Navigate to `computer/0/`. This folder contains everything that's stored on the computer you're on. Paste `fizs.lua` into this folder.
7. Enter `ls` - you'll see a list of files in the computer's root directory. `fizs.lua` should be among those files.
8. Enter `fizs`. You have successfully launched fizs. Follow the instructions, fizzbuzz output will be shown in light gray.
