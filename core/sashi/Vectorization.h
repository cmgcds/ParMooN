 
// ============================================================
// force the compiler to vectorize this loop 
//  !!! use only when there is no dependency in the data
 #pragma clang loop vectorize(assume_safety)
  for (int i = 0; i < count; i++)
      
      
 // force the compiler DISABLE vectorize this loop  
  #pragma clang loop vectorize(disable)
  for ( int i = 0; i < count; i++ )
// ============================================================
// Unrolling a scalar loop
for (int i = 0; i < 64; i++) {
  data[i] = input[i] * other[i];
}

by a factor of two, gives:

for (int i = 0; i < 32; i +=2) {
  data[i] = input[i] * other[i];
  data[i+1] = input[i+1] * other[i+1];
}
#pragma clang loop unroll(enable)

To unroll to a user-defined UF, instead insert:

#pragma clang loop unroll_count(_value_)      

#pragma clang loop unroll(enable)
for (int i = 0; i < 64; i++) {
  data[i] = input[i] * other[i];
}
// ============================================================

use < conditions rather than <= or != when constructing loops. This helps the compiler to prove that a loop terminates before the index variable wraps

