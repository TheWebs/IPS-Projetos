/**
* Esta classe representa uma Loja.
* @author Francisco Leal e Hugo Ferreira
* @version 2.0
*/
public class Store
{
    private String name;
    private Position position;
    private Storage productsStorage;
    private int currentContainers;
    private int maxContainers;
    
    public Store(String newName, Position newPosition)
    {
        if(newName == null)
        {
            name = "Desconhecido";
        }
        else 
        {
            name = newName;
        }
        if(newPosition == null)
        {
            position = new Position(1, 1);
        }
        else 
        {
            position = newPosition;
        }
        maxContainers = 2;
        currentContainers = 0;
        productsStorage = new Storage();
    }
    
    public Store()
    {
        name = "Desconhecido";
        position = new Position(1, 1);
        maxContainers = 2;
        currentContainers = 0;
        productsStorage = new Storage();
    }
    
    public void unloadTruck(Truck truck)
    {
        boolean found = false;
        if(currentContainers+1 > maxContainers)
        {
            System.out.println("Esta loja nao tem mais espaco para armazenar contentores!");
            return;
        }
        if(truck.getContainer() == null) 
        {
            System.out.println("Nao existe nenhum contentor no camiao!");
            return;
        }
        if(truck.getPosition().isEqual(position))
        {
            for(int i = 0; i<truck.getContainer().getProducts().length; i++)
            {
                if(productsStorage.checkForProduct(truck.getContainer().getProducts()[i].getName()))
                {
                        productsStorage.increaseQuantity(truck.getContainer().getProducts()[i].getQuantity(), truck.getContainer().getProducts()[i].getName());
                        found = true;
                        break;
                }
                else 
                {
                        found = false;
                }
                if(found == false)
                {
                        productsStorage.add(truck.getContainer().getProducts()[i]);
                }
            }
            currentContainers++;
            truck.unloadTruck();
        }
        else
        {
            System.out.println("Um camiao apenas pode ser carregado quando se encontra na mesma localizacao que a estacao!");
        }
    }
    
    public void sellProduct(String newName, int newQuantity)
    {
       productsStorage.removeProduct(newName, newQuantity);
    }
    
    public Position getPosition()
    {
        return position;
    }
    
    public String toString()
    {
        String temp = "----Loja----\nNome: " + name + "\n" + position.toString() + "\nProdutos no armazem:\n" + productsStorage.toString();
        temp += "------------";
        return temp;
    }
    
    public void showInfo()
    {
        System.out.println(toString());
    }
}
