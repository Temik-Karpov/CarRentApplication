import java.util.ArrayList;
import java.util.Scanner;

public class DataBase
{
    private ArrayList<User> data_;

    public DataBase()
    {
        data_ = new ArrayList<User>();
    }

    public String LogIn(final String login, final String password)
    {
        if (!search(login))
        {
            return("NEW USER");
        }
        else
        {
            if (User.check(find(login), password))
            {
                return("OLD!!\n\n");
            }
            else
            {
                return("WRONG!!\n\n");
            }
        }
    }

    public void registration(User newUser)
    {
        data_.add(newUser);
        User.increaseNumberOfUsers();
    }

    private boolean search(final String login)
    {
        if(!data_.isEmpty()) {
            for (User element : data_) {
                if (element.getLogin_().equals(login)) {
                    return true;
                }
            }
        }
        return false;
    }

    private User find(final String login)
    {
        for(User element : data_)
        {
            if(element.getLogin_().equals(login))
            {
                return element;
            }
        }
        throw new ArithmeticException("Database error\n");
    }
}
