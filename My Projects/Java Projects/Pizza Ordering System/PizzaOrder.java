public class PizzaOrder {

    private Pizza[] m_order;
    private int m_numPizzas;

    public PizzaOrder() { //default constructor
        m_order = new Pizza[1];
        this.m_order[0] = new Pizza();
        m_numPizzas = 1;
    }

    public PizzaOrder(int size) { // Overloaded constructor 
        // to set the size of the array and initialize the order
        m_order = new Pizza[size];
        m_numPizzas = 0;
    }
    // chat GPT was helpful in this methods
    public int addPizza(Pizza pizza) {
        if (m_numPizzas < m_order.length) {
            m_order[m_numPizzas] = new Pizza(pizza);
            m_numPizzas++;
            return 1;
        }
        else {
            return -1;
        }
    }
// End of chatGPT

//This will keep looping until i becomes the smae number as m_numPizzas 
    public double calcTotal() {
        double totalCost = 0.0;
        for (int i = 0; i < m_numPizzas; i++) {
            totalCost += m_order[i].calcCost(); // stays in the array and then calculates the total cost
        }
        return totalCost; // return the double of totalCost, since the method is typed as a double
    }

    // I did search up the StringBuilder concept through stack overflow    
    public String toString() {
        StringBuilder orderStr = new StringBuilder("Order:\n");
        for (int i = 0; i < m_numPizzas; i++) { // loop until the equal to m_numPizzas
            orderStr.append(m_order[i].toString()).append("\n"); // goes back to the toString from the Pizza class and uses what was in that method
        }
        // Then it will add the numbers from the order and calculate a total cost
        orderStr.append("Total cost: $").append(calcTotal());
        return orderStr.toString();
    }
    }