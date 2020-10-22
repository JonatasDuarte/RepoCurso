package Exceptions;

public class NegativeDepositException extends Exception {
    public NegativeDepositException() {
        super("Invalid deposit!\n");
    }
}
