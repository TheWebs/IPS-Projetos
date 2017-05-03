
import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;

/**
* Esta classe representa uma lista que contem todos os produtos em circulacao.
* @author Francisco Leal e Hugo Ferreira
* @version 2.0
*/

public class ProductsInMarket
{
    private HashMap<String, Product> list;
    
    public ProductsInMarket()
    {
        list = new HashMap<String, Product>();
    }
    
    public void addProduct(Product product)
    {
        if(!list.containsKey(product.getName().toLowerCase()))
        {
            list.put(product.getName().toLowerCase(), product);
        }
    }
    
    public void getAllComercializedProducts()
    {
        System.out.println("Produtos:");
        list.forEach((k,v) -> System.out.println("  - " + v.getName()));
    }
}