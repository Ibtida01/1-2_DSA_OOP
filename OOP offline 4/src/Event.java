/* This class stores the following information about an event: name, starting date, location and list of students registered for the event. */
public class Event {
    private String eventName;
    private String eventDate; // store in the format YYYY-MM-DD
    private String eventLocation;
    private Student[] registeredStudents;
    int participantsAdded = 0; //variable to keep track of number of participants so far added

    //Task: Write code for the constructor below to initialize the member variables properly
    public Event(String eventName, String eventDate, String eventLocation, int maximumParticipants) {
        //write your code here
        this.eventName=eventName;
        this.eventDate=eventDate;
        this.eventLocation=eventLocation;
        //System.out.println("event name : "+eventName+" event date : "+eventDate+" event location : "+eventLocation+" maximum participants : "+maximumParticipants+"");
        registeredStudents=new Student[maximumParticipants];
    }

    // Task: Write getters and setters for Event attributes as required
    public void setEventName(String s)
    {
        eventName=new String(s);
    }
    public String getEventName()
    {
        return eventName;
    }
    public void setEventDate(String s)
    {
        eventDate=new String(s);
    }
    
    public String getEventDate()
    {
        return eventDate;
    }
    public int getParticipantCount()
    {
        return participantsAdded;
    }
    public String getEventLocation()
    {
        return eventLocation;
    }
    public int getParticipantCapacity()
    {
        return registeredStudents.length;
    }
    // Task: Write your code for the function below. This functions adds a participant to this event. Check for the following cases: (i) total participant count does not exceed the maximum participant count, (ii) the studentId is not already added.
    public void addParticipant(Student student)
    {
        //CHANGE
        // write your code here 
        if(participantsAdded+1 > registeredStudents.length)
        {
            System.out.println("Participants exceeded");
            return;
        }
        registeredStudents[++participantsAdded-1]=new Student(student.getName(),student.getID());
    }

    
    //Task: Write code for the function below. This function shows the details of an event. Make sure your output matches with the supplied sample output.
    public void showDetails() {
        //Write your code here
        System.out.println("Name : "+eventName);
        System.out.println("Date : "+eventDate);
        System.out.println("Location : "+eventLocation);
        System.out.println("Registered participants : ");
        for(int i=0;i<participantsAdded;i++)
        {
            registeredStudents[i].showDetails();
        }
    }

    //Task: Write code for the function below. This function check whether the studentId in the argument has registered for this event or not. Return true if registered, otherwise return false.
    public boolean isRegistered(String studentId) {
        //Write your code here
        boolean flag=false;
        String id;
        for(int i=0;i<participantsAdded;i++)
        {
            id=registeredStudents[i].getID();
            if(id.equals(studentId))
            {
                flag=true;
                break;
            }
        }
        return flag;
    }

    // Task: Write code for the function below. This function removes a participant from this event. Check for the following cases: (i) the student Id is not regiseterd. 
    public void removeParticipant(String studentId) {
        //Write your code here
        if(isRegistered(studentId)==false)
        {
            System.out.println("Student not registered");
            return;
        }
        for(int i=0;i<participantsAdded;i++)
        {
           if(registeredStudents[i].getID()==studentId){
            //found
            for(int j=i+1;j<participantsAdded;j++)
            {
                registeredStudents[j-1]=registeredStudents[j];
            }
           }
        }
        --participantsAdded;
    }

}