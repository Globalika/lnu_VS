function [res] = lagrange (v_x, v_y)
  n = length(v_x);
  L = zeros(n,n);
  for i = 1:n
    p = 1;
    for j = 1:n
      if i!=j
        p = conv(p, poly(v_x(j))/(v_x(i)-v_x(j)));
      endif
    endfor
    L(i,:) = p*v_y(i);
  endfor
  L;
  res = sum(L);
endfunction