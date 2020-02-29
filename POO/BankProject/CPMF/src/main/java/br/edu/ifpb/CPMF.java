package br.edu.ifpb;

public class CPMF {
    private static final double value  = 0.01;

    private double calculate(double withdraw){
        return withdraw*value;
    }

    public double discount(double balance, double withdraw){
        return balance-calculate(withdraw);
    }
}
