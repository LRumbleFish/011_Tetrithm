#define TETRITHM_MULTIPLE_OF_3_GAME
#undef TETRITHM_BINARY_SEARCH
#undef TETRITHM_QUICK_SORT
#undef TETRITHM_SORT

#if defined (TETRITHM_MULTIPLE_OF_3_GAME)
#include <stdio.h>

int main()
{
  int num;
  scanf("%d",&num);
  for(int i=1; i<=num ; i++)
    ((i%3)==0) ? printf("X "): printf("%d ",i);
  return 0;
}

#endif // TETRITHM_MULTIPLE_OF_3_GAME

#if defined (TETRITHM_BINARY_SEARCH)
#include <stdio.h>

int S[100], n ,k;

int find(int s, int e)
{
  while(s<=e)
  {
    int m=(s+e)/2;
    if(S[m]==k) return m;
    if(S[m]>k) e=m-1;
    else s=m+1;
  }
  return -1;
}

int main()
{
  scanf("%d%d",&n,&k);
  for(int i=0; i<n; i++)
    scanf("%d",&S[i]);
  printf("%d\n",find(0,n-1));
  return 0;
}
#endif // TETRITHM_BINARY_SEARCH

#if defined (TETRITHM_QUICK_SORT)
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <algorithm>

int n, S[100000];

void print_array()
{
  for (int i=0; i<n; i++)
    printf("%d",S[i]);
  printf("\n");
}

void swap(int a, int b)
{
  int t = S[a];
  S[a]=S[b];
  S[b]=t;
}

void quick_sort(int s, int e)
{
  if(s<e)
  {
    int p=s, l=s+1, r=e;
    while(l<=r)
    {
      while(l<=e && S[l]<=S[p]) l++;
      while(r>=s+1 && S[r]>=S[p]) r--;
      if(l<r) swap(l,r);
    }
    swap(p,r);
    quick_sort(s,r-1);
    quick_sort(r+1,e);
  }
}

int main()
{
  srand(time(NULL));
  scanf("%d",&n);
  for(int i=0; i<n; i++)
    S[i] = rand();
  int start = clock();

  //selection_sort();
  //std::sort(S,S+n);
  quick_sort(0,n-1);
  printf("result =%.3lf(sec)\n",(double)(clock()-start)/CLOCKS_PER_SEC);
  return 0;
}
#endif // TETRITHM_QUICK_SORT

#if defined (TETRITHM_SORT)
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <algorithm>

int n, S[100000];

void print_array()
{
  for (int i=0; i<n; i++)
    printf("%d",S[i]);
  printf("\n");
}

void swap(int a, int b)
{
  int t=S[a];
  S[a] = S[b];
  S[b] = t;
}

void selection_sort(void)
{
  for(int i=0; i<n-1; i++)
    for(int j=i+1; j<n; j++)
      if(S[i]>S[j])
        swap(i,j);
}

int main()
{
  srand(time(NULL));
  scanf("%d",&n);
  for(int i=0; i<n; i++)
    S[i] = rand();
  int start = clock();

  //selection_sort();
  std::sort(S,S+n);
  printf("result =%.3lf(sec)\n",(double)(clock()-start)/CLOCKS_PER_SEC);
  return 0;
}
#endif
