// Programme réalisant une boucle de lecture écriture sans autre intérêt que d'expérimenter dans le terminal
#include <iostream>

using namespace std;

int main(){
  int nb_tours = 10000;
  int val;
  
  for (int i = 0; i <nb_tours; i=i+1){
  
     cin >> val;
     cout << val * 2 << "\n";
  }
}
