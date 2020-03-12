package br.edu.ifpb;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

public class EmployeeTest {
    Employee employee = new Employee(1, 18, "Brasil","jao", 480);
    Professor prof = new Professor(2, 29, "Wakanda", "Panth", 480, 12);
    Manager manager = new Manager(3, 34, "Brasil", "tobi", 480, 500);

    @Test
    void checkingID(){
        assertEquals(1, employee.getId());
        assertEquals(2, prof.getId());
        assertEquals(2, manager.getId());

        assertNotEquals(3, employee.getId());
        assertNotEquals(1, prof.getId());
        assertNotEquals(2, manager.getId());
    }

    @Test
    void checkingSalary(){
        assertEquals(480, employee.getBaseSalary());
        assertEquals(480, prof.getBaseSalary());
        assertEquals(480, manager.getBaseSalary());

        assertNotEquals(302, employee.getBaseSalary());
        assertNotEquals(1451, prof.getBaseSalary());
        assertNotEquals(22, manager.getBaseSalary());

    }

}
