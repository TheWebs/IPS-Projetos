public class DistributionStation
{
    private String name;
    private Position position;
    private Product[] productsToSupply;
    private Container[] availableContainers;
    private int usedContainers;
    private int maxContainers;

    public DistributionStation(String newName, Position newPosition, Product[] newProductsToSupply, int numberOfContainers)
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
            productsToSupply = new Product[50];
        }
        else 
        {
            productsToSupply = newProductsToSupply;
        }
        if(numberOfContainers < 1) 
        {
            numberOfContainers = 1;
        }
        availableContainers = new Container[numberOfContainers];
        usedContainers = 0;
        maxContainers = numberOfContainers;
    }
    
    public DistributionStation()
    {
        name = "Desconhecido";
        position = new Position(1, 1);
        productsToSupply = new Product[50];
        availableContainers = new Container[1];
        usedContainers = 0;
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

    public void loadContainer(Product[] products, int containerNumber)
    {
        if(products == null)
        { 
            System.out.println("Lista de produtos invalida!)");
            return;
        } 
        if(usedContainers == maxContainers)
        {
            System.out.println("Ja nao ha contentores disponiveis nesta estacao!");
            return;
        } 
        
        availableContainers[availableContainers.length-(usedContainers + 1)] = new Container(false, containerNumber);
        /**
        Vai fazer um loop dentro de uma lista de produtos e verificar se estão no armazém. Se estiverem e a quantidade existente for 
        menor do que a desejada vai adicionar todos os produtos diponiveis. Seguidamente define a quantidade existente de produtos 
        para a quantidade de produtos disponiveis menos as que foram carregadas para o contentor. Posteriormente diminui a quantidade
        de contentores diponiveis
        **/
        for(int i = 0; i<products.length; i++) 
        {
            for(int a = 0; a < productsToSupply.length; a++) 
            {
                if(products[i].getName().equals(productsToSupply[a].getName())) 
                {
                    if(products[i].getQuantity() > productsToSupply[a].getQuantity())
                    { /*CODIGO ANTIGO: servia para se pedissem mais quantidade que a disponivel no armazem, apenas era creditada a disponivel eram avisados
                        System.out.println("A quantidade requesitada (" + products[i].getQuantity() + ") de " + products[i].getName() + " e maior que a quantidade disponivel (" + productsToSupply[a].getQuantity() + "). Sera carregada a quantidade disponivel!");
                        products[i].setQuantity(productsToSupply[a].getQuantity());
                        availableContainers[availableContainers.length-(usedContainers + 1)].loadProduct(products[i]);
                        break;
                        */
                       System.out.println("A quantidade requesitada (" + products[i].getQuantity() + ") de " + products[i].getName() + " e maior que a quantidade disponivel (" + productsToSupply[a].getQuantity() + "). Este produto nao sera carregado!");
                       break;
                    }
                    else 
                    {
                        availableContainers[availableContainers.length-(usedContainers + 1)].loadProduct(products[i]);
                        productsToSupply[i].decreaseQuantity(products[i].getQuantity());//wbedikwcbwiudcwud
                        usedContainers++;
                        break;
                    }
                }
                else 
                {
                    if(a+1 == productsToSupply.length) 
                    {
                        System.out.println("Produto " + products[i].getName() + " nao encontrado no armazem!");
                    }
                }
            }
        } 
    }

    public void receiveProducts(Product product)
    {
        //verificar se ja existe, se sim aumenta a quantidade
        for(int i = 0; i<productsToSupply.length; i++)
        {
            if(productsToSupply[i].getName().equals(product.getName())) 
            {
                productsToSupply[i].increaseQuantity(product.getQuantity());
                return;
            }
        }
        //se nao existe adiciona
        for(int i = 0; i < productsToSupply.length; i++)
        {
            if(productsToSupply[i] == null) //primeiro espaco vazio encontrado
            {
               productsToSupply[i] = product; 
               break;
            }
        }
        
        
    }
    
    public void showInfo()
    {
        System.out.println(toString());
    }
    
    public String toString()
    {
        String temp = "-------[Estacao de distribuicao]--------\n";
        int temp1 = 0;
        temp += "Nome: " + name + "\n" + position.toString() +  "\n[Armazem]\n" + "Produtos:\n";
        for(int i = 0;i<productsToSupply.length;i++)
        {
            if(productsToSupply[i] != null)
            {
                temp += "   -" + productsToSupply[i].getName() + " [" + productsToSupply[i].getQuantity() + "]\n";
            }
            else
            {
                temp1++;
            }
        }
        temp += "Espacos vazios: " + temp1 + "\n----------------------------------------";
        return temp;
    }
}
