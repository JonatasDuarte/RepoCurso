package br.edu.ifpb;

import java.sql.Statement;
import java.util.ArrayList;

public class Account {
    private int number;
    private String holder;
    private double balance;
    private ArrayList<String> statement;

    public Account(int number, String holder){
        setNumber(number);
        setHolder(holder);
        statement = new ArrayList<String>();
    }

    public boolean setNumber(int number) {
        if(number > 0){
            this.number = number;
            return true;
        }
        return false;
    }

    public boolean setHolder(String holder) {
        if(!holder.isBlank()){
            this.holder = holder;
            return true;
        }
        return false;
    }

    public int getNumber() {
        return number;
    }

    public String getHolder() {
        return holder;
    }

    public double getBalance() {
        return balance;
    }

    public boolean deposit(double money){
        if(money > 0){
            //Adding our deposit to historic
            statement.add("D--"+String.valueOf(money));
            balance += money;
            return true;
        }
        return false;
    }

    public boolean withdraw(double money){
        if(money <= balance && money > 0){
            //Adding our withdraw to historic
            statement.add("W--"+String.valueOf(money));
            balance  -= money;
            return true;
        }
        return false;
    }

    public ArrayList<String> getStatement() {
        return statement;
    }
}
