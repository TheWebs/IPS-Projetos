/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package projeto.poo;

import java.util.Scanner;

/**
 *
 * @author franc
 */
public class ProjetoPOO {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        boolean running = true;
        while(running)
        {
            System.out.println("\n\n\n"); //limpar consola
            Scanner leitor = new Scanner(System.in);
            System.out.println("1- Alugar / Devolver bicicleta\n" +
            "2- Utilizadores registados ou por registar (criar ou alterar utilizador / pagar\n" +
            "anuidade)\n" +
            "3- Comprar bilhete 1 a 7 dias\n" +
            "4- Visualizar estações\n" +
            "5- Fazer manutenção\n" +
            "0- Sair");
            String answer = leitor.next();
            int option = 0;
            try
            {
                option = Integer.parseInt(answer);
            }catch(NumberFormatException ex)
            {
                System.out.println("Tem que inserir um numero!!");
                main(new String[0]);
            }
            switch(option)
            {
                case 0:
                    running = false;
                    break;
                case 1:
                    System.out.println("1");
                    break;
                case 2:
                    System.out.println("2");
                    break;
                case 3:
                    System.out.println("3");
                    break;
                case 4:
                    System.out.println("4");
                    break;
                case 5:
                    System.out.println("5");
                    break;
                default:
                    System.out.println("O numero tem que estar entre 0 e 5 (inclusive)");
                    break;
            }
    }
    }
    
}
