
import java.util.ArrayList;

/**
* Esta classe representa um armazem de produtos.
* @author Francisco Leal e Hugo Ferreira
* @version 2.0
*/

public class Storage
{
    private int capacity;
    private ArrayList<Product> products;
    
    public Storage(int capacity, ArrayList<Product> products)
    {
        if(capacity <= 0)
        {
            System.out.println("A capacidade do armazem deve ser superior a 0!");
        }
        else
        {
            this.capacity = capacity;
        }
        if(products != null)
        {
            if(products.size() > capacity)
            { 
                System.out.println("O numero de produtos nao pode ser superior a capacidade maxima!");
            }
            else
            {
                this.products = products;
            }
        }
        else
        {
            System.out.println("A lista de produtos nao pode ser nula!");
        }
    }
    
    public Storage(int capacity)
    {
      if(capacity <= 0)
        {
            System.out.println("A capacidade do armazem deve ser superior a 0!");
        }
        else
        {
            this.capacity = capacity;
        }   
    }
    
    public Storage()
    {
        capacity = 100;
    }
    
    public void loadInicialProducts(ArrayList<Product> lista)
    {
        for(int i = 0; i<lista.size(); i++)
        {
            if(lista.get(i) != null)
            {
                products.add(lista.get(i));
            }
        }
    }
    
    public boolean removeProduct(String name, int quantity)
    {
        if(name != null)
        {
            if(quantity > 0)
            {
                if(checkForProduct(name))
                {
                    for(int i = 0; i<products.size();i++)
                    {
                        if(name.equals(products.get(i).getName()))
                        {
                            if(products.get(i).getQuantity() < quantity)
                            {
                                System.out.println("A quantidade requesitada nao se encontra disponivel, apenas existem " + products.get(i).getQuantity() + " unidades!");
                                return false;
                            }
                            else
                            {
                                if(products.get(i).getQuantity() == quantity)
                                {
                                    products.remove(i);
                                    return true;
                                }
                                else
                                {
                                    products.get(i).decreaseQuantity(quantity);
                                    return true;
                                }
                            }
                        }
                    }
                }
                else
                {
                    System.out.println("O produto nao foi encontrado no armazem!");
                    return false;
                }
            }
            else
            {
                System.out.println("A quantidade indicada nao e valida!");
                return false;
            }
        }
        else
        {
            System.out.println("O nome fornecido nao e valido!");
            return false;
        }
        return false;
    }
    
    public int checkForProductIndex(String name)
    {
        int temp = 0;
        if(name == null)
        {
            System.out.println("Nome fornecido nao e valido!");
            return -1;
        }
        for(int i = 0; i<products.size();i++)
        {
            if(products.get(i).getName().equals(name))
            {
                temp = i;
            }
        }
        return temp;
    }
    
    public void increaseQuantity(int quantity, String name)
    {
        if(name != null)
        {
            products.get(checkForProductIndex(name)).increaseQuantity(quantity);
        }
        else
        {
            System.out.println("O nome fornecido nao e valido!");
        }
    }
    
    public void add(Product produto)
    {
        products.add(produto);
    }
    
    public boolean checkForProduct(String name)
    {
        if(name == null)
        {
            System.out.println("Nome fornecido nao e valido!");
            return false;
        }
        boolean found = false;
        for(int i = 0; i<products.size();i++)
        {
            if(products.get(i).getName().equals(name))
            {
                found = true;
            }
        }
        return found;
    }
    
    public String toString()
    {
     String temp = "Produtos:\n";
     for(int i = 0;i<products.size();i++)
        {
                temp += "   -" + products.get(i).getName() + " [" + products.get(i).getQuantity() + "]\n";
        }
     return temp;
    }
}