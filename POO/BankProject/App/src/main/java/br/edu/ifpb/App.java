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
        System.out.print("Enter the holder's name: ");
        Account account = new Account(1, input.nextLine());
        StatementPrinter statement = new StatementPrinter();
        while(op != 5){
            menu.showMenu();
            op = input.nextInt();
            Scanner inputDouble = new Scanner(System.in);
            if(op == 5)
                System.out.println("Thanks for using 'Checking Account'!");
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
