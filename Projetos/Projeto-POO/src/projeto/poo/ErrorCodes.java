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
public enum ErrorCodes {
    CLIENT_ALREADY_EXISTS, INVALID_NAME;
    
    @Override
    public String toString()
    {
        switch(this)
        {
            case CLIENT_ALREADY_EXISTS:
                return "Erro: ja existe um cliente com o nif inserido!";
            case INVALID_NAME:
                return "Erro: o nome nao pode ser nulo!";
            default:
                return "Erro";
        }
    }
}
