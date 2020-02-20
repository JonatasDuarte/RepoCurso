package br.edu.ifpb;

import java.util.ArrayList;

public class Catalog {

    private ArrayList<Book> BooksList;
    private int amount;

    public Catalog(){
        this.amount = 0;
        this.BooksList = new ArrayList<Book>();
    }

    public int getAmount(){
        return BooksList.size();
    }

    @Override
    public String toString() {
        return this.BooksList.toString();
    }
}
