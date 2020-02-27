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

    public ArrayList<Book> getBooksList() {
        return BooksList;
    }

    public boolean addBook(Book book){
        return BooksList.add(book);
    }

    public  boolean removeBook(int id){
        for(int i=0 ; i < getAmount(); i++){
            if(BooksList.get(i).getId() == id)
                return BooksList.remove(BooksList.get(i));
        }
        return false;
    }

    public boolean searchBook(int id){
        for(int i=0; i< (BooksList.size()); i++){
            if(BooksList.get(i).getId() == id)
                return true;
        }
        return false;

    }

    public void ShowBooks(){
        System.out.println((BooksList.toString()));
    }

    @Override
    public String toString() {
        return "Catalog{ " +
                "BooksList=" + BooksList +
                " }";
    }
}
