package br.edu.ifpb;

import Exceptions.InsufficientBalanceException;
import Exceptions.InvalidInputException;
import Exceptions.NegativeDepositException;

import java.util.ArrayList;
import java.util.Scanner;

public class App {
    public static void main(String[] args) throws NegativeDepositException, InvalidInputException, InsufficientBalanceException {
        Scanner input = new Scanner(System.in);
        MenuBank menu = new MenuBank();
        int op = 0;
        System.out.println("\n----- Welcome to Duarte's Bank! -----\n");
        System.out.print("Enter the holder's name: ");
        String holder = input.nextLine();
        System.out.print("Enter the number's account: ");
        int number = input.nextInt();
        Account account = new Account(number, holder);
        StatementPrinter statement = new StatementPrinter();
        while(op != 5){
            menu.showMenu();
            op = input.nextInt();
            Scanner inputDouble = new Scanner(System.in);
            if(op == 5)
                System.out.println("Thanks for using Duarte's Bank!");
            else if (op == 1){
                System.out.print("Enter how much you want: ");
                try {
                    boolean tru = account.withdraw(inputDouble.nextDouble());
                }catch (Exception e) {
                    System.out.print(e);
                }
            } else if(op == 2) {
                System.out.print("Enter how much you want: ");
                try {
                    boolean tru = account.deposit(inputDouble.nextDouble());
                } catch (Exception e) {
                    System.out.println(e);
                }
            } else if (op == 3)
                System.out.println(account.getBalance());
            else if (op == 4)
                statement.showStatement(account.getStatement());
            else
                System.out.println("Invalid option, try again.");
        }

    }
}
