#include <iostream>
using namespace std;
class matrix{
	static const int maxc = 100,maxr = 100;
	int row,column;
	double a[maxr][maxc];
public:	
	matrix (double *a = nullptr ,int m = 0,int n = 0){
		row = m;
		column = n;
		for(int i = 0; i < row ;i++){
			for(int j = 0; j < column ;j++)
				this -> a[i][j] = *((a + i * column) + j);
		}
	}
	matrix (const matrix & b){
		copy(b);
	}
	matrix (double a){
		row = 1 ;
		column = 1 ;
		this  -> a[0][0] = a;
	}
	void copy (const matrix & b){
		row = b.row;
		column = b.column;
		for(int i = 0; i < row ;i++){
			for(int j = 0; j < column ;j++)
				this -> a[i][j] = b.a[i][j];
		}
	}
	int checksize (const matrix &b) const {
		int c = false;
		if(b.row == row && b.column == column)
			c = true ;
		return c;	
	 }
	 void setsize (const matrix &b){
		 int n,m;
		 m = row;
		 n = column;
		 if(row < b.row)
			row = b.row;
		 if(column < b.column)	
			column = b.column;
		for(int i = 0 ;i < row;i++){
			for(int j = n;j < column ;j++)
				a[i][j] = 0;
		}
		for(int j = 0 ;j < column ; j++){
			for (int i = m; i < row ;i++)
				a[i][j] = 0;
		}
	}
	matrix& operator = (const matrix &b){
          copy (b);
          return *this;
	}
	matrix operator += (const matrix &b){
		matrix d(b);
		bool c = checksize(d);
		if(c){
			for(int i = 0;i < row;i++){
				for( int j = 0;j < column;j++)
					a[i][j] += d.a[i][j];
		     }
		}
		else{
			setsize(d);
			c = checksize(d);
			if(c){
				for(int i = 0;i < row;i++){
					for( int j = 0;j < column;j++)
						a[i][j] += d.a[i][j];
				}
			}
			else{
				d.setsize(*this);
					for(int i = 0;i < row;i++){
						for( int j = 0;j < column;j++)
							a[i][j] += d.a[i][j];
					}
				}
			}
		return *this;	
	}
	matrix operator -= (const matrix &b){
		matrix d(b);
		bool c = checksize(d);
		if(c){
			for(int i = 0;i < row;i++){
				for( int j = 0;j < column;j++)
					a[i][j] -= d.a[i][j];
		     }
		}
		else{
			setsize(d);
			c = checksize(d);
			if(c){
				for(int i = 0;i < row;i++){
					for( int j = 0;j < column;j++)
						a[i][j] -= d.a[i][j];
				}
			}
			else{
				d.setsize(*this);
					for(int i = 0;i < row;i++){
						for( int j = 0;j < column;j++)
							a[i][j] -= d.a[i][j];
					}
				}
			}
		return *this;	
	}
	matrix operator *= (const matrix &b){
		matrix c;
		matrix d(b);
		int n,i,j,s;
		if(column < d.row){
			n = column;
			column = d.row;
			for(j = n;j < d.row  ;j++){
				for(i = 0;i < row ;i++)
					a[i][j] = 0;
			}
		}
		else if(column > d.row){
			n = d.row;
			d.row = column;
			for(i = n;i < column  ;i++){
				for(j = 0;j < d.column ;j++)
					d.a[i][j] = 0;
			}
		}
		c = *this;
		column = d.column;
		*this-=*this;
		for(i = 0;i < row;i++){
			for(s = 0; s < column;s++){
				for(j = 0;j < c.column;j++)
					a[i][s] += c.a[i][j] * d.a[j][s];
			}
		}
		return *this;
	}
	matrix operator ++(void){
		for(int i = 0 ;i < row;i++){
			for(int j = 0 ;j < column;j++)
				a[i][j]++;
		}
		return *this;
	}
	matrix operator ++(int){
		matrix b(*this);
		for(int i = 0 ;i < row;i++){
			for(int j = 0 ;j < column;j++)
				a[i][j]++;
		}
		return b;
	}	
	matrix operator --(void){
		for(int i = 0 ;i < row;i++){
			for(int j = 0 ;j < column;j++)
				a[i][j]--;
		}
		return *this;
	}
	matrix operator --(int){
		matrix b(*this);
		for(int i = 0 ;i < row;i++){
			for(int j = 0 ;j < column;j++)
				a[i][j]--;
		}
		return b;
	}
	friend istream& operator>>(istream& in, matrix& k);
    friend ostream& operator <<(ostream& out,const matrix& k); 
    friend matrix operator +(const matrix& k,const matrix& j);
	friend matrix operator -(const matrix& k,const matrix& j);
	friend matrix operator *(const matrix& y,const matrix& x);
	friend	bool  operator ==(const matrix& a,const matrix& b);
	friend	bool  operator !=(const matrix& a,const matrix& b);	
	friend  bool operator !(const matrix& a);
};
istream& operator>>(istream& in, matrix& k);
ostream& operator <<(ostream& out,const matrix& k); 
matrix operator +(const matrix& k,const matrix& j);
matrix operator -(const matrix& k,const matrix& j);
matrix operator *(const matrix& y,const matrix& x);
bool  operator ==(const matrix& a,const matrix& b);
bool  operator !=(const matrix& a,const matrix& b);
bool operator !(const matrix& a);	
void f1 (void);
int main(int argc, char **argv)
{ 
	f1();
	return 0;
}
istream& operator >> (istream& in, matrix& k){
	static int matrixnumber = 1 ;
	cout << "matrix number : " << matrixnumber << endl;
	matrixnumber ++; 
	cout << "Enter number of row :" << endl;
	in >> k.row;
	cout << "Enter number of column :" << endl;
	in >> k.column;
	while( k.row < 0 && k.column < 0 && k.row > 100 && k.column > 100){
		cout << "The numbers you've been entered is invalid .It must be between 0 and 100. "<<endl;
		cout << "Enter number of row :" << endl;
		in >> k.row;
		cout << "Enter number of column :" << endl;
		in >> k.column;
	}
	for (int i = 0 ;i < k.row ;i++){
		for (int j = 0 ; j < k.column ;j++){
			cout << "a[" << i << "][" << j << "] :" <<endl;
			in >> k.a[i][j];
		}
	}
	return in;
}
ostream& operator <<(ostream& out,const matrix& k){
	out << "The number of rows : " << k.row << endl;
	out << "The number of columns : " <<k.column << endl ;
	for (int i = 0 ;i < k.row ;i++){
		for (int j = 0 ; j < k.column ;j++){
			out << "a[" << i << "][" << j << "] : " << k.a[i][j] <<"		";
		}
		out << endl ;
	}
	return out;
}
matrix operator +(const matrix& k,const matrix& j){
	matrix a(k);
	matrix b(j);
	matrix d;
	bool c = a.checksize(b);
	if(c){
		d.row = a.row;
		d.column = a.column;
		for(int i = 0;i < d.row;i++){
			for( int j = 0;j < d.column;j++)
				d.a[i][j] = a.a[i][j] + b.a[i][j];
		    }
	}
	else{
		a.setsize(b);
		c = a.checksize(b);
		if(c){
			d.row = a.row;
			d.column = a.column;
			for(int i = 0;i < d.row;i++){
				for( int j = 0;j < d.column;j++)
					d.a[i][j] = a.a[i][j] + b.a[i][j];
			}
		}
		else{
			b.setsize(a);
			d.row = a.row;
			d.column = a.column;
			for(int i = 0;i < d.row;i++){
				for( int j = 0;j < d.column;j++)
					d.a[i][j] = a.a[i][j] + b.a[i][j];
			}
		}
	}
	return d;	
}
matrix operator -(const matrix& k,const matrix& j){
	matrix a(k);
	matrix b(j);
	matrix d;
	bool c = a.checksize(b);
	if(c){
		d.row = a.row;
		d.column = a.column;
		for(int i = 0;i < d.row;i++){
			for( int j = 0;j < d.column;j++)
				d.a[i][j] = a.a[i][j] - b.a[i][j];
		}
	}
	else{
		a.setsize(b);
		c = a.checksize(b);
		if(c){
			d.row = a.row;
			d.column = a.column;
			for(int i = 0;i < d.row;i++){
				for( int j = 0;j < d.column;j++)
					d.a[i][j] = a.a[i][j] - b.a[i][j];
			}
		}
		else{
			b.setsize(a);
			d.row = a.row;
			d.column = a.column;
			for(int i = 0;i < d.row;i++){
				for( int j = 0;j < d.column;j++)
					d.a[i][j] = a.a[i][j] - b.a[i][j];
			}
		}
	}
	return d;	
}
matrix operator *(const matrix& y,const matrix& x){
	matrix a;
	matrix c(y);
	matrix d(x);
	int n,i,j,s;
	if(c.column < d.row){
			n = c.column;
			c.column = d.row;
			for(j = n;j < d.row  ;j++){
				for(i = 0;i < c.row ;i++)
					c.a[i][j] = 0;
			}
		}
		else if(c.column > d.row){
			n = d.row;
			d.row = c.column;
			for(i = n;i < c.column  ;i++){
				for(j = 0;j < d.column ;j++)
					d.a[i][j] = 0;
			}
		}
		a = c;
		c.column = d.column;
		c-=c;
		for(i = 0;i < c.row;i++){
			for(s = 0;s < c.column;s++){
				for(j = 0;j < a.column;j++)
					c.a[i][s] += a.a[i][j] * d.a[j][s];
			}
		}
		return c;
}
bool  operator ==(const matrix& a,const matrix& b){
	bool c = false ;
	int i,j;
	if(a.row == b.row && a.column == b.column){
		for(i = 0;i < a.row ;i++){
			for (j = 0;j < a.column ;j++){
				if(a.a[i][j] != b.a[i][j])
					break;
			}
			if( j < a.column )
				break;
		}
		if(i == a.row )
			c=true;
	}	
	return c;
}		
bool operator !=(const matrix& a,const matrix& b){
	bool c ;
	c = a==b;
	return !c;
}
bool operator !(const matrix& a){
	bool c = false ;
	int i,j;
	if( !a.column){
		if( !a.row)
			c = true;
	}
	else{
		for( i = 0;i < a.row	; i++){
			for( j = 0; j < a.column ;j++){
				if(a.a[i][j] != 0)
					break;
			}		
			if( j < a.column )
				break;
		}
		if(i == a.row )
			c = true;
	}		
	return c;
}		
void f1 (void){
	matrix a,b,c,d,e,f,g,h,i;
	cin >> b;
	cin >> c;
	a = c + b;
	cout << "a" << endl <<a;
	e = a++;
	f = ++a;
	g = --a;
	i*= c;
	cout << "i" << endl << i;
	cout << "e" << endl << e;
	cout << "f" << endl << f;
	cout << "g" << endl <<g;
	f = b;
	if( g != e)
		cout<<"They are not equal."<<endl;
	if( f == b)
		cout<<"They are equal."<<endl;
	 d = b * c ; 
	 cout << "d" << endl <<d;
	 f = d - g;
	 if(!h)
		cout << "matrix h is empty." << endl;
}
