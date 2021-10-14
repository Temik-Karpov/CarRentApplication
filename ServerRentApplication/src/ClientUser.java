import Car.Car;

public class ClientUser extends User
{
    private static int numberOfUsers;
    private Car currentCar_;
    private double counter_;
    private Date rentBegin_;
    private Date rentEnd_;

    public ClientUser()
    {
        this.currentCar_ = null;
        this.counter_ = 0;
        this.rentBegin_ = null;
        this.rentEnd_ = null;
    }

    public void calculateCounter()
    {

    }

    public static void increaseNumberOfUsers()
    {
        numberOfUsers++;
    }
    static
    {
        numberOfUsers = 0;
    }
}
