package br.ifpb.edu;

import br.edu.ifpb.Book;
import br.edu.ifpb.Catalog;

import java.util.Scanner;

public class Interface {

    public static void main(String[] args) {
        Scanner inputInt = new Scanner(System.in);
        Scanner inputDouble = new Scanner(System.in);
        Scanner inputStr = new Scanner(System.in);
        //New Catalog
        Catalog catalog = new Catalog();

        //Creating book without constructor
        Book withoutConstructor = new Book();
        withoutConstructor.setTittle("This is a tittle");
        withoutConstructor.setId(1);
        withoutConstructor.setPrice(10.0);

        //Creating book with constructor
        Book withConstructor = new Book(2, "Another tittle", 5.0);

        //Creating book with input
        Book withInput = new Book();
        System.out.print("Enter the ID: ");
        withInput.setId(inputInt.nextInt());
        System.out.print("Enter the Tittle: ");
        withInput.setTittle(inputStr.nextLine());
        System.out.print("Enter the Price: ");
        withInput.setPrice(Double.parseDouble(inputDouble.nextLine()));

        //Putting books on catalog
        catalog.addBook(withoutConstructor);
        catalog.addBook(withConstructor);
        catalog.addBook(withInput);

        //Printing the amount of books
        System.out.println(catalog.getAmount());

        //Removing a book by ID
        catalog.removeBook(1);

        //Showing the existence of a book
        System.out.println(2);
        System.out.println(withInput.getId());
        System.out.println(4);

        //Showing the catalog
        System.out.println(catalog);
        catalog.ShowBooks();



    }
}
