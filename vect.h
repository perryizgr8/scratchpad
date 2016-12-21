//Header for a vector class

class Vect
{
public:
	Vect();
	Vect(int64_t a, int64_t b);
	~Vect();
	double magnitude();
	Vect operator+(Vect a);

private:
	int64_t x;
	int64_t y;

};

Vect::Vect(int64_t a, int64_t b)
{
	x = a;
	y = b;
}

Vect::Vect()
{
}

Vect::~Vect()
{
}

double Vect::magnitude()
{
	double temp = pow(x, 2) + pow(y, 2);
	temp = sqrt(temp);
	return temp;
}

Vect Vect::operator+(Vect a)
{
	Vect sum(0,0);
	sum.x = this->x + a.x;
	sum.y = this->y + a.y;
	return sum;
}