package br.edu.ifpb;
public class Menu {

    public void showMenu(){
        System.out.println("1 - Add an Employee");
        System.out.println("2 - Remove an Employee");
        System.out.println("3 - Search an Employee");
        System.out.println("4 - Show all Employees");
        System.out.println("5 - Quit");
    }

    public void employeeMessenger(int menssage, int op){
        if(menssage == 1)
            System.out.print("Enter the Employee's ID: ");
        else if(menssage == 2)
            System.out.print("Enter the Employee's age: ");
        else if(menssage == 3)
            System.out.print("Enter the Employee's address: ");
        else if(menssage == 4)
            System.out.print("Enter the Employee's name: ");
        else if(menssage == 5){
            if(op == 1)
                System.out.println("Enter the work hours: ");
            else if(op == 2)
                System.out.println("Enter the sales commission: ");
        }
    }

    public void addEmployeeMessenger(){
        System.out.println("Enter the type of Employee: ");
        System.out.println("'1' for Professor");
        System.out.println("'2' for Manager");
    }

    public void removeEmployeeMessenger(){
        System.out.println("Enter the Employee's ID that you want to remove: ");
    }

    public void searchEmployeeMessenger(){
        System.out.println("Enter the Employee's ID that you want to search: ");
    }

    public void printEmployee(Employee employee){
        System.out.println(employee.toString());
    }

    public void printAllEmployee(University university){
        System.out.println(university.toString());
    }

    public void thanks(){
        System.out.println("Thank you for use the App !");
    }


}
