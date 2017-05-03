/*
 * 
 * Esta classe nao e suposto ser criada manualmente, serve apenas para uso interno do projeto
 * 
 * 
 */
public class Spot
{
    private boolean hasContainer;
    private boolean hasTruck;
    private int number;
    private Truck truck;
    private Container container;

    public Spot(boolean newHasContainer, boolean newHasTruck)
    {
        hasContainer = newHasContainer;
        hasTruck = newHasTruck;
        truck = null;
        container = null;
    }

    public void setNumber(int newNumber)
    {
        number = newNumber;
    }

    public int getNumber()
    {
        return number;
    }

    public Truck getTruck()
    {
        return truck;
    }

    public boolean hasContainer()
    {
        return hasContainer;
    }

    public boolean hasTruck()
    {
        return hasTruck;
    }

    public void setHasContainer(boolean bool)
    {
        hasContainer = bool;
    }

    public void setHasTruck(boolean bool)
    {
        hasTruck = bool;
    }

    public void saveTruck(Truck truck)
    {
        if(hasContainer == true || hasTruck == true)
        {
            System.out.println("O lugar ja esta ocupado!");
            return;
        }
        else 
        {
            if(truck != null)
            {
                this.truck = truck;
                setHasTruck(true);
            }
            else
            {
                System.out.println("O camiao nao pode ser nulo!");
            }
        }
    }

    public void saveContainer(Container container)
    {
        if(hasContainer == true || hasTruck == true)
        {
            System.out.println("O lugar ja esta ocupado!");
            return;
        }
        else 
        {
            if (container != null) 
            {
                this.container = container;
                setHasContainer(true);
            } 
            else 
            {
                System.out.println("O contentor nao pode ser nulo");
            }
        }
    }

    public void deleteTruck()
    {
        truck = null;
        setHasTruck(false);
    }

    public void deleteContainer()
    {
        container = null;
        setHasContainer(false);
    }

    public void inspect()
    {
        if(hasTruck)
        {
            truck.inspect();
        }
        else
        {
            System.out.println("Não existe nenhum camião estacionado");
        }
    }

}
