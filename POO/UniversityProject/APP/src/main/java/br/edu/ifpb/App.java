package br.edu.ifpb;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class App {

    public static void main(String[] args) {
        Scanner inputInt = new Scanner(System.in);
        Scanner inputString = new Scanner(System.in);
        Scanner inputDouble = new Scanner(System.in);

        Manager initial = new Manager(1, 512, "Nárnia", "Aslam", 33000);
        University university = null;
        Menu menu = new Menu();

        int option = -1;
        while (option != 5) {
            menu.showMenu();
            option = inputInt.nextInt();
            int type;
            if (option == 1) {
                menu.addEmployeeMessager();

                type = inputInt.nextInt();

                menu.employeeMessage(1, type);
                int id = inputInt.nextInt();
                menu.employeeMessage(2, type);
                int age = inputInt.nextInt();
                menu.employeeMessage(3, type);
                String address = inputString.nextLine();
                menu.employeeMessage(4, type);
                String name = inputString.nextLine();

                int hours;
                double commission;

                if (type != 3) {
                    menu.employeeMessage(5, type);

                    if (type == 1) {
                        hours = inputInt.nextInt();

                        Professor professor = new Professor(id, age, address, name, 480, hours);

                        if (university == null)
                            university = new University(new ArrayList<>(Collections.singletonList(professor)));
                        else
                            university.addEmployee(professor);
                    }
                    if (type == 2) {
                        commission = inputDouble.nextDouble();

                        Manager manager = new Manager(id, age, address, name, commission);

                        if (university == null)
                            university = new University(new ArrayList<>(Collections.singletonList(manager)));
                        else
                            university.addEmployee(manager);
                    } else {
                        Employee employee = new Employee(id, age, address, name, 480);

                        if (university == null)
                            university = new University(new ArrayList<>(Collections.singletonList(employee)));
                        else
                            university.addEmployee(employee);
                    }
                }
            }

            if (option == 2) {
                if (university != null) {
                    menu.employeeIDMessage();

                    int ID = inputInt.nextInt();

                    university.removeEmployee(ID);

                    if (university.getEmployees().size() == 0)
                        university = null;
                }

            }

            if (option == 3) {
                if (university != null) {
                    menu.employeeIDMessage();

                    int ID = inputInt.nextInt();

                    menu.printEmployee(university.getEmployee(ID));
                }

            }

            if (option == 4)
                menu.printAllEmployee(university);

            if (option == 5)
                menu.thanks();
        }
    }
}
