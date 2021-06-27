#include<stdio.h>

void selection(int n, int v[]){
  for(int i = 0; i<n-1; i++){
    int posMenor = i;
    for(int j=i+1; j<n; j++)
      if(v[j]<v[posMenor])
        posMenor = j;
    int x = v[i];
    v[i] = v[posMenor];
    v[posMenor] = x;
  }
  for(int r=0;r<n;r++){
  	printf("%i ", v[r]);
  }
}

int main(){
  int v[10],i;
  printf("Digite os numeros do vetor: \n");
  for (i=0;i<10;i++){
    scanf("%i ", &v[i]);
  }
  selection(10, v);
}