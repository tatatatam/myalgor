var m =5;
var n =5;
var t=0;
var result;
var bool = true;
  if(m<n){
    t=m;
  }else{
    t=n;
  }
    while(bool){
      if((m%t)==0){
        if((n%t)==0){
          bool = false;
          result = t;
        }else{
          t--;
        }
      }else{
        t--;
      }
      console.log(m+"--"+n);
    }

console.log(result);
