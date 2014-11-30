// 分別代表錢幣幣值，數量 (如果有限)
int val[3]={2,4,5}, ,num[3]={2,1,3};

// 無限換錢 – 能否湊成某價位
memset(dp,false,sizeof(dp));
dp[0]=true;
// 每種錢幣都試試看
for(i=0;i<3;++i){
  // 每種幣值都試試看
  for(j=val[i];j<=100;++j)
    dp[j]|=dp[j-val[i]];
}

// 無限換錢 – 湊成某價位有幾種
memset(dp,0,sizeof(dp));
dp[0]=1;

// 每種錢幣都試試看
for(i=0;i<3;++i){
// 每種幣值都試試看
  for(j=val[i];j<=100;++j)
    dp[j]+=dp[j-val[i]];
}

// 無限換錢 – 湊成某價位最少要幾個硬幣
dp[0]=0;
for(i=1;i<=100;++i) dp[i]=INF;
// 每種錢幣都試試看
for(i=0;i<3;++i)
{
  // 每種幣值都試試看
  for(j=val[i];j<=100;++j)
    dp[j]=min(dp[j],dp[j-val[i]]+1);
 }

// 無限換錢 – 湊成某價位可以用幾個硬幣 (Bit Mask)
memset(dp,0,sizeof(dp));
// 每種錢幣都試試看
for(i=0;i<3;++i)
{
// 必可以用1個構成(該錢幣本身)
  dp[val[i]]|=1;
		
// 每種幣值都試試看
  for(j=val[i];j<=100;++j)
    dp[j]|=(dp[j-val[i]]<<1);
}
// ex: 6塊是否可以由3個硬幣構成?
if(dp[6]&(1<<(3-1))) printf("Yes\n");
else printf("No");

// 有限換錢 –能否湊成某價位
memset(dp,false,(total+1)*sizeof(bool));
dp[0]=true;
for(i=0;i<n;i++){
  memset(used,0,(total+1)*sizeof(int));
  for(j=val[i];j<=total;j++){
    if(!dp[j]&&dp[j-val[i]]&&used[j-val[i]]<num[i]){
      dp[j]=true;
      used[j]=used[j-val[i]]+1;
    }
  }
}


// 有限換錢 – 湊成某價位有幾種
memset(dp,0,(total+1)*sizeof(int));
dp[0]=1;

// 嘗試每一種錢幣
for(i=0;i<n;++i){
  // 由後往前嘗試每一種存在的幣值
  for(j=total-val[i];j>=0;--j){
    // 如果該幣值已可構成才需要更新
    if(dp[j]){
      // 由後往前嘗試不同數量
      for(k=num[i];k>0;--k)
      {
        // 超出要求的範圍
        if(j+k*val[i]>total) continue;
        dp[j+k*vak[i]]+=dp[j];
      }
    }
  }
}

// 有限換錢 – 湊成某價位最少要幾個硬幣
dp[0]=0;
for(i=1;i<=100;++i) dp[i]=INF;
// 每種錢幣都試試看
for(i=0;i<3;++i){
  // 跑num[i]次
  for(k=0;k<num[i];++k){
    // 每種幣值都試試看
    for(j=100;j>=val[i];--j)
      dp[j]=min(dp[j],dp[j-val[i]]+1);
  }
}

// 有限換錢 – 湊成某價位可以用幾個硬幣 (Bit Mask) [DP陣列用long long]
memset(dp,0,sizeof(dp));
// 每種錢幣都試試看
for(i=0;i<3;++i){
  // 跑num[i]次
  for(k=0;k<num[i];++k){
    // 每種幣值都試試看
    for(j=100;j>=val[i];--j)
      dp[j]|=(dp[j-val[i]]<<1LL);
    // 必定可以用1個構成(該幣值本身)
    dp[val[i]]|=1LL;
  }
}
