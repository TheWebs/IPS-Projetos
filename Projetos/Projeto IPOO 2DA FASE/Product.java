/**
* Esta classe representa o Produto.
* @author Francisco Leal e Hugo Ferreira
* @version 2.0
*/

public class Product
{
    private int code;
    private String name;
    private int quantity;
    private double weight;
    private double volume;
    
    public Product(int code, String name, int quantity, double weight, double volume, ProductsInMarket list) {
        if(list == null)
        {
            System.out.println("Lista invalida, a abortar ...");
            return;
        }
        if(quantity < 0) 
        {
            quantity = 1;
        }
        else 
        {
            this.quantity = quantity;
        }
        if(weight < 0) 
        {
            weight = 0;
        }
        else 
        {
            this.weight = weight;
        }
        if(volume < 0)
        {
            volume = 0;
        }
        else
        {
            this.volume = volume;
        }
        if(name.equals(null)) 
        {
            this.name = "Desconhecido";
        }
        else 
        {
            this.name = name;
        }
        if(code < 0) 
        {
            this.code = 0;
        }
        else
        {
            this.code = code;
        }  
        
        list.addProduct(this);
    }
    
    public Product(ProductsInMarket list)
    {
        if(list == null)
        {
            System.out.println("Lista invalida, a abortar ...");
            return;
        }
        code = 123;
        name = "Desconhecido";
        quantity = 10;
        weight = 1;
        volume = 1;
        list.addProduct(this);
    }
    
    public String getName() 
    {
        return name;
    }
    
    public int getQuantity() 
    {
        return quantity;
    }
    
    public void setQuantity(int value)
    {
        quantity = value;
    }
    
    public void decreaseQuantity(int amount) 
    {
        quantity -= amount;
    }
    
    public void increaseQuantity(int amount)
    {
        quantity += amount;
    }
    
    public double getWeight() 
    {
        return weight;
    } 
    
    public double getVolume() 
    {
        return volume;
    }
    
    public int getCode()
    {
        return code;
    }
    
    public String toString()
    {
        return "-----Produto----\nNome: " + name + "\nCodigo: " + code + "\nQuantidade: " + quantity + "\nPeso: " + weight + "\nVolume: " + volume + "\n---------------";
    }
    
    public void showInfo()
    {
        System.out.println(toString());
    }
}
