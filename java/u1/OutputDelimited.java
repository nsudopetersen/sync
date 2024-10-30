/* */

public class OutputDelimited {

    private static final int LINE_COUNT = 3;

    public static void main(String[] args) {
        private String separator;
        private Scanner s;
        private String input[];

        separator = args[0];
        s = new Scanner(System.in);

        for(int i = 0; i < LINE_COUNT; i++)
        {
            input[i] = s.nextline().toLowerCase() + separator;
        }
        
        for(int i = 0; i < LINE_COUNT; i++)
        {
            System.out.print(input[i]);
        }
        System.out.println();
    }
}
