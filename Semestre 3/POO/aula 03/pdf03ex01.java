public class pdf03ex01 {
    public static void main(String[] args) {
        Department aaa = new Department("foda", 123);
        Employee meudeus = new Employee("pedrão", 123123, "tristeza");

        meudeus.setDept(aaa);
        aaa.addEmployee(meudeus);
        meudeus.setSalary(4000.54);
        //aaa.listAllEmployees();
        System.out.println(aaa.getEmployee(123123).getAnnualSalary());
    }
}
