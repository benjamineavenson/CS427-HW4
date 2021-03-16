long long int modExp(long long int a, long long int b, long long int n){
  long long int val = 1;
  for(long long int i = 1; i <= b; i++){
    val = (val*a)%n;
  }
  return val;
}
