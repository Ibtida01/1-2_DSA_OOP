import java.util.Scanner;
import java.util.List;
import java.lang.invoke.StringConcatFactory;
import java.util.ArrayList;

class Restaurant
{
    private int Id;
    private String Name;
    private double Score;
    private String Price;
    private String Zipcode;
    private String[] Catagories=new String[3];
    List<Food> foodListofRes=new ArrayList<Food>();//food list of this restaurant
    public  Restaurant(String Id,String Name,String Score,String Price,String Zipcode,String Catagory1,String Catagory2,String Catagory3)
    {
        this.Id=Integer.parseInt(Id);
        this.Name=Name;
        this.Score=Double.parseDouble(Score);
        this.Price=Price;
        this.Zipcode=Zipcode;
        this.Catagories[0]=Catagory1;
        this.Catagories[1]=Catagory2;
        this.Catagories[2]=Catagory3;
    }
    public int getRestaurantID()
    {
        return Id;
    }
    public void addFood(Food food)
    {
        foodListofRes.add(food);
    }
    public void getRestaurantInfo()
    {
        System.out.println("Restaurant Id: "+Id);
        System.out.println("Catagory : "+Catagories[0]+","+Catagories[1]+","+Catagories[2]);
        System.out.println("Name : "+Name);
        System.out.println("Price : "+Price);
        System.out.println("Zipcode : "+Zipcode);
        System.out.println("Score : "+Score);
    }
    public String getName()
    {
        return Name;
    }
    public double getScore()
    {
        return Score;
    }
    public String getPrice()
    {
        return Price;
    }
    public String getZipcode()
    {
        return Zipcode;
    }
    public String[] getCatagories()
    {
        return Catagories;
    }
    public int getId()
    {
        return Id;
    }
}