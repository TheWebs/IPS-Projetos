
import java.util.ArrayList;
/**
* Esta classe representa um "monitor" de camioes, isto e controla todos os camioes existentes.
* @author Francisco Leal e Hugo Ferreira
* @version 2.0
*/
public class CentralTruckInformation
{
    private ArrayList<Truck> list;

    public CentralTruckInformation()
    {
        list = new ArrayList<Truck>();
    }

    public void addTruck(Truck truck)
    {
        if(truck == null)
        {
            System.out.println("Camiao invalido!");
            return;
        }
        if(list.size() != 0)
        {
            for(int i = 0; i<list.size(); i++)
            {
                if(list.get(i).equals(truck))
                {
                    System.out.println("Esse camiao ja se encontra listado!");
                    return;
                }
                if(i+1 == list.size())
                {
                    list.add(truck);
                    return;
                }
            }
        }
        else
        {
            list.add(truck);
        }
    }

    public void removeTruck(Truck truck)
    {
        if(truck == null)
        {
            System.out.println("Camiao invalido!");
            return;
        }
        for(int i = 0; i<list.size(); i++)
        {
            if(list.get(i).equals(truck))
            {
                list.remove(i);
                return;
            }
            if(i+1 == list.size())
            {
                System.out.println("O camiao fornecido nao se encontra listado!");
            }
        }
    }

    public void listTrucks()
    {
        System.out.println("Camioes:");
        for(int i = 0; i<list.size(); i++)
        {
            System.out.println("    - Matricula: " + list.get(i).getNumber()); 
        }
    }

    public void listTrucksInRadius(int rad, Position pos)
    {
        if(rad > 0 && pos != null)
        {
            System.out.println("Camioes num raio de " + rad + " kilometros: \n");
            for(int i = 0; i<list.size();i++)
            {
                if ((Math.pow((list.get(i).getPosition().getLatitude()-pos.getLatitude()), 2) + Math.pow((list.get(i).getPosition().getLongitude() - pos.getLongitude()), 2) <= Math.pow(rad, 2)))
                {
                    System.out.println("[Nome = " + list.get(i).getName() + "] [Matricula = " + list.get(i).getNumber() + "]");
                } 
                else
                {
                    //nada
                }
            }
        }
        else
        {
            System.out.println("Argumentos invalidos");
        }
    }

    public void checkTrucks()
    {
        for(int i = 0; i<list.size();i++)
        {
            if(list.get(i).getKilometersSinceInspection() > 10000)
            {
                 System.out.println("[Nome = " + list.get(i).getName() + "] [Matricula = " + list.get(i).getNumber() + "] [Kilometros desde a inspecao = " + list.get(i).getKilometersSinceInspection() + "]");
            }
            else
            {
                //nada
            }
        }
    }

    public void countNewTrucks()
    {
     for(int i = 0; i<list.size();i++)
        {
            if(list.get(i).getKilometers() < 50000)
            {
                 System.out.println("[Nome = " + list.get(i).getName() + "] [Matricula = " + list.get(i).getNumber() + "] [Kilometros = " + list.get(i).getKilometers() + "]");
            }
            else
            {
                //nada
            }
        }   
    }

    public void countOldTrucks()
    {
        for(int i = 0; i<list.size();i++)
        {
            if(list.get(i).getKilometers() > 1000000)
            {
                 System.out.println("[Nome = " + list.get(i).getName() + "] [Matricula = " + list.get(i).getNumber() + "] [Kilometros = " + list.get(i).getKilometers() + "]");
            }
            else
            {
                //nada
            }
        } 
    }
}