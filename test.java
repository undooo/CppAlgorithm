package Assignment3;
import java.awt.Point;
public class Circle {
    //Initialize variables
    private double radius;
    private Point center;
    Circle(){this(1.0);}

    Circle(int x,int y,double r){
        this(r);
        center.move(x,y);
    }
    Circle(double r){
        radius=r;
        center=new Point();
    }
    Circle(int x,int y){
        this(1);
        center.move(x,y);
    }
    Circle(Point p){
        this(1);
        center=p;
    }
    Circle(Point p, double r){
        this(r);
        center=p;
    }
    public double getRadius(){
        return radius;
    }
    public void setRadius(double r){
        radius=r;
    }
    public Point getCenter(){
        return center;
    }
    public void move(int x,int y ){
        center.move(x,y);
    }

}
