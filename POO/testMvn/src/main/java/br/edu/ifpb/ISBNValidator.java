package br.edu.ifpb;

import java.lang.String;

public class ISBNValidator {

    public boolean checkNumber(String isbn) {
       int sum = 0;
       for(int i= 1; i <= isbn.length(); i++){
            sum += Character.digit(isbn.charAt(i-1), 10) * i;
       }
       return sum % 11 == 0;
    }

}
