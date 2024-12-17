#include "./pvector.hpp"
int main(void)
{
  pvector<double,3> A, B, C;
  double val=0;
  pvector<int,3> iv={1,2,3};

  std::cout << "L'idea di questo programmino è ricordati come funziona la classe pvector!\n" << std::endl;
  std::cout << "Puoi definire l'oggetto scrivendo:\npvector<tipo,NT> nome;\nnel programma definiamo A,B,C di tipo double e lunghezza NT 3"<< std::endl;
  std::cout << "Il costruttore inizializza gli array come vettori nulli" << std::endl;
  std::cout << "Il metodo show ti permette di stamparli!\nStampiamo il vettore A con la seguente sintassi A.show(\"A = \")\n";
  A.show("A = ");
  std::cout << "Se voglio modificare il valore di un elemenro di un array posso usare il metodo set con la seguente sintassi: A.set(#,K), dove # è l'elemento e K il valore che imposto.\n";
  A.set(0,1);
  A.show("A = ");
  std::cout << "Il metodo get ti permette di prendere un valore da un array, con la seguente sintassi val = A.get(#) (posso usar anche A(0) )\n";
  std::cout << "val = " << val << " ora uso get";
  val = A(0);
  std::cout << "--> val = " << val << "\n";
  std::cout << "Posso anche assegnare un intero vettore, con l'operatore =, sintassi B=A\n";
  B = A;
  B.show("B =");
  std::cout <<"Posso sommare due vettori, con l'operatore +, sintassi C = A + B\nN.B. puoi anche scrivere C = A.sum(B)\n";
  C = A.sum(B);
  C.show("C = ");
  std::cout <<"Posso usare l'operatore +=, sintassi C += B\n";
  C+=B;
  C.show("C = ");
  std::cout<<"Posso usare l'operatore -, sintassi C = A - B\n";
  C = A - B;
  C.show("C = ");
  std::cout<<"Posso usare l'operatore -=, sintassi C -= B\n";
  C -= B;
  C.show("C = ");
  std::cout<<"Posso inizializzare un vettore con la seguente sintassi A ={1.,2.,3.}. Inizializzo A,B,C e li stampo.\n";
  A={1.,2.,3.};
  B={0.,1.,0.};
  C={0.,0.,1.};
  A.show("A = ");
  B.show("B = ");
  C.show("C = ");
  std::cout<<"Posso fare la norma dei vettori con A.norm()\n";
  val = A.norm();
  std::cout<< "norm = " << val << "\n";
  std::cout<<"Posso fare il prodotto scalare con la sintassi val = A * C\n";
  val = A * C;
  std::cout << "Prodotto scalare --> val = " << val << "\n";
  std::cout << "Posso moltiplicare scalare e vettore, con le seguenti sintassi A = val * B o A = B * val (puoi usar anche  B *= val)\n";
  A = B * val;
  A.show("A = ");
  std::cout << "Posso dividere per uno scalare, sintassi A = B / val (puoi usar anche B /= val)\n";
  A = B / val;
  A.show("A = ");
  std::cout << "E' stato implementato l'operatore confronto ==, sintassi A == B\n A == A -->"<< (A==A) <<"   A == B --> "<< (A==B) << "\n";
  std::cout <<"\nInizializzo di nuovo i vettori\n";
  A = {1.,0.,0.};
  B = {0.,1.,0.};
  C = {0.,0.,0.};
  A.show("A = ");
  B.show("B = ");
  C.show("C = ");
  std::cout <<"Posso effettuare il prodotto vettoriale, sintassi  C = A ^ B\n";
  C = A ^ B;
  C.show("C = ");
  std::cout <<"\nInizializzo di nuovo i vettori\n";
  A = {1.2,2.3,3.4};
  B = {5.1,1.1,0.7};
  C = {1.,2.5,0.9};
  A.show("A = ");
  B.show("B = ");
  C.show("C = ");
  std::cout << "Posso farne il rint(), con la sintassi A = rint(A)\n";
  A = rint(A);
  B = rint(B);
  C = rint(C);
  A.show("A = ");
  B.show("B = ");
  C.show("C = ");
  std::cout <<"Posso fare la component-wise moltiplication, con la sintassi B = A.mulcw(C)\n";
  B = A.mulcw(C);
  B.show("B = ");

  std::cout <<"Posso fare la component-wise division, con la sintassi B = A.divcw(C)\n";
  B = A.divcw(C);
  B.show("B = ");

  std::cout <<"Posso generare un vettore con componenti comprese tra [-L/2 , L/2], con la sintassi B = B.random(L)    (per noi L =  " << val <<")\n";
  B = B.random(val);
  B.show("B = ");

  std::cout <<"Questi son più o meno tutti i metodi utili a completare il progetto scelto!\n";
  
  
  //B.rint();
  //C.rint();

  /*
  
  std::cout << "norm(iv)=" << iv.norm() << "\n";
  // seeding the Mersenne-Twister
  rng.rseed();
 
  vec1.show("vec1=");
  vec2.show("vec2=");
  vec3 = vec1+vec2;
  
  vec3.show("vec3=vec1+vec2=");

  // RETURN VALUE BY REFERENCE IN AN ASSIGNMENT OPERATOR
  // = operator returns object vec3 by reference,
  // hence method set will set first element of vec3 to -3
  (vec3=vec2).set(0,-3);
  vec3.show("vec3=");

  val = vec1(2);
  std::cout << "val=" << val << std::endl;

  char ival=3;
  
  vec3 = {ival,val,1};
  std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>> vec3=" << vec3 << std::endl;
  // CONST VECTOR WITH operator ()
  // if const operator() is not defined we will obtain
  // an error using operator () with const pvector 
  const pvector<double,3> vv={1.0,2.0,6.3};
  std::cout << "norm(vv)=" << vv.norm() << std::endl;
  vec3(0) = vv(1);
  vec3.show("vec3=");
  vec3 = 1.5*vec2;
  vec3.show(">>>>vec3=");
  
  // element-wise operations
  //
  std::cout << "vec3.mulcw(vec3)" << vec3.mulcw(vec3) << std::endl;
  std::cout << "vec3.divcw(vec3)" << vec3.divcw(vec3) << std::endl;

  // NARROWING
  int a=3;
  // if remove conversion to double of integer a, we get
  // an error here since int can not be "narrowed" to double.
  // This is a peculiar behavior of list initialization
  pvector<double,3> vec4={double(a)+0.3,1.5,22.5};

  vec4.random_orient();
  // overloading of << operator and use of rint
  std::cout << "vec4=" << vec4 <<  " norm(vec4)=" << vec4.norm() << std::endl;
  //
  std::cout << "rint(vec4)=" << rint(vec4) << std::endl;
  return 0;
*/
}
