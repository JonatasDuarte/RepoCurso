package br.edu.ifpb;

import java.util.Scanner;

public class MenuBank {

    public void showMenu(){
        Scanner input = new Scanner(System.in);
        System.out.println("------- Checking Account -------");
        System.out.println("Enter '1' to Withdraw");
        System.out.println("Enter '2' to Deposit");
        System.out.println("Enter '3' to Show Balance");
        System.out.println("Enter '4' to Show Statement");
        System.out.println("Enter '5' to Quit");
        System.out.println("--------------------------------");
    }

}
