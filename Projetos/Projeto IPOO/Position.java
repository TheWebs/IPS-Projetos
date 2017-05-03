
public class Position
{
    private double latitude;
    private double longitude;
    
    public Position(double newLatitude, double newLongitude) {
        if(checkCoordinates( newLatitude, newLongitude )) {
            latitude = newLatitude;
            longitude = newLongitude;
        }
    }
    
    public Position()
    {
        latitude = 1;
        longitude = 1;
    }
    
    //Nao e necessario verificar estes argumentos pois vao ser sempre obtidos de uma instancia da
    //classe Position e ja ocorre uma verificacao no construtor da mesma!
    //ex: position.getKilometersTo(newPosition.getLatitude(), newPosition.getLongitude());
    public double getKilometersTo( double newLatitude, double newLongitude ) {
       double kilometers = 0;
       double x1 = latitude*111.12;
       double y1 = longitude*111.12;
       double x2 = newLatitude*111.12;
       double y2 = newLongitude*111.12;
       kilometers = Math.sqrt((Math.pow((x1 - x2), 2))+(Math.pow((y1 - y2), 2)));
       return kilometers;
    }
    
    public boolean checkCoordinates(double newLatitude, double newLongitude)
    {
        if(newLatitude < -90 || newLatitude> 90) {
            //latitude invalida
            System.out.println("Latitude invalida, tem de estar entre -90 e 90.");
            return false;
        }
        else {
            if(newLongitude < -180 || newLongitude > 180) {
                //longitude invalida
                System.out.println("Longitude invalida, tem de estar entre -180 e 180.");
                return false;
            }
            else {
                return true;
            }        
        }
    }
    
    public boolean isEqual(Position newPosition)
    {
        if(latitude == newPosition.getLatitude() && longitude == newPosition.getLongitude())
        return true;
        else
        return false;
    }
    
    public double getLatitude() {
        return latitude;
    }
    
    public double getLongitude() {
        return longitude;
    }
    
    public String getLatitudeNorteSul()
    {
        if(latitude > 0)
        {
            return " Norte";
        }
        else
        {
            return " Sul";
        }
    }
    
        public String getLongitudeNorteSul()
    {
        if(longitude > 0)
        {
            return " Este";
        }
        else
        {
            return " Oeste";
        }
    }
    
    public void showInfo()
    {
        System.out.println(toString());
    }
    
    public String toString()
    {
        String temp = "";
        temp += "Posicao: " + latitude + getLatitudeNorteSul() + "; " + longitude + getLongitudeNorteSul();
        return temp;
    }
}