package Car;

import java.util.ArrayList;

public class CarCatalog
{
    private ArrayList<Car> data_;

    public CarCatalog()
    {
        this.data_ = new ArrayList<>();
    }

    public void addCar(Car newCar)
    {
        this.data_.add(newCar);
    }

    public void showCatalog()
    {
        for(Car car : data_)
        {
            car.showInfo();
        }
    }

    public void deleteCar(Car car)
    {
        this.data_.remove(car);
    }

    public void showCar(Car car)
    {
        car.showInfo();
    }
}
