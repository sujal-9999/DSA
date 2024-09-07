#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define ld long double
#include <iomanip>
#include <fstream>


class Vector{
    public:
        ld x , y;

        Vector() : x(0),y(0){}
        Vector(ld a , ld b) : x(a), y(b){}
        //Vector(const Vector& a) : x(a.x) , y(a.y){}


        static Vector add(const Vector& a  , const Vector& b){
            return Vector(a.x + b.x , a.y + b.y);
        }

        static Vector subtract(const Vector& a , const Vector& b){
            return Vector(b.x - a.x , b.y - a.y);
        }
        
        static Vector mid(const Vector& a  , const Vector& b){
            return Vector( (a.x + b.x)/2 , (a.y + b.y)/2);
        }

        static Vector Rotate(const Vector& a){ 
            return Vector(a.y , -a.x);
        }

        static Vector ARotate(const Vector& a){
            return Vector(-a.y , a.x);
        }

        static ld distance(const Vector& a ,const Vector& b ){
            return sqrt(pow(a.x - b.x , 2) + pow(a.y - b.y , 2));
        }

        static Vector scalar(const Vector& a , ld scalar){
            return Vector(a.x * scalar , a.y * scalar);
        }

        static ld length(const Vector& a){
            return sqrt(pow(a.x,2) + pow(a.y , 2));
        }

        static Vector unit(const Vector& a ){
            ld factor = sqrt(pow(a.x , 2) + pow(a.y , 2));
            return scalar( a , 1/factor);
        }

        static void vector_print(const Vector& a){
            cout<<"( "<<a.x<<" , "<<a.y<<")"<<endl;
        }

        static double dot_p(const Vector& a , const Vector& b){
            return a.x*b.x + a.y*b.y;
        }

        static double cross_p(const Vector& a , const Vector& b){
            return a.x*b.y - a.y*b.x;
        }

        static bool point_on_seg(const Vector& point , const Vector& a , const Vector& b){
            if(distance(point , a) + distance(point , b) == distance(a , b))
                return true;
            return false;
        }

        static bool intersect(const Vector& a , const Vector& b , const Vector& c , const Vector& d){
            if(point_on_seg(a , c ,d) || point_on_seg(b , c , d) || point_on_seg(c , a , b) || point_on_seg(d , a , b))
                return true;

            ld x = cross_p(subtract(a , b) , subtract(a , c));
            ld y = cross_p(subtract(a , b) , subtract(a , d));
            if( (x >= 0 && y >= 0 ) || (x <= 0 && y <= 0) ){
                return false;
            }

            x = cross_p(subtract(c , d ) , subtract(c , a));
            y = cross_p(subtract(c , d) , subtract(c , b));
            if( (x >= 0 && y >= 0 ) || (x <= 0 && y <= 0) ){
                return false;
            }

            return true;
        }

        static Vector intersect_point(const Vector& a ,const Vector& b ,const Vector& c , const Vector& d){
            ld A1 = a.x*b.y - a.y*b.x;
            ld A2 = c.x*d.y - c.y*d.x;
            ld p  = a.x - b.x;
            ld q = c.y - d.y;
            ld r = a.y - b.y;
            ld s = c.x - d.x;
            ld denom = p*q - r*s;
            Vector t;
            t.x = (A1*s - p*A2)/denom;
            t.y = (A1*q - r*A2)/denom;
            return t;
        }


};

class Pyramid{
public:
    Vector origin;
    ld height;
    ld slant_height;
    Vector vertex[4];
    Vector origins[4];
    Pyramid(const Vector& a , const Vector& b , ld h ){
        
        height = h;

        Vector mid = Vector::mid(a , b);
        Vector perpendicular = Vector::ARotate(Vector::mid(Vector::subtract(a , b) , Vector(0,0)));
        origin = Vector::add(mid , perpendicular);

        Vector dir = Vector::subtract(origin , a);
        vertex[0] = a;
        for(int i = 1; i <= 3 ; i++){
            dir = Vector::ARotate(dir);
            vertex[i] = Vector::add(origin , dir);
        }

        ld len = Vector::distance(a , b);
        ld a_h = sqrt(pow(len, 2)/4 + pow(h , 2)) - len/2;
        slant_height = sqrt(pow(len , 2)/2 + pow(h , 2));

        Vector a_dir = Vector::scalar(Vector::unit(perpendicular) , a_h);

        for(int i = 0 ;i < 4 ; i++){
            origins[i] = Vector::add(origin , a_dir);
            a_dir = Vector::ARotate(a_dir);
        }
    }

    static void print(const Pyramid& A){

        cout<<A.height<<endl;
        cout<<"origin --> ";
        Vector::vector_print(A.origin);

        for(int i = 0 ;i < 4 ; i++){

            cout<<"Point "<<i+1<<" :";
            Vector::vector_print(A.vertex[i]);

        }

        for(int i = 0 ;i < 4 ; i++){

            cout<<"Point "<<i+1<<" :";
            Vector::vector_print(A.origins[i]);

        }
    }

};

#define V Vector
class Solution{
public:
    static bool intersect_triplet(V o1 , V a , V b , V o2 , V c , V d){
        if(!( V::intersect(o1 , o2 , a , b ) && V::intersect(o1 , o2 , c , d))){
            return false;
        }
        double dis1 = V::distance(Vector::intersect_point(o1 ,o2 ,  a , b ) , o1);
        double dis2 = V::distance(Vector::intersect_point(o1 ,o2 ,  c , d ) , o1);
        if(dis1 <= dis2)return true;
        return false;
    }
    static ld optimum_path(V o1 , V a , V b , V o2 , V c , V d){
        if(intersect_triplet(o1, a , b , o2 , c , d)){

            return V::distance(o1 , o2);
        }
        ld ans = 1000000;
        if(V::intersect(o1 , c , a , b))
            ans = min(ans , V::distance(o1 , c) + V::distance(c , o2));
        if(V::intersect(o1 , d , a , b))
            ans = min(ans , V::distance(o1 , d) + V::distance(d , o2));
        ans = min(ans , V::distance(o1 , b) + V::distance(b , d ) + V::distance(d , o2));
        ans = min(ans , V::distance(o1 , a) + V::distance(a , c ) + V::distance(c , o2));

        return ans;
    }
    static ld shortest_path(Pyramid A , Pyramid B){
        ld ans = INT_MAX;
        for(int i = 0 ; i< 4 ; i++){
            Vector o1 = A.origins[i];
            Vector a = A.vertex[i];
            Vector b = A.vertex[(i+1)%4];
            for(int j = 0 ; j < 4 ; j++){
                Vector o2 = B.origins[j];
                Vector c = B.vertex[j];
                Vector d = B.vertex[(j+1)%4];
                ld temp = min(optimum_path(o1 , a , b , o2 , c , d) , optimum_path(o2 , d, c , o1 , a , b));
                ans = min(ans , temp );
            }
        }
        return ans;
    }

    // static void execute(){
    //     ld x11 , y11 , x12 , y12 , h1;
    //     ld x21 , y21 , x22 , y22 , h2;
        
    //     cin>>x11>>y11>>x12>>y12>>h1;
    //     cin>>x21>>y21>>x22>>y22>>h2;
    //     Vector a(x11 , y11) , b(x12 , y12);
    //     Vector c(x21 , y21), d( x22 , y22);
    //     Pyramid A(a , b , h1);
    //     Pyramid B(c , d , h2);
    //     //Pyramid::print(A);
    //     //Pyramid::print(B);
    //     cout << fixed << setprecision(13);
    //     cout<<shortest_path(A , B)<<endl;
    //     //Vector e = Vector::intersect_point(a , b , c , d);
    //     //cout<<e.x<<" "<<e.y<<endl;
    // }
    static void execute(const string& file) {
        ifstream infile(file); // Replace "input.txt" with your actual file name
        if (!infile) {
            cerr << "File could not be opened!" << endl;
            return;
        }

        ld x11, y11, x12, y12, h1;
        ld x21, y21, x22, y22, h2;
        
        infile >> x11 >> y11 >> x12 >> y12 >> h1;
        infile >> x21 >> y21 >> x22 >> y22 >> h2;

        Vector a(x11, y11), b(x12, y12);
        Vector c(x21, y21), d(x22, y22);

        Pyramid A(a, b, h1);
        Pyramid B(c, d, h2);

        cout << fixed << setprecision(13);
        cout << shortest_path(A, B) << endl;

        infile.close();
    }

    
};

