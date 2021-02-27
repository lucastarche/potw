# Note: This project was sanitized to be more SFW
import pyttsx3
engine = pyttsx3.init()
def say(text):
    print(text)
    engine.say(text)
    engine.runAndWait()
    
while True:  
    engine.setProperty('rate', 200)
    say("it's modified fizz buzz time, forker")
    say("let's fricking do this")
    say("enter 2 numbers, bruh")
    tastyNums = input()
    tastyNums = tastyNums.split()
    listofstuff = []
        
    for m in range(int(tastyNums[1])):
        say("enter another number and a word, bruh")
        tastierNums = str(input())
        tastierNums = tastierNums.split()
        listofstuff.append(tastierNums)    
 
 
    engine.setProperty('rate', 300)
    
    for n in range(int(tastyNums[0])):
        currentNum = n + 1  
        out = ""
            
        for a in listofstuff:
            if currentNum % int(a[0]) == 0:
                out = out+(a[1])
                    
        if out == "":
            say(currentNum)
        else:
            say(out)
 
 
    engine.setProperty('rate', 200)
    
    say("Do you want to exit or do it again?")
    wannaDo = input("(E)xit or (A)gain?")
    
    if wannaDo == "E" or wannaDo == "e" or wannaDo == "EXIT" or wannaDo == "Exit" or wannaDo == "exit":
        break
    elif wannaDo != "A" and wannaDo != "a" and wannaDo != "AGAIN" and wannaDo != "Again" and wannaDo != "again":
        engine.setProperty('rate', 1000)
        say(("error error error error error error error "+
            "error error error error error error error "+
            "error error error error error error error "+
            "error error error error error error error "+
            "error error"))
        engine.setProperty('rate', 200)
        say("What the frick is wrong with you? Never feed"+
            "me bad input again. Bye.")
        break
