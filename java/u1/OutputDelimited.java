/* */

import java.util.Scanner; 

public class OutputDelimited {

    private static final int LINE_COUNT = 3;

    public static void main(String[] args) {
        String separator;
        Scanner s;
        String input[];
        int i = 0;

        separator = args[0];
        s = new Scanner(System.in);

        for(; i < OutputDelimited.LINE_COUNT; i++)
        {
            input[i] = s.nextLine().toLowerCase() + separator;
        }
        
        for(i = 0; i < OutputDelimited.LINE_COUNT; i++)
        {
            System.out.print(input[i]);
        }
        System.out.println("");
    }
}
