public class Pizza {

    private String m_size;
    private int m_cheese;
    private int m_pepperoni;
    private int m_veggie;

    public Pizza() { // default constructor
        this.m_size = "medium";
        this.m_cheese = 1;
        this.m_pepperoni = 0;
        this.m_veggie = 0;
    }

    public Pizza(String size, int cheese, int pepperoni, int veggie){ // overloading constructor
        // call the variable from the other class and assigns it to the varibale from this class
        // this had to be done since the variables in this class were private
        this.m_size = size;
        this.m_cheese = cheese;
        this.m_pepperoni = pepperoni;
        this.m_veggie = veggie;
    }
// Copy constructor
    public Pizza(Pizza pizza){ // type is Pizza and created to ensure that the variables from this class does not get messed up
        this.m_size = pizza.m_size;
        this.m_cheese = pizza.m_cheese;
        this.m_pepperoni = pizza.m_pepperoni;
        this.m_veggie = pizza.m_veggie;
    }
// acessors and mutator for the size, cheese, pepperoni and veggies
//since the variables are private in this class, this is needed when working with the other class
// Size    
    public String getSize(){
        return this.m_size;
    }
    public void setSize(String size){
        this.m_size = size;
    }
// Cheese
    public int getCheese(){
        return this.m_cheese;
    }
    public void setCheese(int cheese){
        this.m_cheese = cheese;
    }
// Pepperoni
    public int getPepperoni(){
        return this.m_pepperoni;
    }
    public void setPepperoni(int pepperoni){
        this.m_pepperoni = pepperoni;
    }
// Veggies
    public int getVeggie(){
        return this.m_veggie;
    }
    public void setVeggie(int veggie){
        this.m_veggie = veggie;
    }

    // assign the pre-determined costs for the size
    public double calcCost(){
        int cost=0;
        if (this.m_size == "small"){ // checking to see if the size is the right string outputted
            cost = 10;
        }
        else if (this.m_size == "medium") {
            cost = 12;
        }
        else if (this.m_size == "large") {
            cost = 14;
        }
        // multiplying each topping by two and then adding them
        // if there are 0 toppings for a specific order, then this will cancel out that 0
        cost = cost + ((2*this.m_cheese) +(2*this.m_pepperoni) + (2*this.m_veggie)); 
        return cost;
    }
// returning what the print statement is going to look like
    public String toString(){
        return ("Pizza Size: " + m_size + ", Quantity of Cheese: " + m_cheese + ", Quantity of Pepperoni: " + m_pepperoni + ", Quantity of Veggies: " + m_veggie + ", Pizza Cost: " + calcCost());
    }
// This equals methd will take the variable that is called and compare it to another variable 
// will check of it the same
// the method will be called from a different class (PizzaDriver)
    public boolean equals(Pizza pizza) {
        if (pizza == null) {
            return false; // if it is not the same
        }
        else if (pizza.m_size == this.m_size && pizza.m_cheese == this.m_cheese && pizza.m_pepperoni == this.m_pepperoni && pizza.m_veggie == this.m_veggie) {
             return true; // if it is the same
        }
        return false;   // confirming that will output false if it is not true
    }
}

