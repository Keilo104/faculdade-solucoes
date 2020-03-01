import java.util.ArrayList;

public class Department {
    private String name;
    private int code;
    private String location;
    private int phoneExtention;
    private double budget;
    private Employee chief;
    private ArrayList<Employee> staff;


    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getCode() {
        return code;
    }

    public String getLocation() {
        return location;
    }

    public void setLocation(String location) {
        this.location = location;
    }

    public int getPhoneExtention() {
        return phoneExtention;
    }

    public void setPhoneExtention(int phoneExtention) {
        this.phoneExtention = phoneExtention;
    }

    public double getBudget() {
        return budget;
    }

    public void setBudget(double budget) {
        this.budget = budget;
    }

    public Employee getChief() {
        return chief;
    }

    public void setChief(Employee chief) {
        this.chief = chief;
    }

    public Department(String name, int code) {
        this.name = name;
        this.code = code;

        this.staff = new ArrayList<>();
    }

    public void addEmployee(Employee e) {
        this.staff.add(e);
    }

    public void removeEmployee(Employee e) {
        this.staff.remove(e);
    }

    public void removeEmployee(long id) {
        for (Employee employee : this.staff) {
            if(employee.getId() == id) {
                this.staff.remove(employee);
            }
        }
    }

    public void listAllEmployees() {
        for (Employee employee : this.staff) {
            employee.printState();
        }
    }

    public int sizeOfEmployees() {
        return this.staff.size();
    }

    public Employee getEmployee(long id) {
        for (Employee employee : this.staff) {
            if (id == employee.getId()) {
                return employee;
            }
        }
        return null;
    }

}
