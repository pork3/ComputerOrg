//function call : compiler cannot do away with function calls
//pointer alias : 
int* a ;
int* b;

b =a ;
b[i] = 6 //this implies a[i] = 6
//biggest issue with c, b and a are aliases 
//these are why they may not be
  
//perspective/logical detour 
// rather than if x true else x false

if x!=0{
	x =0
} // replaced by x=0


//be replaced by x=!x


///////// inlining ////////
//inline just execute the body in the exact place in code where call occurs
