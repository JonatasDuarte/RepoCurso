package br.edu.ifpb;

public class Teacher  extends  Employee{

    private int numHours;

    public Teacher() {
        super();
        this.setNumHours(8);
    }

    public Teacher(int id, String name, double baseSalary, int numHours) {
        super(id, name, baseSalary);
        this.numHours = numHours;
    }

    public int getNumHours() {
        return numHours;
    }

    public void setNumHours(int numHours) {
        this.numHours = numHours;
    }

    @Override
    public String toString() {
        return super.toString() +
                "numHours=" + numHours +
                "base salary = R$ " +
                super.getBaseSalary();
    }

    public double getSalary(){
        return super.getBaseSalary() +
                2*numHours;
    }
}
