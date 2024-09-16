# Assingment: Password Manager

# using this function to be able to do that flip-flop action
# should go back and forth with encrypting and decrypting
def swap_dict(encrypt_dict):
    decryption_dict = {}
    for key, value in encrypt_dict.items():
        decryption_dict[value] = key
    return decryption_dict

# the below function is looping through every letter to encrypt it
# ex. password was "dog"
# it will go through the ['d', 'o', 'g'] encrypt the first letter so d = w
# then put it at the back making it ['o', 'g', 'f'] and it will keep going until the password is completed
def encrypt(input_string, mapping_dict):
    # Wanted to split the word into different letters, that way each letter can be encrypted
    letters = list(input_string) # make this in a list or something
    #print(letters) # a tester to see where I was at
    new = letters.copy() # this will make another version of the list to its entiretly
    for letter in letters:
        new.remove(letter)
        letter = mapping_dict[letter]
        #print(letter) # another tester to see where I was at
        #input_string = ",".join(letter)
        new.append(letter) # after appending everything, it will...
    return "".join(new) # join and make the encrypted password

# this function goes through the dictionary in a line
def add_record(service, username, password, password_dict, encrypt_dict):
    password = encrypt(password, encrypt_dict) # first it will encrypt the code
    password_dict[service] = {
        "username" : username,
        "password" : password
    } # Then it will go through the dictionary like this 
    
# To view the password whenever the user wants to 
def view_password(service, username, password_dict, decryption_dict):
    #print(password_dict) # another tester to see where I was 
    if service in password_dict: # Will look for the right username to show the password in
        password = password_dict[service]["password"] # This will create the variable password be "password"
        solve_password = encrypt(password, decryption_dict) # this will decrypt the password 
        return solve_password # and will return that password
    else:
        print("No record found")
        return ""
# If user wanted to change the password for a specific service
def update_password(service, new_password, password_dict, encrypt_dict):
    new_password = encrypt(new_password, encrypt_dict) # This will encrypt the new password
    password_dict[service]["password"] = new_password

  
if __name__ == "__main__":
    password_dict = {} # left as an empty dictionary, until user adds an entry
    # below are the encryptions
    encrypt_dict = {
        "A" : "Z",
        "B" : "Y",
        "C" : "X",
        "D" : "W",
        "E" : "V",
        "F" : "U", 
        "G" : "T", 
        "H" : "S", 
        "I" : "R",
        "J" : "Q",
        "K" : "P",
        "L" : "O",
        "M" : "N",
        "N" : "M",
        "O" : "L",
        "P" : "K",
        "Q" : "J",
        "R" : "I",
        "S" : "H",
        "T" : "G",
        "U" : "F",
        "V" : "E",
        "W" : "D",
        "X" : "C",
        "Y" : "B",
        "Z" : "A",
        "a" : "z",
        "b" : "y",
        "c" : "x",
        "d" : "w",
        "e" : "v",
        "f" : "u",
        "g" : "t",
        "h" : "s",
        "i" : "r",
        "j" : "q",
        "k" : "p",
        "l" : "o",
        "m" : "n",
        "n" : "m",
        "o" : "l",
        "p" : "k",
        "q" : "j", 
        "r" : "i",
        "s" : "h",
        "t" : "g",
        "u" : "f",
        "v" : "e", 
        "w" : "d",
        "x" : "c",
        "y" : "b",
        "z" : "a"
        }
# This commented out stuff underneath were test points to see what was going on with the functions
    # print(encrypt("wlt", decryption_dict)) #wlt
    # print(swap_dict(encrypt_dict))
    # print(add_record("mobile", "hkothari", "dog", password_dict, encrypt_dict))
    
    # print(password_dict)
    # print(update_password("mobile", "cat", password_dict, encrypt_dict))
    # print(password_dict)

    user_start = input ("Enter 100 to start or (quit) to quit: ")
    # once the user types 'quit', the program will end. 
    while user_start != 'quit': # This will allow the user to keep going until they don't want to
        decryption_dict = swap_dict(encrypt_dict) # This calls the first function and works with the whole flipflop thing
        user_choice = input("""
        Press 1 to add an entry, 
        Press 2 to view a password, 
        Press 3 to update the password of an existing entry: 
         """)
        # This first one is adding, if the user wants to
        if user_choice == "1":
            user_service = input("Enter the service: ") # Gaining user input 
            user_username = input("Enter the username: ") # These inputs will be save into the password_dict
            user_password = input("Enter our password: ") # The user will put the real password in there
        # calling function to add into password_dict
            add_record(user_service, user_username, user_password, password_dict, encrypt_dict)
            print("Entry has been added to dictionary")
            # wanted to show the user what they added
            # and what the encrypted password looks like
            print(password_dict)
            user_start = input ("Enter anything to start or ('quit') to quit: ")
            # allows the user to look at the password they ask for
            # This will work it the services are different, because you can not have the same key
        elif user_choice == "2":
             user_service = input("Enter the service: ") # gaining inputs
             user_username = input("Enter the username: ") # input to look for the username in that service
             # solved_pass bring a variable from what is return which is (solve_password) 
             solved_pass = view_password(user_service, user_username, password_dict, decryption_dict)
             print(solved_pass)
             user_start = input ("Enter anything to start or ('quit') to quit: ")
             # this allows the user to update the password
        elif user_choice == "3":
            user_service = input("Choose the service you want to update to password for: ") #gaining inputs
            user_new_password = input("Enter a new password: ") # The user will enter the real password
            # this function will be called and it will encrypt the new password once updated
            update_password(user_service, user_new_password, password_dict, encrypt_dict)
            # also wanted to show what the new password_dict would look like and the new encryption for it
            print(password_dict)
            user_start = input ("Enter anything to start or ('quit') to quit: ")
        else:
            # This is only an odd case that they accidently put any other number than 1, 2, 3
            print("Enter a valid number")
            user_start = input ("Enter 100 to start or ('quit') to quit: ")
