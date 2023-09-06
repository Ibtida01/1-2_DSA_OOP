/* This class stores some basic information of a student, namely a student's name and id.  */
public class Student {
    private String name;
    private String id;

    public Student(String name, String id) {
        this.name = name;
        this.id = id;
    }

    // Task: Write getters and setters as required
    public String getName()
    {
        return name;
    }
    public String getID()
    {
        return id;
    }

    public void showDetails() {
        System.out.println("  Name: "+name+", Id: "+id);
    }
}
