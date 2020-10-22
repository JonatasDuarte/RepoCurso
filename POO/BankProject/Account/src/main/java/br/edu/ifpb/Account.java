package br.edu.ifpb;

import Exceptions.InsufficientBalanceException;
import Exceptions.InvalidInputException;
import Exceptions.NegativeDepositException;

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

    public boolean deposit(double money) throws InvalidInputException, NegativeDepositException{
        if(money > 0){
            //Adding our deposit to historic
            statement.add("D--"+String.valueOf(money));
            balance += money;
            return true;
        }
        else if (money < 0) throw new NegativeDepositException();
        else throw new InvalidInputException();
    }

    public boolean withdraw(double money) throws InvalidInputException, NegativeDepositException, InsufficientBalanceException {
        if(money <= balance && money > 0){
            //Adding our withdraw to historic
            statement.add("W--"+String.valueOf(money));
            balance  -= money;
            return true;
        }else{
            if(money < 0) throw new NegativeDepositException();

            else if(money > balance) throw new InsufficientBalanceException();

            else throw new InvalidInputException();
        }
    }

    public ArrayList<String> getStatement() {
        return statement;
    }
}
