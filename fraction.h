namespace chipmunk {
    //Fraction class
    class Fraction
    {
    int numerator, denominator;
    public:
        //initiate with num and denom
        Fraction(int num, int denom);
        //add another fraction
        chipmunk::Fraction  add(chipmunk::Fraction other);
        //substract another fraciton
        chipmunk::Fraction  sub(chipmunk::Fraction other);
        chipmunk::Fraction  mult(chipmunk::Fraction other);
        chipmunk::Fraction  div(chipmunk::Fraction other);
        //return double value
        double getValue();
        //return num and denom
        int getNum();
        int getDenom();
    private:
        void simplify();
    };

}
