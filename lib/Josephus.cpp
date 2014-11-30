// 輸出: n人中每m人殺一人，最後剩下的人的id，0~n-1
int killer(int n,int m){
  if(n==1) return 0;
  return (killer(n-1,m)+m)%n;
}
// 若要1~n，輸出+1就好
// 若要每次殺不同個數，傳參數的m改掉，平移m不動
