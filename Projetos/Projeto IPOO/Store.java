public class Store
{
    private String name;
    private Position position;
    private Product[] productsStorage;
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
        productsStorage = new Product[50];
    }
    
    public Store()
    {
        name = "Desconhecido";
        position = new Position(1, 1);
        maxContainers = 2;
        currentContainers = 0;
        productsStorage = new Product[50];
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
                for(int a = 0; a<productsStorage.length; a++) 
                {
                    if(truck.getContainer().getProducts()[i].getName().equals(productsStorage[a].getName()))
                    {
                        productsStorage[a].increaseQuantity(truck.getContainer().getProducts()[i].getQuantity());
                        found = true;
                        break;
                    }
                    else 
                    {
                        found = false;
                    }
                   
                }
                if(found == false)
                {
                    for(int j = 0; j<productsStorage.length;j++)
                    {
                        if(productsStorage[j] == null) 
                        {
                            productsStorage[j] = truck.getContainer().getProducts()[i];
                            break;
                        }
                    }
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
        if(newName.equals(null))
        { 
            System.out.println("Nome do produto inválido"); 
            return;
        }
        if(newQuantity <= 0) 
        {
            System.out.println("Quantidade inválida"); 
            return; 
        }
        for(int i =0; i < productsStorage.length; i++) 
        {
            if(productsStorage[i].getName().equals(newName))
            {
                if(productsStorage[i].getQuantity()<newQuantity)
                {
                    System.out.println("A quantidade pedida é superior à existente");
                    return;
                }
                else
                {
                    productsStorage[i].decreaseQuantity(newQuantity);     
                }
            }
        }
    }
    
    public String toString()
    {
        String temp = "----Loja----\nNome: " + name + "\n" + position.toString() + "\nProdutos no armazem:\n";
        for(int i =0; i< productsStorage.length;i++)
        {
            temp += "   -" + productsStorage[i].getName() + " [" + productsStorage[i].getQuantity() + "]";
        }
        temp += "------------";
        return temp;
    }
    
    public void showInfo()
    {
        System.out.println(toString());
    }
}
