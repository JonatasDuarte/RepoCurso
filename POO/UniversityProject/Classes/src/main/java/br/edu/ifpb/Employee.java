package br.edu.ifpb;

public class Employee {
    private int id;
    private int age;
    private String address;
    private String name;
    private double baseSalary;

    public Employee(){
        this(0, 18,"--- No Address ---", "--- No name ---", 480.0);
    }

    public Employee(int id, int age, String address, String name, double baseSalary) {
        this.setId(id);
        this.setAge(age);
        this.setAddress(address);
        this.setName(name);
        this.setBaseSalary(baseSalary);
    }


    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getAddress() {
        return address;
    }

    void setAddress(String address) {
        this.address = address;
    }

    public String getName() {
        return name;
    }

    void setName(String name) {
        this.name = name;
    }

    public double getBaseSalary() {
        return baseSalary;
    }

    void setBaseSalary(double baseSalary) {
        this.baseSalary = baseSalary;
    }

    @Override
    public String toString() {
        return "Employee {" +
                "id=" + id +
                ", age=" + age +
                ", address='" + address + '\'' +
                ", name='" + name + '\'' +
                ", baseSalary=" + baseSalary +
                '}';
    }
}
