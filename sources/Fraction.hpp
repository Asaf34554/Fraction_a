#pragma once
#include <iostream>


namespace ariel{
    class Fraction
    {
    private:
        int _numerator,_denominator;


    public:
    //constructors
        Fraction():
            _numerator(0),_denominator(1){}

        Fraction(int ,int );
        Fraction(float );
        // Fraction(const Fraction& other) {
        //     _numerator = other._numerator;
        //     _denominator = other._denominator;
        // }

    //destructor
        // ~Fraction();

    //methods
        int getNumerator() const{
            return _numerator;
        }

        int getDenominator() const{
            return _denominator;
        }
   
    //operators
        static float fraction_to_float(const Fraction&);
        Fraction operator + (const Fraction& ) const;
        friend Fraction operator + (float, const Fraction& );
        friend Fraction operator + (const Fraction& , float );
        
        Fraction operator - (const Fraction& ) const;
        friend Fraction operator - (float , const Fraction& );
        friend Fraction operator - (const Fraction& , float );

        Fraction operator * (const Fraction& ) const;
        friend Fraction operator * (float , const Fraction& );
        friend Fraction operator * (const Fraction& , float );
        
        Fraction operator / (const Fraction& ) const;
        friend Fraction operator / (float , const Fraction& );
        friend Fraction operator / (const Fraction& , float );

        
        bool operator == (const Fraction& )const;
        friend bool operator == (float ,const Fraction& );
        friend bool operator == (const Fraction& ,float );

        bool operator > (const Fraction& )const;
        friend bool operator > (float ,const Fraction& );
        friend bool operator > (const Fraction& ,float );

        bool operator < (const Fraction& )const;
        friend bool operator < (float ,const Fraction& );
        friend bool operator < (const Fraction& ,float );

        bool operator >= (const Fraction& )const;
        friend bool operator >= (float num1,const Fraction& );
        friend bool operator >= (const Fraction& ,float );


        bool operator <= (const Fraction& )const;
        friend bool operator <= (float ,const Fraction& );
        friend bool operator <= (const Fraction& ,float );


        Fraction& operator ++ (){
            _numerator += _denominator;
            return *this;
        }
        Fraction operator ++ (int flag_to_overload){
            Fraction copy = *this;
            _numerator += _denominator;
            return copy;
        }
        Fraction& operator -- (){
            _numerator -= _denominator;
            return *this;
        }
        Fraction operator -- (int flag_to_overload){
            Fraction copy = *this;
            _numerator -= _denominator;
            return copy;
        }
        
        friend std::ostream& operator << (std::ostream& , const Fraction& );
        // friend ostream& operator << ( const Fraction& f,ostream output);
        
        friend std::istream& operator >> (std::istream& ,Fraction& ); 
        // friend ostream& operator >> ( const Fraction& f,ostream output);

     };  
};

