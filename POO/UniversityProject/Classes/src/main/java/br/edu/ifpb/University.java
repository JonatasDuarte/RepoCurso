package br.edu.ifpb;

import java.util.ArrayList;

public class University {
    private ArrayList<Employee> employees;

    public University(ArrayList employees) {
        this.setEmployees(employees);
    }

    public ArrayList<Employee> getEmployees() {
        return employees;
    }

    public void setEmployees(ArrayList<Employee> employees) {
        this.employees = employees;
    }

    boolean addEmployee(Employee employee){
        return employees.add(employee);
    }

    boolean removeEmployee(int id) {
        return employees.removeIf(employee -> employee.getId() == id);
    }

    Employee getEmployee(int id) {
        return employees.stream().filter(x -> x.getId() == id).findFirst().orElse(null);
    }

    @Override
    public String toString() {
        return "University{" +
                "employees=" + employees +
                '}';
    }
}
