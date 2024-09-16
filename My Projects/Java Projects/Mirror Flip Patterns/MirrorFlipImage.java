public class MirrorFlipImage{
    
    private static void displayImage(char[][] image) {
        for (int i = 0; i < image.length; i++) { //Goes through all the rows 
            System.out.println(image[i]); // and then prints them out
        }
    }
    
    private static char[][] horizontalMirror(char[][] image) {
        char temp;
        int len = image.length;
        for (int i=0; i < len/2; i++) { // i is the rows
            // the /2 is needed because without it, the code flips it twice and goes back to the original array
            for (int j=0; j< image[i].length;j++) {
                temp = image[i][j]; // A temporary place, this will allow me to switch the characters 
                image[i][j] = image[len-1-i][j]; // j is the colunms
                image[len-1-i][j]=temp;
            }
        }
        return image; 
    }
    // this flips the horizontal array vertical
    // therefore all the variable has to be flipped
    private static char[][] verticalMirror(char[][] image) {
        char temp;
        int numRows = image.length; // clearly stating the rows 
        int numCols = image[0].length; // clearly stating the colunms
        for (int i=0; i < numRows; i++) { 
            for (int j=0; j< numCols/2;j++) {
                temp = image[i][j];
                image[i][j] = image[i][numCols-1-j];
                image[i][numCols-1-j]=temp;
            }
        }
        // This will return the array after it has been flipped vertically
        return image;
    }

    public static void main(String[] args) {

        char [][] image = {
            {'#', 'x', '#', '#', '#'},
            {'#', ' ', ' ', ' ', '#'},
            {'#', ' ', 'E', ' ', '#'},
            {'*', ' ', ' ', ' ', '|'},
            {'#', ' ', ' ', ' ', '#'},
            {'#', ' ', ' ', ' ', '#'},
            {'#', '#', '#', 'y', '#'},
        }; // used the one in the brief

        // Prints out the original
        System.out.println("Original Image: ");
        displayImage(image);

        // calls the method in order to flip it horizontally
        System.out.println("Horizontally flipped image: ");
        displayImage(horizontalMirror(image));

        // reverse back to the original
        // that way the vertical flipped method will work and flip the original
        horizontalMirror(image);
         
        // method is called and flips the array
        System.out.println("Vertically flipped image: ");
        displayImage(verticalMirror(image));

        // now you don't need to flip it back to the original again
        // so now you just call the horizontal again and it will flip both ways 
        System.out.println("Horizontally and then Vertically flipped image: ");
        displayImage(horizontalMirror(image));
    }




}