public class PizzaDriver {
// So this is the main, where everything gets printed
    public static void main(String[] args) {
    Pizza pizza1 = new Pizza("small", 1, 0, 1);// small pizza, 1 cheese, 1 veggie
    Pizza pizza2 = new Pizza("large", 2, 2, 0);// large pizza, 2 cheese, 2 pepperoni 
    Pizza pizza3 = new Pizza(pizza2);// Same as pizza 2, use copy constructor
    Pizza pizza4 = new Pizza(pizza1);// Same as pizza 1, use copy constructor


    // create an order of THREE pizzas
    PizzaOrder order = new PizzaOrder(3);    
     
        

    // add pizza1 to the order 
    System.out.println(order.addPizza(pizza1)); 
    // add pizza2 to the order
    System.out.println(order.addPizza(pizza2)); 
    // add pizza3 to the order  
    System.out.println(order.addPizza(pizza3));
    // add pizza4 to the order – what happens here?
    System.out.println(order.addPizza(pizza4)); 

    // are pizza1 and pizza 2 the same?
    System.out.println(pizza1.equals(pizza3));

    // Should call order’s toString method
    System.out.println(order.toString());

 
    }
}