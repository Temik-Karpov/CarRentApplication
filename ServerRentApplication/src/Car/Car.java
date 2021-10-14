package Car;

import java.util.ArrayList;
import java.util.stream.IntStream;

public class Car
{
    private String name_;
    private CarType type_;
    private double maxSpeed_;
    private double fuelCapacity_;
    private double price_;
    private ArrayList<Integer>  marks_;
    public Car()
    {
        this.name_ = "";
        this.type_ = null;
        this.maxSpeed_ = 0;
        this.fuelCapacity_ = 0;
        this.price_ = 0;
        this.marks_ = new ArrayList<>();
    }

    public Car(String name, CarType type, double speed, double fuel, double price)
    {
        this.name_ = name;
        this.type_ = type;
        this.maxSpeed_ = speed;
        this.fuelCapacity_ = fuel;
        this.price_ = price;
    }

    public void showInfo()
    {
        System.out.println("\nName: " + this.name_);
        System.out.println("\n\tType: " + this.type_);
        System.out.println("\n\tMax speed: " + this.maxSpeed_);
        System.out.println("\n\tFuel capacity: " + this.fuelCapacity_);
    }

    public void addMark(int newMark)
    {
        this.marks_.add(newMark);
    }

    public int getRating()
    {
        int sum = 0;
        for(Integer mark:marks_)
        {
            sum += mark;
        }
        return sum/marks_.size();
    }
}
