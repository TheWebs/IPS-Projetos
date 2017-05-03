/**
* Esta classe representa uma garagem para os camioes.
* @author Francisco Leal e Hugo Ferreira
* @version 2.0
*/
public class Garage
{
    private String name;
    private Position position;
    private Spot[] parkingSpaces;
    
    public Garage(String newName, Position newPosition, int numberParkingSpaces)
    {
        if(newName.equals(null))
        {
            name = "Desconhecido";
        }
        else
        {
          name = newName;
        }
        if(newPosition != null)
        {
             position = newPosition;
        }
        else
        {
            position = new Position(1, 1);
        }
        if(numberParkingSpaces <= 0)
        {
            numberParkingSpaces = 20; //numero default escolhido por nos
        }
        parkingSpaces = new Spot[numberParkingSpaces];
        sortParkingSpaces();
    }
    
    public Garage()
    {
        name = "Desconhecido";
        position = new Position(1, 1);
        parkingSpaces = new Spot[20];
        sortParkingSpaces();
    }
    
    public void sortParkingSpaces() 
    {
            for(int i = 0; i < parkingSpaces.length;i++)
            {
                parkingSpaces[i] = new Spot(false, false);
                parkingSpaces[i].setNumber(i+1);
            }
    }
    
    public void showInfo(){
        System.out.println("-----Garagem-----");
        System.out.println("Nome: " + name);
        System.out.println(position.toString());
        for(int i = 0; i < parkingSpaces.length;i++) {
            System.out.println("[" + parkingSpaces[i].getNumber() + "] [Contentor = " + parkingSpaces[i].hasContainer() + "]" + " [Camiao = " + parkingSpaces[i].hasTruck() + "]" );
        }
        System.out.println("-----------------");
    }
       
    public void parkTruck(Truck truck, int number){
        if(number-1 < 0 || number-1 > parkingSpaces.length-1){
            System.out.println("Numero invalido, nao pode ser menor que 1 nem maior que " + parkingSpaces.length + ".");
        }
        else{
                if(parkingSpaces[number-1].hasTruck() || parkingSpaces[number-1].hasContainer()){
                    System.out.println("O lugar pretendido ja esta ocupado!");
                }
                else {
                  parkingSpaces[number-1].setHasTruck(true);
                  parkingSpaces[number-1].saveTruck(truck);
                }
        }
    }
    
    public void removeTruck(int number)
    {
        if(number-1 < 0 || number-1 > parkingSpaces.length-1){
            System.out.println("Numero invalido, nao pode ser menor que 1 nem maior que " + parkingSpaces.length + ".");
        }
        else
        {
            if(parkingSpaces[number-1].hasTruck()){
                System.out.println("Camiao estacionado no lugar " + number + " foi removido");
                parkingSpaces[number-1].setHasTruck(false);
                parkingSpaces[number-1].deleteTruck();
            }
            else
            {
                System.out.println("Nao existe nenhum camiao estacionado no lugar indicado!");
            }
        }   
    }

    public void inspectTruck(int number)
    {
        if(parkingSpaces[number-1].hasTruck()) {
            parkingSpaces[number - 1].inspect();
        }
        else
        {
            System.out.println("Nao existe camiao nesse lugar!");
        }
    }

    public void changeContainer(int spotNumber, Container newContainer)
    {
        if(spotNumber > 0 && spotNumber <= parkingSpaces.length)
        {
            if(parkingSpaces[spotNumber-1].hasTruck())
            {
                if(newContainer == null)
                {
                    parkingSpaces[spotNumber-1].deleteContainer();
                }
                else
                {
                    parkingSpaces[spotNumber-1].saveContainer(newContainer);
                }
            }
            else
            {
                System.out.println("Nao existe nenhum camiao nesse lugar, logo a troca nao pode ser efetuada.");
            }

        }
        else
        {
            System.out.println("Esse lugar nao existe! Apenas existem " + parkingSpaces.length + " lugares.");
        }
    }

    public void checkSpots()
    {
        for(int i = 0; i < parkingSpaces.length;i++)
        {
            if(parkingSpaces[i].hasTruck())
            {
                if(parkingSpaces[i].getTruck().getPosition().isEqual(position))
                {
                    System.out.println("O camiao estacionado no lugar [" + (i-1) + "] encontra se mesmo na garagem.");
                }
                else
                {
                    System.out.println("O camiao estacionado no lugar [" + (i-1) + "] nao esta mesmo na garagem.");
                }
            }
        }
    }
    
}

