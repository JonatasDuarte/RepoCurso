package br.edu.ifpb;

public class Manager extends Employee{

    private double salesComission;

    public Manager() {
        super();
        this.setSalesComission(50);
    }

    public Manager(int id, String name, double baseSalary, double salesComission) {
        super(id, name, baseSalary);
        this.salesComission = salesComission;
    }

    public double getSalesComission() {
        return salesComission;
    }

    public void setSalesComission(double salesComission) {
        this.salesComission = salesComission;
    }

    public double getSalary(){
        return super.getBaseSalary() +
                salesComission;
    }

    @Override
    public String toString() {
        return super.toString() +
                "Sales Comission =" + salesComission +
                "Base Salary = R$ " +
                super.getBaseSalary();
    }
}
