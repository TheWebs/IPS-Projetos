/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projeto.poo;

import java.util.HashMap;

/**
 *
 * @author franc
 */
public class Users {
    private HashMap<Long, Client> clients;
    
    public Users()
    {
        clients = new HashMap();
    }
    
    public void addClient(String name, long nif)
    {
        Client client;
        if(clients.containsKey(nif))
        {
            System.out.println(ErrorCodes.CLIENT_ALREADY_EXISTS);
            return;
        }
        try
        {
           client = new Client(name, nif);
           clients.put(nif, client);
        }
        catch(IllegalArgumentException ex)
        {
            System.out.println(ErrorCodes.INVALID_NAME);
        }
    }
    
}
