package br.edu.ifpb;

import java.util.ArrayList;

public class StatementPrinter {

    public void showStatement(ArrayList<String> statement){
        for (String s : statement)
            System.out.println(s);
    }
}
