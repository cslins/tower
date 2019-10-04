#include <stdio.h> 
int c = 0, n = 3;

void troca(int origem , int destino, int matriz[20][3]){ // troca o numero na coluna(torre) origem para a coluna destino
  for(int i = 19; c == 0 && i >= 0; i--){
          for(int j = 0; c == 0 && j < 20; j++){
            if(matriz[i][destino]==0 && matriz[j][origem]!=0){ //checa se o destino está vazio e se a origem tem algum número
              matriz[i][destino] = matriz[j][origem]; //o local de destino recebe o número que está na origem
              matriz[j][origem] = 0;// origem recebe zero
              c = 1;} // c é uma variavel checadora, ela indica se a troca foi feita;
          }
        }
    c = 0;
  return;
}
void mostrar(int matriz[20][3]){ //só imprime a matriz

   for(int x = 0; x < 20; x++){
    printf("\n");
    for(int y = 0; y < 3; y++){
      printf("%4d", matriz[x][y]);
    }
  }
  printf("\n");
  
}
void towerOfHanoi(int n, int origem, int dest, int aux, int matriz[20][3]) //algoritmo que define como a torre de hanoi é resolvida de acordo com o número de discos
{   
    
    if (n == 1) 
    {   
        troca(origem, dest, matriz);
        mostrar(matriz);
        return; 
    } 
    towerOfHanoi(n-1, origem, aux, dest, matriz);
    troca(origem, dest, matriz);
    mostrar(matriz); 
    towerOfHanoi(n-1, aux, dest, origem, matriz); 
} 

int main() 
{ int num_aneis;
  
  scanf("%d", &n);
  num_aneis = n;
    int mat[20][3], i , j;

    for( i = 19; i >= 0 ; i--){// construção da matriz inicial(aquela com discos somente na primeira coluna)
      for( j = 0; j < 3; j++){
        if(j == 0 && num_aneis != 0){// se for a primeira coluna e se o num_aneis != 0, o local na matriz receberá um número que corresponde ao tamanho do seu disco
          mat[i][j] = num_aneis--;
        }else{
          mat[i][j] = 0;
        }}}
    
    mostrar(mat);
    towerOfHanoi(n, 0, 2, 1, mat);
    return 0; 
} 
