package br.edu.ifpb;

import org.junit.Assert;
import org.junit.Test;



public class ISBNValidatorTest {
    @Test
    public void TestValidISBN(){
        ISBNValidator isbn = new ISBNValidator();
        Assert.assertTrue(isbn.checkNumber("0306406152"));
        Assert.assertFalse(isbn.checkNumber("120111122"));

    }
}
