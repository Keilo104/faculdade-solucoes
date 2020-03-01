public class Employee {
    private String name;
    private long id;
    private double salary;
    private String jobTitle;
    private Department dept;
    private Department deptInCharge;

    public Employee(String name, long id, String job) {
        this.name = name;
        this.id = id;
        this.jobTitle = job;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public long getId() {
        return id;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public String getJobTitle() {
        return jobTitle;
    }

    public void setJobTitle(String jobTitle) {
        this.jobTitle = jobTitle;
    }

    public Department getDept() {
        return dept;
    }

    public void setDept(Department dept) {
        this.dept = dept;
    }

    public Department getDeptInCharge() {
        return deptInCharge;
    }

    public void setDeptInCharge(Department deptInCharge) {
        this.deptInCharge = deptInCharge;
    }

    public void printState() {
        System.out.printf("Nome: %s\n", this.name);
        System.out.printf("ID: %d\n", this.id);
        System.out.printf("Salário: %f\n", this.salary);
        System.out.printf("Título de Emprego: %s\n\n", this.jobTitle);
    }

    public double getAnnualSalary() {
        return this.salary * 12;
    }
}
