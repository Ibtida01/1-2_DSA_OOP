import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.net.PortUnreachableException;
import java.nio.channels.InterruptibleChannel;
import java.security.PublicKey;
import java.util.Set;

import javax.swing.event.ListSelectionEvent;

public class RestaurantDBMS
{
    //main DB
    List<Restaurant> restaurants=new ArrayList<>();
    List<Food> foods=new ArrayList<>();
    //main DB finished
    //private List<Restaurant> restaurantList= new ArrayList<>();
    //private List<Food> foodList=new ArrayList<>();
    private List<String> restaurantID_Name=new ArrayList<>();//idx is restaurant ID and value is restaurant name
    private Set<String> CatagoriesList=new HashSet<>();
    private static final String INPUT_FILE_MENU="menu.txt";
    private static final String OUT_FILE_MENU="menu.txt";
    private static final String INPUT_FILE_RESTAURANT="restaurant.txt";
    private static final String OUT_FILE_RESTAURANT="restaurant.txt";
    public String getRestaurantID(String rname)
    {
        for(Restaurant r:restaurants)
        {
            if(r.getName().equalsIgnoreCase(rname))
            {
                return Integer.toString(r.getId());
            }
        }
        //else 
        return null;
    }
    public int addRestaurant(String name,String zipcode,String price,double score,String cat1,String cat2,String cat3)
    {
        boolean eligibleToBeAdded=true;
        for(Restaurant r:restaurants)
        {
            if(r.getName().equalsIgnoreCase(name))
            {
                eligibleToBeAdded=false;
                break;
            }
        }
        if(eligibleToBeAdded==false)
        {
            System.out.println("Restaurant with name "+name+" already exists");
            return 1;
        }
        //else
        int newId=restaurants.size()+1;
        Restaurant r=new Restaurant(Integer.toString(newId),name,Double.toString(score),price,zipcode,cat1,cat2,cat3);
        restaurants.add(r);
        CatagoriesList.add(cat1);
        CatagoriesList.add(cat2);
        CatagoriesList.add(cat3);
        System.out.println("Restaurant with name "+name+" added successfully");
        return 0;
    }
    public void addFoodToMenu(String restaurantName,String foodName,String Catagory,String price)
    {
        boolean eligibleToBeAdded=true;
        int restaurantID=-1;
        Restaurant restaurant=null;
        double prc=Double.parseDouble(price);
        for(Restaurant r:restaurants)
        {
            if(r.getName().equalsIgnoreCase(restaurantName))
            {
                restaurantID=r.getId();
                restaurant=r;
                break;
            }
        }
        if(restaurantID==-1 || restaurant==null)
        {
            System.out.println("No restaurant found with name "+restaurantName);
            return;
        }
        for(Food f:foods)
        {
            if(f.getName().equalsIgnoreCase(foodName) && f.getRestaurantID()==restaurantID && f.getCatagory().equalsIgnoreCase(Catagory) && f.getPrice()==prc)
            {
                eligibleToBeAdded=false;
                break;
            }
        }
        if(eligibleToBeAdded==false)
        {
            System.out.println("Food item with name "+foodName+" already exists in restaurant "+restaurantName);
            return;
        }
        //else
        Food f=new Food(Integer.toString(restaurantID),Catagory,foodName,Double.toString(prc));
        foods.add(f);
        restaurant.addFood(f);
        CatagoriesList.add(Catagory);
        System.out.println("Food item with name "+foodName+" added successfully in restaurant "+restaurantName);
    }
    public void loadFoodItemsToRestaurantMenus()
    {
        for(Food food:foods)
        {
            int restaurantID=food.getRestaurantID();
            restaurants.get(restaurantID-1).addFood(food);
        }
    }
    public  List<Integer> showDetailsbyName(String rname)
    {
        List<Integer> restaurantIDList=new ArrayList<>();
        int len=restaurants.size();
        for(int i=0;i<len;i++)
        {
            if(restaurants.get(i).getName().equalsIgnoreCase(rname))
            {
                restaurantIDList.add(restaurants.get(i).getId());
            }
        }
        if(restaurantIDList.size()==0)
            return null;
        else return restaurantIDList;
    }
    public List<Integer> showDetailsbyScore(double rscore_l,double rscore_r)
    {
        int len=restaurants.size();
        double currentRestaurantScore;
        List<Integer> restaurantIDList=new ArrayList<>();
        for(int i=0;i<len;i++)
        {
            currentRestaurantScore=restaurants.get(i).getScore();
            if(rscore_l<=currentRestaurantScore && currentRestaurantScore<=rscore_r)
            {
               //add the id of that resaturant to the list
                restaurantIDList.add(restaurants.get(i).getId());
            }
        }
        if(restaurantIDList.size()==0)
            return null;
        else return restaurantIDList;
    }
    public List<Integer> showDetailsbyPrice(String rprice)
    {
        List<Integer> restaurantIDList=new ArrayList<>();
        int len=restaurants.size();
        for(int i=0;i<len;i++)
        {
            if(restaurants.get(i).getPrice().equals(rprice))
            {
                restaurantIDList.add(restaurants.get(i).getId());
            }
        }
        if(restaurantIDList.size()==0)
            return null;
        //else
        return restaurantIDList;
    }
    public List<Integer> showDetailsbyZipcode(String rzipcode)
    {
        List<Integer> restaurantIDList=new ArrayList<>();
        int len=restaurants.size();
        for(int i=0;i<len;i++)
        {
            if(restaurants.get(i).getZipcode().equals(rzipcode))
            {
               
                restaurantIDList.add(restaurants.get(i).getId());
            }
        }
        if(restaurantIDList.size()==0)
            return null;
        //else
        return restaurantIDList;
    }
    public List<Integer> showDetailsbyCatagory(String rcatagory)
    {
        List<Integer> restaurantIDList=new ArrayList<>();
        int len=restaurants.size();
        for(int i=0;i<len;i++)
        {
            String[] catagories=restaurants.get(i).getCatagories();
            for(int j=0;j<3;j++)
            {
                if(catagories[j].equalsIgnoreCase(rcatagory))
                {
                    restaurantIDList.add(restaurants.get(i).getId());
                    break;
                }
            }
        }
        if(restaurantIDList.size()==0)
        {
            System.out.println("No restaurant found with catagory "+rcatagory);
            return null;
        }
        //else
       return restaurantIDList;
    }
    // public void showRestaurantByCatagories()
    // {
    //    for(String catagory:CatagoriesList)
    //    {
    //        System.out.println("Catagory : "+catagory);
    //        for(int i=0;i<restaurants.size();i++)
    //        {
    //            String[] catagoryArray=restaurants.get(i).getCatagories();
    //            if(catagoryArray[0].equalsIgnoreCase(catagory) || catagoryArray[1].equalsIgnoreCase(catagory) || catagoryArray[2].equalsIgnoreCase(catagory))
    //            {
    //                restaurants.get(i).getRestaurantInfo();
    //            }
    //        }
    //    }
    // }

    //Start of Food related functions
    public List<Integer> showFoodDetailsbyName(String fname)
    {
        List<Integer> resIDlist=new ArrayList<>();
        for(int i=0;i<foods.size();i++)
        {
            if(foods.get(i).getName().toLowerCase().contains(fname.toLowerCase()))
            {
                resIDlist.add(foods.get(i).getRestaurantID());
            }
        }
        if(resIDlist.size()==0)
        {
            return null;
        }
        //else
        return resIDlist;
    }
    public int showFoodDetailsbyName_and_restaurant(String fname,String rname)
    {
        int targetRestaurantID=-1;
        for(int i=0;i<restaurants.size();i++)
        {
            if(restaurants.get(i).getName().equalsIgnoreCase(rname))
            {
                targetRestaurantID=restaurants.get(i).getId();
                break;
            }
        }
        if(targetRestaurantID==-1)
        {
            return -1;//no such restaurant found
        } //no such restaurants found
        return targetRestaurantID;
    }
    public List<String> searchFoodByCatagory(String catagoryName)
    {
        List<String> foodListOfGivenCatagory=new ArrayList<>();
        for(int i=0;i<foods.size();i++)
        {
            if(foods.get(i).getCatagory().equalsIgnoreCase(catagoryName))
            {
                foodListOfGivenCatagory.add(foods.get(i).getName());
            }
        }
        if(foodListOfGivenCatagory.size()==0)
        {
            return null;
        }
        //else
        return foodListOfGivenCatagory;
    }

    public List<String> showFoodDetailsbyCatagory_and_restaurant(String catagoryNmae,String restaurantName)
    {
        List<String> foodListOfGivenCatagory=new ArrayList<>();
        int targetRestaurantID=-1;
        for(int i=0;i<restaurants.size();i++)
        {
            if(restaurants.get(i).getName().equalsIgnoreCase(restaurantName))
            {
                targetRestaurantID=restaurants.get(i).getId();
                break;
            }
        }
        if(targetRestaurantID==-1)
        {
            return null;//no such restaurant found
        }
        Restaurant targRestaurant=restaurants.get(targetRestaurantID-1);
        for(int i=0;i<targRestaurant.foodListofRes.size();i++)
        {
            if(targRestaurant.foodListofRes.get(i).getCatagory().equalsIgnoreCase(catagoryNmae))
            {
                foodListOfGivenCatagory.add(targRestaurant.foodListofRes.get(i).getName());
            }
        }
        if(foodListOfGivenCatagory.size()==0)
        {
            return null;
        }
        //else
        return foodListOfGivenCatagory;
    }
    public List<Food> searchFoodByPriceRange(double lower_bound,double upper_bound)
    {
        List<Food> foodList=new ArrayList<>();
        for(Food food:foods)
        {
            if(food.getPrice()>=lower_bound && food.getPrice()<=upper_bound)
            {
                foodList.add(food);
            }
        }
        if(foodList.size()==0)
        {
            return null;
        }
        //else
        return foodList;
    }
    public List<Food> searchFoodByPriceRange_and_restaurant(double lower_bound,double upper_bound,String rname)
    {
        List<Food> foodList=new ArrayList<>();
        Restaurant targetRestaurant=restaurants.get(0);
        boolean found=false;
        for(Restaurant r:restaurants)
        {
            if(r.getName().equalsIgnoreCase(rname))
            {
                found=true;
                targetRestaurant=r;
            }
        }
        if(found==false)
        {
            return null;
        }
        //else
        for(Food food:targetRestaurant.foodListofRes)
        {
            if(food.getPrice()>=lower_bound && food.getPrice()<=upper_bound)
            {
               foodList.add(food);
            }
        }
        if(foodList.size()==0)
        {
            return null;
        }
        return foodList;
    }
    public List<Food> showCostliestFoodItems(String restaurantName)
    {
        List<Food> foodList=new ArrayList<>();
        Restaurant targetRestaurant=restaurants.get(0);
        boolean found=false;
        for(Restaurant r:restaurants)
        {
            if(r.getName().equalsIgnoreCase(restaurantName))
            {
                found=true;
                targetRestaurant=r;
            }
        }
        if(found==false)
        {
            return null;
        }
        //else
        double maxPrice=-1.0;
        for(Food food:targetRestaurant.foodListofRes)
        {
            if(food.getPrice()>maxPrice)
            {
                maxPrice=food.getPrice();
            }
        }
        for(Food food:targetRestaurant.foodListofRes)
        {
            if(food.getPrice()==maxPrice)
            {
                foodList.add(food);
            }
        }
        if(foodList.size()==0)
        {
            return null;
        }
        return foodList;
    }
    public HashMap<String,Integer> totalItemsPerRestaurant()
    {
        HashMap<String,Integer> totalNumberOfItemsPerRestaurant=new HashMap<>();
        for(Restaurant r:restaurants)
        {
            totalNumberOfItemsPerRestaurant.put(r.getName(),r.foodListofRes.size());
        }
        return totalNumberOfItemsPerRestaurant;
    }
    //food related functions finished
    public static void showMainMenu()
    {
            System.out.println("Main Menu:");
            System.out.println("1) Search Restaurants");
            System.out.println("2) Search Food Items");
            System.out.println("3) Add Restaurant");
            System.out.println("4) Add Food Item to the Menu");
            System.err.println("5) Exit System");
    }
    public static void showMainMenuOption1()
    {
        System.out.println("1) By Name");
        System.out.println("2) By Score");
        System.err.println("3) By Catagory");
        System.err.println("4) By Price");
        System.err.println("5) By Zip Code");
        System.err.println("6) Different Catagory Wise List of Restaurants");
        System.err.println("7) Back to Main Menu");
    }
    public static void showMainMenuOption2()
    {
        System.out.println("1) By Name");
        System.out.println("2) By Name in a given Restaurant");
        System.out.println("3) By Cataogry");
        System.out.println("4) By Catagory in a given Restaurant");
        System.out.println("5) By Price Range");
        System.out.println("6) By Price Range in a given Restaurant");
        System.out.println("7) Costliest Food Item(s) on the Menu in a Given Restaurant");
        System.out.println("8)  List of Restaurants and Total Food Item on the Menu");
        System.out.println("9) Back to Main Menu");
    }
    public static void main(String[] args) throws Exception {
        RestaurantDBMS rdb=new RestaurantDBMS();
        //load everything 
        String bufferStr=new String();
        List<String[]> restaurantInfo=new ArrayList<>();
        List<String[]> foodInfo=new ArrayList<>();
        // List<Restaurant> restaurants=new ArrayList<>();
        // List<Food> foods=new ArrayList<>();
        //reading restaurant.txt 
        BufferedReader br=new BufferedReader(new FileReader(INPUT_FILE_RESTAURANT));
        while(true)
        {
            bufferStr=br.readLine();
            if(bufferStr==null)
                break;//Reached EOF
            //System.out.println(bufferStr);
            String[] strArray=bufferStr.split(",",-1);
            Restaurant r = new Restaurant(strArray[0], strArray[1], strArray[2], strArray[3], strArray[4], strArray[5],strArray[6],strArray[7]);
            rdb.restaurants.add(r);
            //restaurants.get(restaurants.size()-1).getRestaurantInfo(); for debugging purpose
        }
        //load menu.txt into RAM
        br=new BufferedReader(new FileReader(INPUT_FILE_MENU));
        while(true)
        {
            bufferStr=br.readLine();
            if(bufferStr==null)
                break;//Reached EOF
            //System.out.println(bufferStr);
           String[] strArray=bufferStr.split(",",-1);
           Food f = new Food(strArray[0], strArray[1], strArray[2], strArray[3]);
            rdb.foods.add(f);
        }
        //DB loading done
        //loading the CatagoriesList
        for(int i=0;i<rdb.restaurants.size();i++)
        {
            //INSERT INTO catagoriesList SET
            String[] catagories=rdb.restaurants.get(i).getCatagories();
            for(int j=0;j<3;j++)
            {
                if(catagories[j].equals(""))
                    continue;
                rdb.CatagoriesList.add(catagories[j]);
            }
        }
         rdb.loadFoodItemsToRestaurantMenus();
         //All loading done
         br.close();
        // ...
        /*
        for(int i=0;i<foods.size();i++)
        {
          //print details of food
            foods.get(i).getFoodInfo();
        }
        
        for(int i=0;i<restaurantInfo.size();i++)
        {
            //print details about restaurant
            restaurants.get(i).getRestaurantInfo();
        }
        */
        //showing main menu
        Scanner scn=new Scanner(System.in);
        int choice,subchoice;
        //MAIN MENU STARTED_________________________________________________________________________________________________________________________________
        do
        {
            showMainMenu();
            choice=scn.nextInt();
            scn.nextLine();
            //flushing buffer
            switch(choice)
            {
                case 1:
                    //search restaurants
                    
                    do{
                    showMainMenuOption1();
                    subchoice=scn.nextInt();
                    scn.nextLine();//flushing the buffer
                    //more
                    //subchoice section started
                    switch(subchoice)
                    {
                        case 1://SEARCH BY NAME
                            System.out.println("Enter restaurant name to search: ");
                            String rname;
                            rname=scn.nextLine();
                            System.out.println("Searching for "+rname);
                            List<Integer> restaurantIDList= rdb.showDetailsbyName(rname);
                            if(restaurantIDList==null)
                            {
                                System.out.println("No restaurant found with name "+rname);
                                break;
                            }
                            for(int i=0;i<restaurantIDList.size();i++)
                            {
                                rdb.restaurants.get(restaurantIDList.get(i)-1).getRestaurantInfo();
                            }
                           //did this to maintain OOP style
                            break;
                        case 2://SEARCH BY SCORE
                            double lower_bound,upper_bound;
                            System.out.println("Enter lower bound:");
                            lower_bound=scn.nextDouble();
                            scn.nextLine();//flushing buffer
                            System.out.println("Enter upper bound:");
                            upper_bound=scn.nextDouble();
                            //flushing buffer
                            scn.nextLine();
                            List<Integer> idList=rdb.showDetailsbyScore(lower_bound,upper_bound);
                            if(idList==null)
                            {
                                System.out.println("No restaurant found with score in range "+lower_bound+"-"+upper_bound);
                                break;
                            }
                            //else
                            for(int i=0;i<idList.size();i++)
                            {
                                System.out.println(rdb.restaurants.get(idList.get(i)-1).getName());
                            }
                            break;
                        case 3:
                            //by cataogry
                            System.out.println("Please enter catagory name:");
                            String rcatagory;
                            rcatagory=scn.nextLine();
                            idList=rdb.showDetailsbyCatagory(rcatagory);
                            if(idList==null)
                            {
                                System.out.println("No restaurant found with catagory "+rcatagory);
                                break;
                            }
                            //else
                            for(int i=0;i<idList.size();i++)
                            {
                                System.out.println(rdb.restaurants.get(idList.get(i)-1).getName());
                            }
                            break;
                        case 4:
                            //by price
                            System.out.println("Please enter price:");
                            String prc=scn.nextLine();
                            idList=rdb.showDetailsbyPrice(prc);
                            if(idList==null)
                            {
                                System.out.println("No restaurant found with price "+prc);
                                break;
                            }
                            //else
                            for(int i=0;i<idList.size();i++)
                            {
                                System.out.println(rdb.restaurants.get(idList.get(i)-1).getName());
                            }
                            break;
                        case 5:
                            //by zip code
                            System.out.println("Please enter zip code:");
                            String rzipcode=scn.nextLine();
                            idList=rdb.showDetailsbyZipcode(rzipcode);
                            if(idList==null)
                            {
                                System.out.println("No restaurant found with zip code "+rzipcode);
                                break;
                            }
                            //else
                            for(int i=0;i<idList.size();i++)
                            {
                                System.out.println(rdb.restaurants.get(idList.get(i)-1).getName());
                            }
                            break;
                        case 6:
                            //different catagory wise list of restaurants
                            for(String catagory:rdb.CatagoriesList)
                            {
                                System.out.print(catagory+" : ");
                                for(int i=0;i<rdb.restaurants.size();i++)
                                {
                                    String[] currentCatagories=rdb.restaurants.get(i).getCatagories();
                                    if(catagory.equals(currentCatagories[0]) || catagory.equals(currentCatagories[1]) || catagory.equals(currentCatagories[2]))
                                    //rdb.restaurants.get(i) is the same as rdb.restaurants[i],though the 2nd syntax isn't valid
                                    {
                                        System.err.print(rdb.restaurants.get(i).getName()+" , ");
                                    }
                                }
                                System.out.println();
                            }
                            break;
                        case 7:
                            //back to main menu
                            break;
                        default:
                            System.out.println("Wrong Choice!!");
                    }
                }while(subchoice!=7);
                    //subchoice section finished
                break;
                case 2:
                    //Search Food Items...submenu 2 begins
                   
                    do{
                         showMainMenuOption2();
                        subchoice=scn.nextInt();
                        scn.nextLine();//flushing buffer
                        switch(subchoice)
                        {
                            case 1:
                                //by name
                                System.out.println("Enter food name to search: ");
                                String fname=scn.nextLine();
                                System.out.println("Searching for "+fname);
                                List<Integer> resIdList=new ArrayList<>();
                                resIdList=rdb.showFoodDetailsbyName(fname.toLowerCase());
                                if(resIdList==null)
                                {
                                    System.out.println("No food item found with name "+fname);
                                    break;
                                }
                                for(int i=0;i<resIdList.size();i++)
                                {
                                    int currentRestaurantID=resIdList.get(i);
                                    for(int j=0;j<rdb.restaurants.size();j++)
                                    {
                                        if(rdb.restaurants.get(j).getId()==currentRestaurantID)
                                        {
                                            for(int k=0;k<rdb.restaurants.get(j).foodListofRes.size();k++)
                                            {
                                                String toMatch=rdb.restaurants.get(j).foodListofRes.get(k).getName().toLowerCase();
                                                if(toMatch.contains(fname.toLowerCase()))
                                                {
                                                    rdb.restaurants.get(j).foodListofRes.get(k).getFoodInfo();
                                                }
                                            }
                                            System.out.println("Available in restaurant: "+rdb.restaurants.get(j).getName());
                                        }
                                    }
                                }
                                break;
                            case 2:
                                //search for food items by name in a specific restaurant
                                System.out.println("Enter the food item name: ");
                                fname=scn.nextLine();
                                System.out.println("Enter the restaurant name: ");
                                String rname=scn.nextLine();
                                System.out.println("Searching for "+fname+" in "+rname);
                                int targetRestaurantID=rdb.showFoodDetailsbyName_and_restaurant(fname,rname);
                                if(targetRestaurantID==-1)
                                {
                                    System.out.println("No food item found with name "+fname+" in restaurant "+rname);
                                    break;
                                }
                                //else
                                Restaurant targetRestaurant=rdb.restaurants.get(targetRestaurantID-1);
                                for(int i=0;i<targetRestaurant.foodListofRes.size();i++)
                                {
                                    if(targetRestaurant.foodListofRes.get(i).getName().toLowerCase().contains(fname.toLowerCase()))
                                    {
                                        targetRestaurant.foodListofRes.get(i).getFoodInfo();
                                    }
                                }
                                break;
                            case 3:
                                //search by catagory
                                System.out.println("Enter catagory name: ");
                                String catagory=scn.nextLine();
                                System.out.println("Searching for "+catagory);
                                List<String>  catagoryWiseFoodList=rdb.searchFoodByCatagory(catagory);
                                if(catagoryWiseFoodList==null)
                                {
                                    System.out.println("No food item found with catagory "+catagory);
                                    break;
                                }
                                //else
                                for(int i=0;i<catagoryWiseFoodList.size();i++)
                                {
                                    System.out.println(catagoryWiseFoodList.get(i));
                                }
                                break;
                            case 4:
                                //search by food catagory and restaurant name
                                System.out.println("Enter catagory name: ");
                                catagory=scn.nextLine();
                                System.out.println("Enter restaurant name: ");
                                rname=scn.nextLine();
                                System.out.println("Searching for "+catagory+" in "+rname);
                                List<String> catagory_and_restaurant_wise_foodList=rdb.showFoodDetailsbyCatagory_and_restaurant(catagory,rname);
                                if(catagory_and_restaurant_wise_foodList==null)
                                {
                                    System.out.println("No food item found with catagory "+catagory+" in restaurant "+rname);
                                    break;
                                }
                                //else
                                for(String s:catagory_and_restaurant_wise_foodList)
                                {
                                    System.out.println(s);
                                }
                            case 5:
                            //search by price range
                            System.out.println("Enter lower bound:");
                            double lower_bound=scn.nextDouble();
                            scn.nextLine();//flushing buffer
                            System.out.println("Enter upper bound:");
                            double upper_bound=scn.nextDouble();
                            //flushing buffer
                            scn.nextLine();
                            List<Food> foodList=rdb.searchFoodByPriceRange(lower_bound,upper_bound);
                            if(foodList==null)
                            {
                                System.out.println("No such food item with this price range");
                                break;
                            }
                            //else 
                            for(Food food:foodList)
                            {
                                System.out.println(food.getName());
                            }
                            break;
                            case 6:
                            //search by price and restaurant name
                            System.out.println("Enter lower bound:");
                            lower_bound=scn.nextDouble();
                            scn.nextLine();//flushing buffer
                            System.out.println("Enter upper bound:");
                            upper_bound=scn.nextDouble();
                            //flushing buffer
                            scn.nextLine();
                            System.out.println("Enter restaurant name:");
                            rname=scn.nextLine();
                            //flushing buffer
                            foodList=rdb.searchFoodByPriceRange_and_restaurant(lower_bound,upper_bound,rname);
                            if(foodList==null)
                            {
                                System.out.println("No such food item with this price range in restaurant "+rname);
                                break;
                            }
                            //else
                            for(Food food:foodList)
                            {
                                System.out.println(food.getName());
                            }
                                break;
                            case 7:
                            //show the costliest food items
                            System.out.println("Enter restaurant name:");
                            rname=scn.nextLine();
                            foodList=rdb.showCostliestFoodItems(rname);
                            if(foodList==null)
                            {
                                System.out.println("No such food item with this price range in restaurant "+rname);
                                break;
                            }
                            //else
                            for(Food food:foodList)
                            {
                                System.out.println(food.getName());
                            }
                                break;
                            case 8:
                            //show the list of restaurants and total food items on the menu
                            HashMap<String,Integer> RestaurantWiseitemCount=rdb.totalItemsPerRestaurant();
                            for(String restaurantName:RestaurantWiseitemCount.keySet())
                            {
                                System.out.println(restaurantName+" : "+RestaurantWiseitemCount.get(restaurantName));
                            }
                                break;
                            case 9:
                                break;
                            default:
                                System.out.println("Invalid choice!!Please try again with choices 1-9");
                                break;
                        }
                    }while(subchoice!=9);
                    break;
                case 3:
                    //Add restaurant
                    System.out.println("Enter restaurant name:");
                    String rname=scn.nextLine();
                    System.out.println("Enter restaurant address:");
                    String zipCode=scn.nextLine();
                    System.out.println("Enter restaurant price:");
                    String price=scn.nextLine();
                    System.out.println("Enter restaurant score:");
                    double scr=scn.nextDouble();
                    scn.nextLine();//flushing buffer
                    System.out.println("Enter restaurant catagory 1:");
                    String cat1=scn.nextLine();
                    System.out.println("Enter restaurant catagory 2:");
                    String cat2=scn.nextLine();
                    System.out.println("Enter restaurant catagory 3:");
                    String cat3=scn.nextLine();
                    int flag=rdb.addRestaurant(rname,zipCode,price,scr,cat1,cat2,cat3);
                    //now we need to write this data as a String into restaurant.txt
                    if(flag==1)
                    {
                        System.out.println("Restaurant with name "+rname+" couldn't be added");
                        break;
                    }
                    //else
                    String restaurantID=rdb.getRestaurantID(rname);
                    String toWrite=restaurantID+","+rname+","+scr+","+price+","+zipCode+","+cat1+","+cat2+","+cat3;
                    BufferedWriter bw=new BufferedWriter(new FileWriter(OUT_FILE_RESTAURANT,true));
                    bw.write(System.lineSeparator()); // Write a line separator to start the next write on a new line
                    bw.write(toWrite);
                    bw.write(System.lineSeparator()); // Write a line separator to start the next write on a new line
                    bw.close(); // Close the BufferedWriter to ensure the content is written and release resources
                    break;
                case 4:
                    //Add food item to the menu
                    System.out.println("Enter restaurant name: ");
                    rname=scn.nextLine();
                    System.out.println("Enter food name:");
                    String fname=scn.nextLine();
                    System.out.println("Enter food catagory:");
                    String catagory=scn.nextLine();
                    System.out.println("Enter food price:");
                    String prc=scn.nextLine();
                    rdb.addFoodToMenu(rname,fname,catagory,prc);
                    //now we need to write this data as a String into menu.txt
                    restaurantID=rdb.getRestaurantID(rname);
                    if(rname==null)
                    {
                        System.out.println("No restaurant found with name "+rname);
                        break;
                    }
                    toWrite=restaurantID+","+catagory+","+fname+","+prc; 
                    bw=new BufferedWriter(new FileWriter(OUT_FILE_MENU,true));
                    bw.write(System.lineSeparator());
                    bw.write(toWrite);
                    bw.write(System.lineSeparator()); // Write a line separator to start the next write on a new line
                    bw.close(); // Close the BufferedWriter to ensure the content is written and release resources
                    break;
                case 5:
                    break;
                default:
                    System.out.println("Invalid choice!!Please try again with choices 1-5");
            }
        }while(choice!=5);
        System.out.println("Exiting System...");
        //MAIN MENU FINISHED_________________________________________________________________________________________________________________________________
        //br.close();
        //scn.close();
    }
}