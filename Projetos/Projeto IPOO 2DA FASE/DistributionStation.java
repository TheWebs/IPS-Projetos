
import java.util.ArrayList;
/**
* Esta classe representa uma estacao de distribuicao de produtos.
* @author Francisco Leal e Hugo Ferreira
* @version 2.0
*/
public class DistributionStation
{
    private String name;
    private Position position;
    private Storage productsToSupply;
    private ArrayList<Container> availableContainers;
    private int maxContainers;

    public DistributionStation(String newName, Position newPosition, ArrayList<Product> newProductsToSupply, int numberOfContainers)
    {
        if(newName.equals(null)) 
        {
            name = "Desconhecido";
        }
        else 
        {
            name = newName;
        }
        if(newPosition == null) 
        {
            position = new Position(0, 0);
        }
        else 
        {
            position = newPosition;
        }
        if(newProductsToSupply == null) 
        {
            productsToSupply = new Storage();
        }
        else 
        {
            productsToSupply.loadInicialProducts(newProductsToSupply);
        }
        if(numberOfContainers < 1) 
        {
            numberOfContainers = 1;
        }
        availableContainers = new ArrayList<Container>();
        maxContainers = numberOfContainers;
    }

    public ArrayList<Container> getContainers()
    {
        return availableContainers;
    }

    public DistributionStation()
    {
        name = "Desconhecido";
        position = new Position(1, 1);
        productsToSupply = new Storage();
        availableContainers = new ArrayList<Container>();
        maxContainers = 1;
    }

    public void loadTruck(Truck truck, Container container)
    {
        if(truck.getPosition().isEqual(position))
        {
            if(container == null)
            {
                System.out.println("O contentor tem que ser valido!");
            }
            else
            {
                truck.loadTruck(container);
            }
        }
        else
        {
            System.out.println("Um camiao apenas pode ser carregado quando se encontra na mesma localizacao que a estacao!");
        }
    }

    public void loadContainer(ArrayList<Product> products, int containerNumber)
    {
        if(products == null)
        { 
            System.out.println("Lista de produtos invalida!)");
            return;
        } 
        if(availableContainers.size() == maxContainers)
        {
            System.out.println("Ja nao ha contentores disponiveis nesta estacao!");
            return;
        } 
        availableContainers.add(new Container(false, containerNumber));
        Product temp;
        for(int i = 0; i<products.size(); i++)
        {
            if(productsToSupply.checkForProduct(products.get(i).getName()))
            {
                temp = products.get(i);
                if(productsToSupply.removeProduct(products.get(i).getName(), products.get(i).getQuantity()))
                {
                    availableContainers.get(availableContainers.size()-1).loadProduct(temp);
                }
            }
            else 
            {
                   System.out.println("Produto " + products.get(i).getName() + " nao encontrado no armazem!");
            }
        }
    }

    public void receiveProducts(Product product)
    {
        //verificar se ja existe, se sim aumenta a quantidade
        if(productsToSupply.checkForProduct(product.getName()))
        {
            productsToSupply.increaseQuantity(product.getQuantity(), product.getName());
            return;
        }
        //se nao existe adiciona
        productsToSupply.add(product);
    }

    public Position getPosition()
    {
        return position;
    }

    public void showInfo()
    {
        System.out.println(toString());
    }

    public String toString()
    {
        String temp = "-------[Estacao de distribuicao]--------\n";
        temp += "Nome: " + name + "\n" + position.toString() +  "\n[Armazem]\n" + productsToSupply.toString();
        temp += "\n----------------------------------------";
        return temp;
    }
}
