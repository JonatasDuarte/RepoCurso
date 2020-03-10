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
        University university = new University((ArrayList) Collections.singletonList(initial));
        Menu menu = new Menu();

        int op = -1;
        while (op != 5){
            menu.showMenu();
            op = inputInt.nextInt();
            int type;
            if(op == 1)
                menu.addEmployeeMessenger();
                type = inputInt.nextInt();
                //Parei aqui
                if(type == 1)
                    university.addEmployee();

        }


    }
}
