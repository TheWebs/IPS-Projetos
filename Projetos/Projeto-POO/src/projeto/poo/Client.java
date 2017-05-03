/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projeto.poo;

/**
 *
 * @author franc
 */
public class Client {
    private String name;
    private long nif;
    private boolean hasRent;
    
    public Client(String name, long nif)
    {
        if(name == null)
        {
            throw new IllegalArgumentException();
        }
        this.name = name;
        this.nif = nif;
    }

    public String getName() {
        return name;
    }

    public long getNif() {
        return nif;
    }

    public boolean HasRent() {
        return hasRent;
    }
    
    
    
}
