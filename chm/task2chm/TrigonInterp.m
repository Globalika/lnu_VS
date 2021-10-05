function [g_T] = TrigonInterp(v_y, t, n)
  v_a = zeros(1, n + 1);
  v_b = zeros(1, n + 1);
  # k = 0 : n
  for kk = 1:n + 1
    # j = 0 : 2*n - 1
    for jj = 1:2 * n
      v_a(kk) += v_y(jj) * cos( (pi * (jj-1) * (kk-1)) / n );
    endfor
    v_a(kk) = ( 1 / n ) * v_a(kk);
  endfor
  
  # k = 1 : n - 1
  for kk = 2:n
    # j = 0 : 2*n - 1
    for jj = 1:2 * n
      v_b(kk) += v_y(jj) * sin( (pi * (jj-1) * (kk-1)) / n );
    endfor
    v_b(kk) = ( 1 / n ) * v_b(kk);
  endfor
  
  sum = 0;
  for kk = 2:n
    sum += (v_a(kk) .* cos((kk-1) .* t)) + (v_b(kk) .* sin((kk-1) .* t));
  endfor
  
  g_T = ( v_a(1) / 2 ) + sum + ( v_a(end) / 2 ) * cos(n * t);
endfunction