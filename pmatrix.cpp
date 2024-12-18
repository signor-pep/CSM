#include"./pmatrix.hpp"
int main(void)
{
  std::cout<<"Programmino per mostrare i metodi della classe pmatrix!\n\n";
  std::cout<<"Posso definire un oggetto pmatrix con la seguente sintassi:\npmatrixq<type,#>\ncon type --> tipo di variabile contenute nella matrice e # numero di righe (uguale al numero di colonne perché la matrice è quadrata)\n";
  std::cout<<"Noi definiamo tre matrici A , B e C con typr = double e # = 3. Il costruttore le inizializzerà come matrici nulle.\n";
  pmatrixq<double,3> A , B , C;

  std::cout << "Per stampare una matrice si usa la seguente sintassi std::cout<<\" A = \" << A << \"\\n\"\n";
  std::cout << "A = " << A << "\n";
  std::cout << "Posso inizializzare una matrice con la seguente sintassi A = {1.,2.,3.,4.,5.6.,7.,8.,9.}. Inizializzo A , B e C.\n";
  A = {1.,2.,3.,4.,5.,6.,7.,8.,9.};
  B = {1.,1.,1.,1.,1.,1.,1.,1.,1.};
  C = {2.,2.,2.,2.,2.,2.,2.,2.,2.};
  std::cout << "A = " << A << "  |  B = " << B << "  |  C = " << C << "\n";
  std::cout << "\nCon il metodo A(i,j) posso prendere l'elemento i-j della matrice --> se i = 1 e j = 2 --> A(1,2) = " << A(1,2) << "\n";
  A(1,2) = 0;
  std::cout << "Posso anche impostare un valore differente con lo stesso metodo --> A(1,2) = "<< A(1,2) << "\n";
  std::cout << "Posso sommare due matrici con la sintassi A = B + C ---> ";
  A = B + C;
  std::cout << "A = " << A <<"\n";
  std::cout << "Posso sottrarre due matrici con la sintassi A = B - C ---> ";
  A = B - C;
  std::cout << "A = " << A <<"\n";
  std::cout << "N.B. Posso usare anche gli operatori += e -=\n";
  std::cout << "Posso moltiplicare per uno scalare con le seguenti sintassi A = C * 0.5 o A = 0.5 * C --->";
  A = 0.5 * C;
  std::cout << "A = " << A <<"\n";
  std::cout << "Posso dividere per uno scalare con la seguente sintassi A = C / 2 --->";
  A = C / 2;
  std::cout << "A = " << A <<"\n";
  std::cout << "N.B. Posso usare anche gli operatori *= e /=\n";
  std::cout << "Ridefinisco le matrici A e B -->";
  A = {3.,0.,0.,0.,2.,0.,0.,0.,1.};
  B = {1.,2.,3.,0.,0.,0.,0.,0.,0.};
  std::cout << " A = " << A << "  |  B = " << B << "\n";
  C = A * B ;
  std::cout << "Posso fare il prodotto tra matrici con la seguente sintassi C = A * B --> C = " << C << "\n";
  std::cout << "Posso fare la trasposta col metodo C.transpose() -->  " << (C.transpose()) << "\n";
  std::cout << "Posso comparare due matrici con A == A --> " << (A == A) << " e A == B --> " << (A == B) << "\n";
  std::cout << "\nPosso moltiplicare vettori e matrici, quindi mi definisco un vettore v e ridefinisco la matrice A.\n";
  pvector<double, 3> v = {1.,2.,3.} , w;
  A = {1.,2.,0.,0.,0.,0.,0.,0.,1.};
  std::cout << "A = " << A << "  |  v = " << v << "\n";
  std::cout << "Posso usar quindi la sintassi w = A * v --> ";
  w = A * v;
  std::cout << "w = " << w << "\n";
  std::cout << "Posso scrivere anche w = v * A --> ";
  w = v * A;
  std::cout << "w = " << w << "\n";
  std::cout << "N.B. (w = A * v) != (w = v * A) \n";
  return 0;
}
