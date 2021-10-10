import simpleaudio as sa # audio functionaliteiten
import inquirer # user input functionaliteiten
import time # time

kick = sa.WaveObject.from_wave_file("../samples/Kick.wav")
snare = sa.WaveObject.from_wave_file("../samples/Snare.wav")
hihat = sa.WaveObject.from_wave_file("../samples/Hihat.wav")

kick_event = {
    'filename': kick,
    'instrumentname': 'kick',
    'timestamps': [],
    'duration': 100,
    'velocity': 127,
}

snare_event = {
    'filename': snare,
    'instrumentname': 'snare',
    'timestamps': [],
    'duration': 200,
    'velocity': 127,
}

hihat_event = {
    'filename': hihat,
    'instrumentname': 'hihat',
    'timestamps': [],
    'duration': 300,
    'velocity': 127,
}

bpm = 120
noteDurations = [0.5, 1, 2, 1, 2]


# def bpmchoice(): 
#     #functie voor de y/n vraag voor bpm
#     bpmChoice = input("Default BPM is set to 120, would you like to change the BPM (y/n): ")
#     if bpmChoice == "n" :
#         bpm = 120
#         return bpm
#     elif bpmChoice == "y" :
#         bpm = int(input("Enter a new BPM: " ))
#         return bpm
#     else :
#         print("Please enter valid input, 'y' or 'n' only")
#         bpmchoice() #als input niet matched dan voer de functie choice opnieuw uit
# bpm = bpmchoice() #bpm is gelijk aan het resultaat van de functie choice

noteDurationsForInstrument = {}
def instrumentname_noteDuratons_choice():
    # aan de hand de gekozen instrumentname en het aantal steps worden er notedurations aan de array toegevoegd

    # multiple choice voor de instrumentname
    instrumentChoiceQuestion = [
        inquirer.List('instrumentname', 
                       message = 'Choose instrument',
                       choices = ['kick', 'snare', 'hihat'],
                       carousel = True)] # zorgt voor infinite scroll
    instrumentChoiceAnswer = inquirer.prompt(instrumentChoiceQuestion)

    # aantal elementen in de noteDuration array
    print("Choose number of steps for " + str(instrumentChoiceAnswer['instrumentname']) + " drumline")
    numberSteps = int(input())

    # een dictionary betsaande uit de instrumentname met de bij behorende noteDurations array
    global noteDurationsForInstrument # maak de dictionary binnen de fuctie beschikbaar buiten de functie
    noteDurationsForInstrument = {
        'instrumentname' : instrumentChoiceAnswer['instrumentname'],
        'noteDurations' : []
    }
    print("Type rythmic patern for " + str(instrumentChoiceAnswer['instrumentname']) + " drumline")
    for i in range(numberSteps):
        noteDurationsForInstrument['noteDurations'].append(float(input()))
        i += 1
instrumentname_noteDuratons_choice()
print(noteDurationsForInstrument['noteDurations'])


def duration_16th_note(_bpm):
    # de lengte van 1 16de noot wordt uitgereknd aan de hadn van het bpm

    return((60 / _bpm) / 4)# hele noot = 60/bpm, 16de = 1/4 van een hele noot
noteDuration16th = duration_16th_note(bpm)

noteDurationArray16th = []
def noteDurations_to_noteDurations16th(_noteDurations):
    # zet voor het aantal elementen in noteDurations elk element om in een 16de
    i = 0
    for i in range(len(noteDurationsForInstrument['noteDurations'])):
        noteDurationArray16th.append(float(_noteDurations[i]) / 0.25)
        i += 1
noteDurations_to_noteDurations16th(noteDurationsForInstrument['noteDurations'])
print(noteDurationArray16th)

timeStamps = []
def noteDurations16th_to_timeStamps(_noteDurationArray16th):
    # zet elke 16de noot duratie om in een tijd in miliseconden daarna tellen deze tijden op
    timeStamps16th = []
    sum = 0
    for i in range(len(noteDurationsForInstrument['noteDurations'])):
        timeStamps16th.append(float(_noteDurationArray16th[i] * noteDuration16th))
        sum = sum + timeStamps16th[i]
        timeStamps.append(sum)
        print(sum)
noteDurations16th_to_timeStamps(noteDurationArray16th)
print(timeStamps)

# def handle_sample_event(event):
#     print(event['instrumentname'])
#     event['filename'].play()
# handle_sample_event(kick_event)
# time.sleep(1)
# handle_sample_event(snare_event)
# time.sleep(1)