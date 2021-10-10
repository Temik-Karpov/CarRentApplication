import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.io.InputStream;
import java.io.DataInputStream;
import java.util.List;

public class main
{
    public static void main(String args[]) throws Exception
    {
        ServerSocket sersock = new ServerSocket(5000);
        DataBase dataBase = new DataBase();
        System.out.println("server is ready");
        Socket sock = sersock.accept();
        ObjectInputStream is = new ObjectInputStream(sock.getInputStream());
        List<String> user = (List)is.readObject();
        String login = user.get(0);
        String password = user.get(1);
        String answer = dataBase.LogIn(login, password);
        switch(answer)
        {
            case "NEW USER":
                ObjectOutputStream os = new ObjectOutputStream(sock.getOutputStream());
                os.writeObject(answer);
                ObjectInputStream is2 = new ObjectInputStream(sock.getInputStream());
                User newUser = (User)is2.readObject();
                break;
            case "OLD USER":
                break;
            case "WRONG":
                ObjectOutputStream os2 = new ObjectOutputStream(sock.getOutputStream());
                os2.writeObject(answer);
                break;
        }
        sock.close();
        sersock.close();
    }
}
