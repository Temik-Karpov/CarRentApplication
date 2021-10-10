import java.io.Serializable;

public class Date implements Serializable
{
    private int day_;
    private int month_;
    private int year_;
    public Date()
    {
        this.day_ = 0;
        this.month_ = 0;
        this.year_ = 0;
    }

    public Date(int day, int month, int year)
    {
        this.day_ = day;
        this.month_ = month;
        this.year_ = year;
    }

    @Override
    public String toString()
    {
        String dayS = Integer.toString(day_);
        String monthS = Integer.toString(month_);
        String yearS = Integer.toString(year_);
        return dayS + '.' + monthS + '.' + yearS;
    }
}
