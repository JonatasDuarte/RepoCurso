package br.edu.ifpb;

public class Manager extends Employee {
    private double commission;

    public Manager() {
        super();
        this.setCommission(500);
    }

    public Manager(int id, int age, String address, String name, double baseSalary, double commission){
        super(id, age, address, name, baseSalary);
        this.commission = commission;
    }

    public double getCommission() {
        return commission;
    }

    public void setCommission(double commission) {
        this.commission = commission;
    }

    public double getSalary(){
        return super.getBaseSalary() +
                commission;
    }

    @Override
    public String toString(){
        return super.toString() +
                "Sales commission= "+ commission +
                "base salary = R$ " + super.getBaseSalary();
    }
}
