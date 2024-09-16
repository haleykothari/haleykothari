'''
Objective:
Create 20 Halloween words that have 5-12 characters
Create different permutations of each word and make them into a list
Allow the user to play and guess the word from the permutation. They get 3 tries per word/round
'''

import random
from itertools import permutations
#tuple of 20 halloween words
halloween_words = (
    'pumpkin', 'witch', 'warlock', 'trick', 'treat', 'hauntedhouse', 'blood', 'goblins', 'ghouls', 'skeletons',
    'vampires', 'werewolves', 'ghosts', 'cauldron', 'graveyard', 'cemetery', 'cauldron', 'darkness', 'hocuspocus', 'goosebumps'
    )
#While playing 
playing = True
#that way the games keeps going until someone whats to stop by typing 'Quit'
while playing:
    #This should pop up after each round is over, so it allows the user to leave when they want to
    quit = input('Click any key to Play or type "Quit" to exit the game: ')
    if quit != 'Quit':
        tries = 3 #Initialize that there is 3 tries after every round, no matter if you lost any from the previous round
        the_word = random.choice(halloween_words) # pick a random word from the tuple Ex. "treat"
        perm = permutations(the_word) #and comes up with all the permutations 
        random_word = (random.choice(list(perm))) #randomly picks one of the permutation 
        print(random_word) #Ex. ('r', 't', 'a', 't', 'e')
        user_input = input("Guess the Word: ")
    # User guesses the word and then there are two senerios
        # 1) The user guesses right and the round ends, going back into the loop
        if user_input == the_word:
            print(f'You are Correct! The word is {the_word}')
            continue
        # 2) The user guesses wrong and then they have two more tries before code will just give the word and end the game
        else:
            # A nested loop that way user gets their tries
            while tries > 1:
                tries-=1
                print(f'Incorrect! You have {tries} tries left')
                #Ensures that the same combination of letter print again for the user to try 
                print(random_word) #Ex : If would was 'treat' and the permutation was ('r', 't', 'a', 't', 'e'), the same thing would show here
                user_input = input("Guess the Word: ") # guesses until they get it right
            # if they get is right on the senod or last try, it will break and go back to the bigger loop to start a new round
                if user_input == the_word:
                    print(f'You are Correct! The word is {the_word}')
                    break
            
            # This is if they user could not get in in 3 tries, the round would be over and a new round would start
            if tries==1:
                print(f'The word was {the_word}')
                continue #goes back in the loop to start a new round if they want
    # This else happen when they want to Quit and hence break and stops the game
    else:
        playing = False
        break