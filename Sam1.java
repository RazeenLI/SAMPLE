import java.time.*;

public class Sam1
{
    public static void main(String[] args) 
    {
        Manager boss = new Manager("Boss Bo", 80000, 1966, 12, 11);
        Employee[] staff = new Employee[4];
        staff[0] = boss;
        boss.setBonus(10000);
        staff[1] = new Employee ("Carl Cracker ", 75000, 1987, 12, 15);  
        staff[2] = new Employee ("Harry Hacker ", 50000, 1989, 10, 1);
        staff[3] = new Employee ("Tony Tester", 40000, 1990, 3, 15);

        for (Employee ex : staff)
        {
            System.out.println("name\t" + ex.getName());
            System.out.println("ID\t" + ex.getID());
            System.out.println("Salary\t" + ex.getSalary() + "\n");
        }

        int n = Employee.getNextID();
        System.out.println("Next available ID\t" + n);

        trivalue(staff[0].getSalary());
        System.out.println(staff[0].getSalary());
    } 

    public static void trivalue(double x)
    {
        x *= 3;
        System.out.println("the result of x is " + x);
    }
}

class Employee
{
    private static int nextID = 1;
    
    private String name = "";
    private double salary = 0;
    private LocalDate hireDay;
    private int ID;

    public Employee(String aName, double aSalary, int year, int month, int day)
    {
        this.name = aName;
        this.salary = aSalary;
        this.hireDay = LocalDate.of(year, month, day);
        setID();
    }

    public String getName()
    {
        return this.name;
    }

    public double getSalary() 
    {
        return this.salary;
    }

    public LocalDate getHireDay()
    {
        return this.hireDay;
    }

    public int getID()
    {
        return this.ID;
    }

    public void setID()
    {
        ID = nextID;
        nextID++;
    }

    public static int getNextID() 
    {
        return nextID;
    }

    public void raiseSlary(double byPercent)
    {
        double raise = this.salary * byPercent / 100;
        this.salary += raise;
    }

    public static void main(String[] args)
    {
        Employee ex = new Employee("Harry", 50000, 2020, 12, 20);
        System.out.println(ex.getName() + " " + ex.getSalary());
    }
}

class Manager extends Employee
{
    private double bonus = 0;
    
    public Manager(String aName, double aSalary, int year, int month, int day)
    {
        super(aName, aSalary, year, month, day);
        bonus = 0;
    }

    public void setBonus(double aBonus)
    {
        this.bonus = aBonus;
    }

    public double getSalary()
    {
        return bonus + super.getSalary();
    }
}