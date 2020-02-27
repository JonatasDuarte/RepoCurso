package br.edu.ifpb;

public class Book {

    private int id;
    private String tittle;
    private double price;

    public Book(){
        this.setId(0);
        this.setTittle("No tittle");
        this.setPrice(0.0);
    }

    public Book(int id, String tittle, double price) {

        this.setId(id);
        this.setTittle(tittle);
        this.setPrice(price);
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        if(id >= 0)
            this.id = id;
    }

    public String getTittle() {
        return tittle;
    }

    public void setTittle(String tittle) {

        this.tittle = tittle;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        if(price>=0)
            this.price = price;
    }

    @Override
    public String toString(){
        return "Book{" +
                "id=" + id +
                ", tittle= "+ tittle +
                ", price:" + price +
                 "}";
    }
}
