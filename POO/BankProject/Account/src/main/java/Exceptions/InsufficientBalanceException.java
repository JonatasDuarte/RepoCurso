package Exceptions;

public class InsufficientBalanceException extends Exception{
    public InsufficientBalanceException() {
        super("Insufficient balance!\n");
    }
}
