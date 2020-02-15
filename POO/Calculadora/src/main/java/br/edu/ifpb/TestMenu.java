package br.edu.ifpb;
import java.util.Scanner;

public class TestMenu {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        MenuCalculator menu = new MenuCalculator();
        Calculator calc = new Calculator();
        int op = -1;
        while (op != 0) {
            menu.showMenu();
            op = input.nextInt();
            if(op == 0)
                System.out.println("Thanks for using my calculator!");

            else if (op >= 1 && op <= 4) {
                double[] nums = menu.catchNumbers();
                System.out.print("Result: ");
                if (op == 1)
                    System.out.println(calc.sum(nums[0], nums[1]));

                else if (op == 2)
                    System.out.println(calc.dif(nums[0], nums[1]));

                else if (op == 3)
                    System.out.println(calc.mult(nums[0], nums[1]));

                else if (op == 4)
                    System.out.println(calc.div(nums[0], nums[1]));

            }
            else if (op > 4 && op < 9) {
                System.out.print("This: ");
                    if (op == 5)
                        System.out.println(calc.getMemory());

                    else if (op == 6) {
                        Scanner inputMemory = new Scanner(System.in);
                        calc.setMemory(inputMemory.nextDouble());

                    } else if (op == 8) {
                        Scanner inputDescription = new Scanner(System.in);
                        calc.setDescription(inputDescription.nextLine());

                    } else if (op == 7)
                        System.out.println(calc.getDescription());

                }
            else
                System.out.println("Invalid option, try again! ");
        }

    }
}
