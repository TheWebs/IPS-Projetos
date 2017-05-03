
import java.util.ArrayList;

/**
* Esta classe representa um mecanismo de distribuicao automatico.
* @author Francisco Leal e Hugo Ferreira
* @version 2.0
*/
public class ProductSupplyMechanism
{
    private Truck truck;
    private DistributionStation distributionStation;
    private Store store;
    private ArrayList<Product> products;
    private boolean comeBack;

    public ProductSupplyMechanism(Truck truck, DistributionStation distributionStation, Store store, boolean comeBack, ArrayList<Product> products)
    {
        if(truck != null)
        {
            this.truck = truck;
        }
        else
        {
            System.out.println("O camiao fornecido nao e valido!");
            return;
        }
        if(distributionStation != null)
        {
            this.distributionStation = distributionStation;
        }
        else
        {
            System.out.println("A estacao de distribuicao fornecida nao e valida!");
            return;
        }
        if(store != null)
        {
            this.store = store;
        }
        else
        {
            System.out.println("A loja fornecida nao e valida!");
            return;
        }
        if(products != null)
        {
            this.products = products;
        }
        else
        {
            System.out.println("A lista de produtos fornecida nao e valida!");
            return;
        }
        this.comeBack = comeBack;

    }

    public void iniciateRoute()
    {
        //  vai ate a estacao de distribuicao (caso nao esteja ja la) e carrega o camiao com os produtos
        if(!truck.getPosition().isEqual(distributionStation.getPosition()))
        {
            truck.moveTruck(distributionStation.getPosition());
        }
        distributionStation.loadContainer(products, 69876);
        for(int i = 0; i<distributionStation.getContainers().size();i++)
        {
            if(distributionStation.getContainers().get(i).getNumber() == 69876)
            {
                distributionStation.loadTruck(truck, distributionStation.getContainers().get(i));
            }
        }

        //vai ate a loja e descarrega os produtos
        truck.moveTruck(store.getPosition());
        store.unloadTruck(truck);

        //verifica se o camiao deve voltar ou nao e atua de acordo
        if(comeBack == true)
        {
            truck.moveTruck(distributionStation.getPosition());
        }

    }

}