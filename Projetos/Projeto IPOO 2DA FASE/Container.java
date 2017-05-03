/**
* Esta classe representa um contentor.
* @author Francisco Leal e Hugo Ferreira
* @version 2.0
*/
public class Container
{
    private boolean isOnTruck;
    private double maxCargo;
    private double maxVolume;
    private int number;
    private double volumeLeft;
    private double cargoLeft;
    private int maxDifferentProducts;
    private Product[] productsList;

    public Container(boolean onTruck, int newNumber)
    {
        isOnTruck = onTruck;
        number = newNumber;
        maxCargo = 22000; //em Kg
        cargoLeft = 22000;
        volumeLeft = 33;
        maxVolume = 33; //em m3
        productsList = new Product[10];
        maxDifferentProducts = 10;
    }
    
    public Container() 
    {
        isOnTruck = false;
        number = 123;
        maxCargo = 22000; //em Kg
        cargoLeft = 22000;
        volumeLeft = 33;
        maxVolume = 33; //em m3
        productsList = new Product[10];
        maxDifferentProducts = 10;
    }

    
    public void loadProduct(Product product) 
    {
        boolean available = false;
        for(int i = 0; i<productsList.length;i++)
        {
            if(productsList[i] == null)
            {
                available = true;
                break;
            }
        }
        if(available == false) 
        {
            //ja nao da mais
            System.out.println("O numero maximo de de produtos foi atingido! (10)");
            return;
        }
        else
        {
            if(getUsedCargo()+ (product.getWeight()*product.getQuantity()) > maxCargo)
            {
                //peso excedido
                double overflow = (getUsedCargo()+(product.getWeight()*product.getQuantity()))-maxCargo;
                System.out.println("Peso maximo excedido por " + overflow + "Kg");
                System.out.println(getUsedCargo());
                return;
            }
            else 
            {
                if(getUsedVolume() + ((product.getVolume()/1000000)*product.getQuantity()) > maxVolume)
                {
                    //volume excedido
                    double overflow = (getUsedVolume() + ((product.getVolume()/1000000)*product.getQuantity())) - maxVolume;
                    System.out.println("Volume maximo excedido por " + overflow + " centimetros cubicos");
                    return;
                }
                else 
                {
                    for(int i = 0; i<productsList.length;i++)
                    {
                        if(productsList[i] != null) 
                        {
                            if(productsList[i].getName().equals(product.getName()))
                            {
                                productsList[i].increaseQuantity(product.getQuantity());
                                cargoLeft -= product.getQuantity()*product.getWeight();
                                volumeLeft -= product.getQuantity()*(product.getVolume()/1000000);
                                return;
                            }
                        }
                    }
                    for(int i = 0; i<productsList.length;i++)
                    {
                        if(productsList[i] == null)
                        {
                            productsList[i] = product;
                            cargoLeft -= product.getQuantity()*product.getWeight();
                            volumeLeft -= product.getQuantity()*(product.getVolume()/1000000);
                            break;
                        }
                    }
                }
            }

        }
    }

    public void unloadProduct(String name, int quantity)
    {
        if(isOnTruck == true)
        {
            //nao se pode descarregar
            System.out.println("Nao e possivel descarregar produtos enquanto o contentor estiver no camiao!");
        }
        else
        {
            if(name.equals(null) || quantity <= 0){
                System.out.println("O nome fornecido nao pode ser nulo e a quantidade tem que ser maior que 0!");
            }
            else
            {
            for(int i = 0; i< productsList.length; i++)
            {
                if(productsList[i] != null) {
                    if(productsList[i].getName().equals(name))
                    {
                        if(quantity > productsList[i].getQuantity()){
                            /* CODIGO ANTIGO QUE SERVIA PARA RETIRAR A QUANTIDADE DISPONIVEL QUANDO A PEDIDA SUPERAVA A MESMA
                             * productsList[i].decreaseQuantity(productsList[i].getQuantity());
                             * cargoLeft += productsList[i].getQuantity()*productsList[i].getWeight();
                             * volumeLeft += productsList[i].getQuantity()*(productsList[i].getVolume()/1000000);*/
                             System.out.println("So existem " + productsList[i].getQuantity() + " unidades desse produto");
                        }
                        else {
                            productsList[i].decreaseQuantity(quantity);
                            cargoLeft += productsList[i].getQuantity()*productsList[i].getWeight();
                            volumeLeft += productsList[i].getQuantity()*(productsList[i].getVolume()/1000000);
                        }
                        if(productsList[i].getQuantity() == 0)
                        {
                            productsList[i] = null;
                        }
                    }
                }
            }
        }
        }
    }

    public Product[] getProducts()
    {
        return productsList;
    }

    public double getVolumeLeft()
    {
        return volumeLeft;
    }

    public double getCargoLeft()
    {
        return cargoLeft;
    }

    public double getUsedVolume() 
    {
        return (maxVolume - volumeLeft);
    }

    public double getUsedCargo() 
    {
        return (maxCargo - cargoLeft);
    }

    public int getNumber()
    {
        return number;
    }

    public void showInfo()
    {
        System.out.println("- Informacao do contentor -");
        System.out.println("Numero: " + number);
        System.out.println("Peso por usar: " + getCargoLeft());
        System.out.println("Peso usado: " + getUsedCargo());
        System.out.println("Volume por usar: " + getVolumeLeft());
        System.out.println("Volume usado: " + getUsedVolume());
        System.out.println("Produtos:");
        int temp = 0;
        for(int i = 0; i<productsList.length; i++)
        {
            if (productsList[i] != null)
            {
                System.out.println("    - " + productsList[i].getName() + " [" + productsList[i].getQuantity() + "]");
            }
            else
            {
                temp++;
            }
        }
        System.out.println("Lugares vazios: " + temp);
        System.out.println("----------------------------");
    }
    
    public String toString()
    {
        String temp = "- Informacao do contentor -\nNumero: " + number + "\nPeso por usar: " + getCargoLeft() + "\nPeso usado: " + getUsedCargo() + "\nVolume por usar: " + getVolumeLeft() + "\nVolume usado: " + getUsedVolume() + "\nProdutos:";
            for(int i = 0; i<productsList.length; i++)
            {
                if(productsList[i] != null)
                {
                    temp += "   -" + productsList[i].getName() + " [" + productsList[i].getQuantity() + "]\n";
                }
            }
            temp += "Lugares vazios: " + temp + "\n----------------------------";
            return temp;
    }
    
}
