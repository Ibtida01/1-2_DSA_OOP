import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class FileOperations {

    private static final String INPUT_FILE_NAME = "restaurant.txt"; // Input file name
    private static final String OUTPUT_FILE_NAME = "out.txt"; // Output file name

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader(INPUT_FILE_NAME)); // Create a BufferedReader to read from the input file
        while (true) {
            String line = br.readLine(); // Read a line from the input file
            if (line == null) break; // Exit the loop if there are no more lines to read
            System.out.println(line); // Print the current line to the console
            String[] array = line.split(",", -1); // Split the line by commas into an array
            for (int i = 0; i < array.length; i++) {
                System.out.println(array[i]); // Print each value separated by commas
            }
        }
        br.close(); // Close the BufferedReader to free up resources

        String text = "Hello World";
        BufferedWriter bw = new BufferedWriter(new FileWriter(OUTPUT_FILE_NAME)); // Create a BufferedWriter to write to the output file
        bw.write(text); // Write "Hello World" to the output file
        bw.write(System.lineSeparator()); // Write a line separator to start the next write on a new line
        bw.close(); // Close the BufferedWriter to ensure the content is written and release resources
        // System.out.println("\u2122");
    }
}
