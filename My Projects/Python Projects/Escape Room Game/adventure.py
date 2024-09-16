# create a game with 6 rooms 


import random



# First Task was to make the random death function
def is_dead(odds_of_death):
    result = random.randint(0,100)
    if result>odds_of_death:
        return False #Output would be False if the random number is greater than the odds of death
    else:
        return True #otherwise it is True
       

# Second Task was to make the roll_dice function                  
def roll_dice(number_of_dice=1):
    counter=1
    sum=0
    while (counter <= number_of_dice):
        num = random.randint(1,6)
        sum = sum+num
        counter+=1
    return sum
    
    #print(dice)

def enter_room(room_num):
    # /* https://www.w3schools.com/python/python_variables_global.asp */
    #... global ...
    # /* https://www.w3schools.com/python/python_variables_global.asp */
    global special_item
    global completed_rooms
    if room_num == 1: #This is to add the storyline to each specific room 
        print("Thee hast entered the Room 1: The Armory Room where lies the weapons the knights of Camelot used to train with. The special item is Sir Elyan's crossbow.")
    elif room_num == 2:
        print("Thee hast entered Room 2: The Great Hall where Sir Leon carried out the king's orders. The special item is Sir Leon's royal red cape.")
    elif room_num == 3:
        print("Thee hast entered Room 3: The Rising Sun, the best and only tavern in all of Camelot; a place where Sir Gwaine often frequented. The special item is his lucky parchment of drink orders.")
    elif room_num == 4:
        print("Thee hast entered Room 4: The Kitchen, where Sir Percival tried to steal food in between training. The special item is the kitchen's most famous pie.")
    elif room_num == 5:
        print("Thee hast entered Room 5: Guineviere's Living Quarters. The special item is a necklace Sir Lancelot had given her.")
    elif room_num == 6:
        print("Thee hast entered Room 6: Merlin and Gaius' living quarters, where Merlin would hide the magic potions and book from Arthur. The special item is Merlin's book of Magic.")
    elif room_num == 7: # stop the user from playing this room untill the other 6 has been completed 
        if special_item != 6:
            print("Sorry thee can not access King Arthur's Chambers without collecting 6 out of 7 special items.")
            return(True) #The return will go back to the main and do that loop again
        else:
            print("Congratulations! Thee hast received 6 out of 7 special items and now hast the power to access King Arthur's Chambers. ")
            print("Thee hast entered Room 7: King Arthur's Chambers. The special item is his most prized possession, King Arthur's sword, Excalibur.")
   # Below is what I want each room to do. Kept it together to keep it organized. Didn't need to write it multiple times
    user_choice = 0
    # This loop is to make sure that the user only picks a number between 1 and 4. 
    # Otherwise pick a valid number
    while user_choice<1 or user_choice>4: 
        user_choice = int(input("How many dices would thee like to play with this round?(1-4): "))
        if user_choice<1 or user_choice>4:
            print("Thee must pick a valid number")
    # Using the roll_dice function, it enters the number of dices and spits out the sum
    # Then I wanted to print out the situation that way they know why they did or did not receive the special item. 
    sum = roll_dice(user_choice)
    print(f'You must roll a total of 15 in order to collect the special item.')
    print(f'You have rolled a total of {sum} from the number of dices you picked.')

    if is_dead(sum) == True:
        print("The dragon has caught up to thee as you were running through Camelot and hast killed thee!")
        return(False)
    #The append allows me to collect and list how many rooms have a special item
    #This is to make sure the user can not access the room a again once completed
    if sum>=15:
        special_item += 1
        completed_rooms.append(room_num)
        # /* https://www.w3schools.com/python/python_arrays.asp#gsc.tab=0 */
        #... .append ...
        # /* https://www.w3schools.com/python/python_arrays.asp#gsc.tab=0 */ 
       
        # The the sum would determine if they received the special item
        print(f'Thee hast found the special item from Room {rselection}! thee can move forward')
        print(f'You have collected {special_item} special items!')
    else:
        print("Thee did not receive the special item and hence did not pass this room.")
        print(f'You have collected {special_item} special items!') 
    # Making this function return back to the nested while loop in the main program
    return(True)

    

if __name__== "__main__":
    
    special_item = 0
    completed_rooms = [""]
    
    #Wanted to add a background story to the game  
    print("""70 years ago, Camelot was attacked by a menacing dragon plunging the kingdom into darkness.
    The ancient sorcerer, Merlin, prophesized that a destined warrior will emerge to collect the 7 items necessary to awaken the spirits of the knights of King Arthur's Round Table.
    Collect each item that corresponds to each knight to allow the spirits to vanquish the dragon.
    You must enter the 7 rooms and throw the correct dice sequence to collect these special items.""")
    
    playing = True #Inspo from the wolves game to start this game, hence makng playing as a variable
    while playing: #This will keep the game going until user wins or dies
        selection=int(input("""Would you like to...
                        1. Enter a Room?
                        2. Quit the Game? """))
        #Above gives the option to the user on whether they would like to start the game or quit it at first
        if selection == 2:
            break
        # Below is the main while loop that calls the function with all the rooms
        while special_item<7:
            rselection= int((input("Choose which room to enter (1-7) OR to quit the game enter 100 ")))
            # I wanted to give the user the option to quit the game when ever they want
            # Soo if they type 100, then the game will quit
            if rselection == 100:
                playing = False
                break
            elif rselection <1 or rselection>7:
                # This elif statement makes sure that the user is inputting a valid Room number 
                print("Put a Valid Room Number")
            elif rselection in completed_rooms:
                # This elif is making sure that the user can not acces the same room once completed
                print("You already received a special item from this room. Pick another room.")
            else:
                playing=enter_room(rselection)
                if playing == False:
                    break
        
        if special_item==7:
            print("Congratulations! You reunited the spirits and saved Camelot from the dangerous Dragon!")
        else:
            print("Game Over")