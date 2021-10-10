import java.io.Serializable;
import java.util.Scanner;

public class User implements Serializable
{
    private String login_;
    private String password_;
    private String name_;
    private String secondName_;
    private Date dateOfBirth_;
    private int passport_;
    public enum UserType
    {
        CLIENT,
        EMPLOYEE
    }
    private UserType type_;
    private static int numberOfUsers;

    public User()
    {
        this.login_ = "";
        this.password_ = "";
        this.name_ = "";
        this.secondName_ = "";
        this.passport_ = 0;
    }

    public User(String login, String password, String name, String secondName, Date dateOfBirth, int passport)
    {
        this.login_ = login;
        this.password_ = password;
        this.name_ = name;
        this.secondName_ = secondName;
        this.dateOfBirth_ = dateOfBirth;
        this.passport_ = passport;
    }

    public void setType_(String type_)
    {
        switch(type_)
        {
            case "CLIENT":
                this.type_ = UserType.CLIENT;
                break;
            case "EMPLOYEE":
                this.type_ = UserType.EMPLOYEE;
        }
    }

    public void registration(String login, String password)
    {
        Scanner scanner = new Scanner(System.in);
        System.out.println("\nYou are \n\t1) CLIENT \n\t2) EMPLOYEE\n");
        String type;
        type = scanner.nextLine();
        System.out.println("\nYour name: ");
        String name;
        name = scanner.nextLine();
        this.name_ = name;
        System.out.println("\nYour second name: ");
        String secondName;
        secondName = scanner.nextLine();
        this.secondName_ = secondName;
        int day, month, year;
        System.out.println("\nDay of birth: ");
        day = scanner.nextInt();
        System.out.println("\nMonth of birth: ");
        month = scanner.nextInt();
        System.out.println("\nYear of birth: ");
        year = scanner.nextInt();
        Date dateOfBirth = new Date(day, month, year);
        this.dateOfBirth_ = dateOfBirth;
        int passport;
        System.out.println("\nYour passport: ");
        passport = scanner.nextInt();
        this.passport_ = passport;
        setType_(type);
    }

    public String getLogin_()
    {
        return login_;
    }

    public static void increaseNumberOfUsers()
    {
        numberOfUsers++;
    }

    public static boolean check(User user, final String password)
    {
        return (user.getPassword_().equals(password));
    }

    private String getPassword_()
    {
        return password_;
    }

    static
    {
        numberOfUsers = 0;
    }
}
