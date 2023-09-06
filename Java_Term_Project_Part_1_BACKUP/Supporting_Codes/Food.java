import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

class Food{
    int RestaurantId;
    String Catagory;
    String Name;
    double Price;
    public Food(String RestaurantId,String Catagory,String Name,String Price){
        this.RestaurantId=Integer.parseInt(RestaurantId);
        this.Catagory=Catagory;
        this.Name=Name;
        this.Price=Double.parseDouble(Price);
    }
    public void getFoodInfo()
    {
        System.out.println("Restaurant Id: "+RestaurantId);
        System.out.println("Catagory : "+Catagory);
        System.out.println("Name : "+Name);
        System.out.println("Price : "+Price);
    }
    public int getRestaurantID()
    {
        return RestaurantId;
    }
    public String getName()
    {
        return Name;
    }
    public double getPrice()
    {
        return Price;
    }
    public String getCatagory()
    {
        return Catagory;
    }
}