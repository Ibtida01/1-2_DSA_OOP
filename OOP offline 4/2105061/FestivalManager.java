/* This class stores information of a festival which are name, starting date and list of events that will take place during the festival. */



public class FestivalManager {
    private String name;
    private String startDate;
    private Event[] events;
    int eventsAdded = 0;

    //Task: Write code for the constructor below to initialize the member variables properly
    public FestivalManager(String name, String startDate, String maxEventCount) {
        // write your code here
        this.name=name;
        this.startDate=startDate;
        int mxEvntCount=Integer.parseInt(maxEventCount);
        events=new Event[mxEvntCount];
    }

    //Task: Write code for the function below. This function adds an event to this festival. Check for the following case: (i) total event count does not exceed the maximum number of events allowed for this festival
    public void addEvent(Event e) {
        // write your code here
        if(eventsAdded>=events.length)
        {
            System.out.println("Events exceeded");
            return;
        }
        events[eventsAdded++]=new Event(e.getEventName(),e.getEventDate(),e.getEventLocation(),e.getParticipantCapacity());
        //System.out.println("event name : "+events[eventsAdded-1].getEventName()+" event date : "+events[eventsAdded-1].getEventDate()+" event location : "+events[eventsAdded-1].getEventLocation()+" maximum participants : "+events[eventsAdded-1].getParticipantCount()+"");
    }

    //Task: Write code for the function below. This function registers a student for an event in this festival. Check for the following case: (i) event does not exist
    public void registerStudent(String eventName, Student s) {
        //Write your code here
        for(int i=0;i<eventsAdded;i++)
        {
            if(events[i].getEventName().equals(eventName))
            {
                //found
                events[i].addParticipant(s);
                return;
            }
           
        }
         //else,that is event not found,the ctrl flow will reach here
        System.out.println("Event not found");
    }

    // Task: Write code for the function below. The function shows the details of this festival. Make sure the output matches with the supplied sample output.
    public void showDetails() {
        //Write your code here
        System.out.println("Festival Name: "+name);
        System.out.println("Festival Start Date: "+startDate);
        System.out.println("Festival Events: ");
        for(int i=0;i<eventsAdded;i++)
        {

            events[i].showDetails();
        }
    }

    // Task: Write code for the function below. This function shows details of the event in the argument. Check for the following case: (i) event does not exist
    public void showEvent(String eventName){
        //Write your code here
        for(int i=0;i<eventsAdded;i++)
        {
            if(events[i].getEventName().equals(eventName))
            {
                //found
                events[i].showDetails();
                return;
            }
        }
        System.out.println("Event not found");
    }

    // Task: Write code for the function below. This function shows details of the events that will start on the date passed as its argument. Check for the following case: (i) event does not exist
    public void showEventsOnDate(String eventDate) {
        //Write your code here
        System.out.println("Events on "+eventDate+" are:");
        String s;
        int ct=0;
        for(int i=0;i<eventsAdded;i++)
        {
            if(events[i].getEventDate().equals(eventDate))
            {
                //found
                s=events[i].getEventName();
                System.out.println(s);
                ++ct;
            }
        }
        if(ct==0)
        {
            System.out.println("No events on "+eventDate);
        }
    }

    //Task: Write code for the function below. This function shows the details of the events with maximum number of participants. If there are multiple events, show all.
    public void eventWithHighestParticipants() {
        //Write your code here
        System.out.println("Events with highest participants:");
        int mx=events[0].getParticipantCount();
        for(int i=1;i<eventsAdded;i++)
        {
            if(events[i].getParticipantCount()>mx)
            {
                mx=events[i].getParticipantCount();
            }
        }
        for(int i=0;i<eventsAdded;i++)
        {
            if(events[i].getParticipantCount()==mx)
            {
                events[i].showDetails();
            }
        }
    }

    //Task: Write code for the function below. This function takes a student Id as input and then lists all the events this particular student has registered for. Make sure your output matches the supplied sample output.
    public void showEventsForStudent(String studentId) {
        //Write your code here
        String eveName;
        System.out.println("Student "+studentId+" is registered in :");
        for(int i=0;i<eventsAdded;i++)
        {
           if(events[i].isRegistered(studentId)==true)
           {
               eveName=events[i].getEventName();
               System.out.println(eveName);
           }
        }
       
    }

    //Task: Write code for the function below. This functions takes an event's name and a student's ID as arguments and then removes the student from the registered student list of the event. Check for the following cases: (i) event does not exist, (ii) student is not registered for the event
    public void cancelRegistration(String eventName, String studentId) {
        //Write your code here
        for(int i=0;i<eventsAdded;i++)
        {
           if(events[i].getEventName().equals(eventName))
           {
            //found
                if(events[i].isRegistered(studentId)==true)
                {
                    events[i].removeParticipant(studentId);
                     System.out.println("Successfully removed id "+studentId+" from event "+eventName);
                    return;   
                }
                else
                {
                    System.out.println("Student not registered");
                    return;
                }
           }
        }
        System.out.println("Event not found");
    }
    public void showEventOnDate(String eveDate)
    {
        String eveName;
        for(int i=0;i<eventsAdded;i++)
        {
            if(events[i].getEventDate().equals(eveDate))
            {
                eveName=events[i].getEventName();
                System.out.println(eveName);
            }
        }
    }
}
