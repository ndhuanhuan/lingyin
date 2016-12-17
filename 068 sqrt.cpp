double sqrt(double x)
{
  if(x==0) return 0;
  double last = 0.0;
  double res =1.0;
  while(abs(res-last)>0.0001)
  {
    last = res;
    res =(res+x/res)/2;
  }
  return res;
}
