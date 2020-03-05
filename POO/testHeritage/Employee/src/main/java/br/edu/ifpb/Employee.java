package br.edu.ifpb;

public class Employee {

    private int id;
    private String name;
    private double baseSalary;

    public Employee(){
        this(0, "--- Null ----", 980.90);
    }

    public Employee(int id, String name, double baseSalary){
        this.setId(id);
        this.setName(name);
        this.setBaseSalary(baseSalary);
    }
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }


    public double getBaseSalary() {
        return baseSalary;
    }

    public void setBaseSalary(double baseSalary) {
        this.baseSalary = baseSalary;
    }

    @Override
    public String toString() {
        return "Employee{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", baseSalary=" + baseSalary +
                '}';
    }
}
