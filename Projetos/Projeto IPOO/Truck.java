public class Truck
{
    private String name;
    private int number;
    private Container container;
    private Position position;
    private double totalKilometers;
    private int inspections;
    private double kilometersSinceInspection;
      
    public Truck(String newName, int newNumber, Container newContainer, Position newPosition) {
        if(newName.equals(null)) 
        {
            name = "Desconhecido";
        }
        else 
        {
            name = newName;
        }
        if(newNumber < 0) 
        {
            number = 0;
        }
        else
        {
            number = newNumber;
        }
        if(newPosition == null) 
        {
            position = new Position(1, 1);
        }
        else 
        {
            position = newPosition;
        }
        if(newContainer == null) 
        {
            container = new Container(true, 123);
        }
        else 
        {
            container = newContainer;
        }
        totalKilometers = 0;
        inspections = 1;
        kilometersSinceInspection = 0;
    }
    
    public Truck()
    {
        name = "Desconhecido";
        number = 123;
        container = new Container(true, 123);
        position = new Position(1, 1);
    }
    
    public void moveTruck(Position newPosition)
    {
        if(newPosition != null) 
        {
           totalKilometers += position.getKilometersTo(newPosition.getLatitude(), newPosition.getLongitude());
           kilometersSinceInspection += position.getKilometersTo(newPosition.getLatitude(), newPosition.getLongitude());
           position = newPosition;
        }
        else 
        {
           System.out.println("Erro, a posicao fornecida nao pode ser nula!");
        }
    }
    public void loadTruck(Container newContainer) 
    {
        if(newContainer != null)
        {
            container = newContainer;
        }
        else 
        {
            System.out.println("Contentor inválido"); container = new Container(false, 0);
        }
    }
    public void unloadTruck() 
    {
        container = null;
    }
   
    public Container getContainer() 
    {
        return container;
    }
    
    public Position getPosition() 
    {
        return position;
    }
    
    public void inspect()
    {
        inspections++;
        kilometersSinceInspection = 0;
    }
    
    public String toString()
    {
        if(container == null)
        {
            return "----Camiao----\nNome: " + name + "\nNumero: " + number + "\nContentor: Nao existe\n" + position.toString() + "\nTotal de kilometros: " + totalKilometers + "\nInspecoes: " + inspections + "\nKilometros desde a ultima inspecao: " + kilometersSinceInspection + "\n--------------";
        }
        else
        {
            
            return "----Camiao----\nNome: " + name + "\nNumero: " + number + "\nContentor:\n" + container.toString() + "\n" + position.toString() + "\nTotal de kilometros: " + totalKilometers + "\nInspecoes: " + inspections + "\nKilometros desde a ultima inspecao: " + kilometersSinceInspection + "\n--------------";
        }
    }
    
    
}

