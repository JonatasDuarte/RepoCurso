package br.edu.ifpb;

public class Calculator {

    private String description;
    private double memory;

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public double getMemory() {
        return memory;
    }

    public void setMemory(double memory) {
        this.memory = memory;
    }

    public double sum(double n1, double n2){
        return n1+n2;
    }

    public double dif(double n1, double n2){
        return n1-n2;
    }

    public double mult(double n1, double n2) {
        return n1*n2;
    }

    public double div(double n1, double n2) {
        return n1/n2;
    }

}
