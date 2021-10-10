import java.io.*;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Client
{

    public static void main(String args[]) throws Exception
    {
        Socket sock = new Socket("127.0.0.1", 5000);
        System.out.println("Welcome!\n");
        System.out.println("Login: ");
        String login, password;
        Scanner scanner = new Scanner(System.in);
        login = scanner.nextLine();
        System.out.println("\nPassword: ");
        password = scanner.nextLine();
        List<String> user = new ArrayList<>();
        user.add(login);
        user.add(password);
        ObjectOutputStream os = new ObjectOutputStream(sock.getOutputStream());
        os.writeObject(user);
        ObjectInputStream is2 = new ObjectInputStream(sock.getInputStream());
        String answer = (String)is2.readObject();
        switch(answer)
        {
            case "NEW USER":
                    User newUser = new User();
                    newUser.registration(login, password);
                    ObjectOutputStream os2 = new ObjectOutputStream(sock.getOutputStream());
                    os2.writeObject(newUser);
                    break;
            case "OLD USER":
                break;
            case "WRONG":
                System.out.println("\nREPEAT PLEASE");
                break;
        }
        os.close();
        sock.close();
    }
}
