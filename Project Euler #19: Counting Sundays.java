import java.io.*;
import java.util.*;
import java.time.LocalDate;
import java.time.temporal.TemporalAdjusters;
import java.time.DayOfWeek;
public class Solution {

    public static void main(String[] args) {
        Scanner sc  = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            long startYear, endYear;
            int month, dayOfMonth;
            startYear = sc.nextLong();
            month = sc.nextInt();
            dayOfMonth = sc.nextInt();
            
            LocalDate startDate = LocalDate.of((int)(startYear % 2800), month, dayOfMonth); // calander repeats every 2800 years
            
            endYear = sc.nextLong();
            month = sc.nextInt();
            dayOfMonth = sc.nextInt();
            int diff = (int)(endYear - startYear);
            LocalDate endDate = LocalDate.of((int)(startYear % 2800) + diff, month, dayOfMonth);// instead of finding endYear % 2800. We are just adding the original diff with startYear % 2800 

// why are we doing this? % 2800 will give a number < 2800.
// Say startDate % 2800 is a number greater than 0 and less than 2800
// end date % 2800 is 0, i.e end date is exactly divisible by 2800. This makes all the trouble. Now startDate year > endDate year.

// so storing endDate as starDate % 2800 + original difference avoids this!

            if(endDate.isBefore(startDate)){
                LocalDate temp = startDate;
                startDate = endDate;
                endDate = temp;
            }
            int sundays = 0;
            while(startDate.isBefore(endDate)){
                if(startDate.getDayOfWeek() == DayOfWeek.SUNDAY && startDate.getDayOfMonth() == 1)
                sundays++;

                startDate = startDate.with(TemporalAdjusters.firstDayOfNextMonth());
                
            }

            if(startDate.isEqual(endDate)){
                if(startDate.getDayOfMonth() == 1 && startDate.getDayOfWeek() == DayOfWeek.SUNDAY)
                    sundays++;
            }

            System.out.println(sundays);

        }
    }
}

