import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

/* This is the driver class for this project. You need to run this class with three command line arguments corresponding to the name, starting date and maxinum number of allowed events of a festival. For exmaple run the below command from the termincal:
java FestivalApp "CSE Fest 2023" "2023-07-15" 10*/
public class FestivalApp {

    public static void main(String[] args) {
        
        //Task: The program will be run with three command line arguements related to a festival- (i) the festival's name, (ii) its starting date and (iii) the maximum number of events allowed in the festival. Create a FestivalManager object named 'festivalManager' and initialize it with the values passed from the command line as: FestivalManager festivalManager = new FestivalManager(...); Generate error if the required parameters are not passed from the command line.  
        //Write your code here
        if(args.length<3)
            {
                System.err.println("Very few arguments\n");
                System.exit(1);
            }
        String festivalName = args[0];
        String startingDate = args[1];
        //int maxEvents = Integer.parseInt(args[2]);
        FestivalManager festivalManager=new FestivalManager(festivalName,startingDate,args[2]);
        System.out.println("testing ");
        int choice;
        //Scanner scanner = new Scanner(System.in);
        //declaring a new file
        File file = new File("input.txt");
        try (Scanner scanner = new Scanner(file)){
        do {
            // the following lines of code show a menu to take user's choice
            System.out.println("Menu:");
            System.out.println("1. Add an event");
            System.out.println("2. Register student in an event");
            System.out.println("3. View festival details");
            System.out.println("4. View specific event");
            System.out.println("5. View Event on Date");
            System.out.println("6. View event with maximum participants");
            System.out.println("7. View events for students");
            System.out.println("8. Cancel registration");
            System.out.println("9. Exit");
            System.out.print("Enter option: ");

             choice = Integer.parseInt(scanner.nextLine());
            // scanner.nextLine(); // Consume the newline character

            
            switch (choice) {
                case 1: // Add an event
                    /*
                     * Task: using the scanner object, read the following information for an event:
                     * (i) name as a string, (ii) starting date as a string in 'YYYY-MM-DD' format,
                     * (iii) location as  astring, and (iv) max number of participants allowed in the
                     * event as an integer. Invoke the function 'add event' of 'Festival Manager' to
                     * add the event, i.e., call festivalManager.addEvent(...)
                     */

                    // Write your code here
                    System.out.println("Enter event name: ");
                    String s=scanner.nextLine();
                    // scanner.nextLine();//flushing the buffer
                    System.out.println("Enter event date: ");
                    String date=scanner.nextLine();
                    // scanner.nextLine();//flushing the buffer
                    System.out.println("Enter event location: ");
                    String e=scanner.nextLine();
                    // scanner.nextLine();//flushing the buffer
                    System.out.println("Enter maximum participants: ");
                    int mx=Integer.parseInt(scanner.nextLine()); 
                    scanner.nextLine();//flushing the buffer
                    Event evnt=new Event(s,date,e,mx);
                    festivalManager.addEvent(evnt);
                    break;

                case 2:// Register a student in an event
                    /*
                     * Task: read the name and id of a student and an event name. Then register the
                     * student in the event by calling the function:
                     * festivalManager.registerStudent(...)
                     */

                    // Write your code here
                    System.out.println("Enter student name: ");
                    String name=scanner.nextLine();
                    // scanner.nextLine();//flushing the buffer
                    System.out.println("Enter student ID: ");
                    String id=scanner.nextLine();
                    // scanner.nextLine();//flushing the buffer
                    System.out.println("Enter event name: ");
                    String eventName=scanner.nextLine();
                    // scanner.nextLine();//flushing the buffer
                    Student std=new Student(name,id); 
                    festivalManager.registerStudent(eventName,std);
                    break;

                case 3: // View festival details

                    festivalManager.showDetails();

                    break;

                case 4: // View event details
                    /*
                     * Task: read the name of an event and then show the details for the event by
                     * calling the function: festivalManager.showEvent(...);
                     */

                    // Write your code here
                    System.out.println("Enter event name: ");
                    String s1=scanner.nextLine();
                    // scanner.nextLine();//flushing the buffer
                    festivalManager.showEvent(s1);
                    break;
                case 5:
                    System.out.println("Enter date: ");
                    String date1=scanner.nextLine();
                    // scanner.nextLine();//flushing the buffer
                    festivalManager.showEventOnDate(date1);
                    break;
                case 6: // View event with maximum participants
                    festivalManager.eventWithHighestParticipants();
                    break;

                case 7: // View events for students
                    /*Task: read the id of a student and then show the events the student is participating in by calling the function:  festivalManager.showEventsForStudent(...);*/
                    
                    //Write your code here
                    System.out.println("Enter student id: ");
                    String id1=scanner.nextLine();
                    festivalManager.showEventsForStudent(id1);
                    break;

                case 8: // Cancel registration
                    /* Task: read the id of a student and an event name. Then remove the student from the participant list of the event by calling the function:  festivalManager.cancelRegistration(...); */
                    
                    //Write your code here
                    System.out.println("Enter student id: ");
					String idToRemove=scanner.nextLine();
                    // scanner.nextLine();//flushing the buffer
                    System.out.println("Enter event name:");
                    String fromEvent=scanner.nextLine();
                    // scanner.nextLine();//flushing the buffer
                    festivalManager.cancelRegistration(idToRemove,fromEvent);
                    break;

                case 9:
                    System.out.println("Exiting the program.");
                    break;

                default:
                    System.out.println("Invalid option. Please try again.");
            }
            System.out.println();
        } while (choice != 9 && scanner.hasNextLine());
    } catch (FileNotFoundException e) {
        System.err.println("Error: input.txt file not found.");
    }
        // scanner.close();
    }
}
