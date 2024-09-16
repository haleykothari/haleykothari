

# define you generate_recipe_function
def generate_recipe(flour, water, salt, yeast, name_of_dough):
    flour = int(flour)
    water = int(water)
    salt = int(salt)
    yeast= int(yeast)

    return f"""
    Your {name_of_dough} Recipe
    ------------------------
    Flour         {flour}g
    Water         {water}g
    Salt          {salt}g
    Yeast         {yeast}g
"""

def bake(selection, flour):
    '''name_of_dough = ""
    water=0.0
    salt=0.0
    yeast=0.0'''
    if selection == 1: #"Pizza Dough":
        name_of_dough = "Pizza Dough"
        water = float((65/100) * flour)
        salt = float((2/100) * flour)
        yeast = float((1/100)* flour)
    elif selection == 2: #"White Bread":
        name_of_dough = "White Bread"
        water = float((66/100) * flour)
        salt = float((2/100)* flour)
        yeast = float((1.2/100) * flour)
    elif selection == 3: #"Artisan Loaf":
        name_of_dough = "Artisan Loaf"
        water = float(flour)
        salt = float((3/100) * flour)
        yeast = float((10/100) * flour)
    else:
        return -1

    return (name_of_dough, water, salt, yeast) #"Name of Dough:"
'''
Params: are flour, water, yeast: floats (could be ints)
dough_name: str
Returns: 
-string: the formatted recipe with values as ints
'''


#TODO: make this string formatted lied the brief
# define yur bake function


# getting parameters from bake from the user
# sending it into bake



if __name__ == "__main__":
    print(""" Types of Recipes
    1. Pizza Dough
    2. White Bread
    3. Artisan Bread""")
    
    number = int(input("Which Dough Recipe (1, 2 or 3): "))
    
    flour = int(input("Grams of Flour: "))


    # TODO: write the main program where you get user input
    # Want to keep trying for dummy numbers
    #if(bake(number, flour) != -1):
    (name_of_dough, water, salt, yeast) = bake(number, flour)
    print(generate_recipe(flour, water, salt, yeast, name_of_dough))
        

#TODO: test the bake function with different dummy values
#TODO: get user input, and send that input into you function

#print(bake(selection, flour))
#name, water, salt, yeast = bake(1,100)
