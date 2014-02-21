//need rewrite
#include <cstdio>

int stk[3][251], top[3], m;

void push(int i, int v){
   stk[i][top[i]++] = v;
}

int pop(int i){
   top[i]--;
   return stk[i][top[i]];
}

void toh(int n, int s, int t, int d){
    if (m == 0)
        return;
   if (n > 1 && m)
        toh(n - 1, s, d, t);  // move A to B
   push(d, pop(s));
   for (int i = 0; i < 3; i++)
   {
      printf ("%c=>", 'A' + i);
      if (top[i])
         printf ("  ");
      for (int j = 0; j < top[i]; j++)
         printf (" %d", stk[i][j]);
      printf ("\n");
   }
   printf ("\n");
    m--;
   if (n > 1 && m)
     toh(n - 1, t, s, d); // move B to C
}

int main()
{
   int n, tc = 1, i, j;

   while (scanf ("%d %d", &n, &m) == 2 && (n || m))
   {
      top[0] = top[1] = top[2] = 0;

      printf ("Problem #%d\n\n", tc++);

      for (i = n; i > 0; i--)
         push(0, i);

      for (i = 0; i < 3; i++)
      {
         printf ("%c=>", 'A' + i);
         if (top[i])
            printf ("  ");
         for (j = 0; j < top[i]; j++)
            printf (" %d", stk[i][j]);

         printf ("\n");
      }
      printf ("\n");

     toh(n, 0, 1, 2);

      while (m--)
      {
         for (i = 0; i < 3; i++)
         {
            printf ("%c=>", 'A' + i);
            if (top[i])
               printf ("  ");
            for (j = 0; j < top[i]; j++)
               printf (" %d", stk[i][j]);

            printf ("\n");
         }
         printf ("\n");
      }
   }
   return 0;
}
