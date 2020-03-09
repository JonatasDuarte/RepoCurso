package br.edu.ifpb;

public class Professor extends Employee{
    private int numHours;

    public Professor() {
        super();
        this.setNumHours(8);
    }

    public Professor(int id, int age, String address, String name, double baseSalary, int numHours) {
        super(id,age, address, name, baseSalary);
        this.numHours = numHours;
    }

    public int getNumHours() {
        return numHours;
    }

    void setNumHours(int numHours) {
        if(numHours > 0)
            this.setNumHours(numHours);
    }

    @Override
    public String toString() {
        return super.toString() +
                "numHours=" + numHours +
                "base salary= R$ " +
                super.getBaseSalary();
    }

    public double getSalary(){
        return super.getBaseSalary() +
                20*numHours;
    }
}
