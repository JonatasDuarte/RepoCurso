package br.edu.ifpb;
import java.util.Scanner;

public class MenuCalculator {
    Scanner inputDouble = new Scanner(System.in);
    public void showMenu(){
        System.out.println("\n-----------CALCULATOR-----------");
        System.out.println("Enter '1' to sum");
        System.out.println("Enter '2' to subtract");
        System.out.println("Enter '3' to multiply");
        System.out.println("Enter '4' to divide");
        System.out.println("Enter '5' to get memory");
        System.out.println("Enter '6' to set memory");
        System.out.println("Enter '7' to get description");
        System.out.println("Enter '8' to set description");
        System.out.println("Enter '0' to close the menu.");
    }

    public double[] catchNumbers(){
        double[] nums = new double[2];
        System.out.print("Enter the first number: ");
        nums[0] = inputDouble.nextDouble();
        System.out.print("Enter the second number: ");
        nums[1] = inputDouble.nextDouble();
        return nums;
    }
}

