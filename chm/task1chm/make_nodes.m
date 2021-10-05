function [res] = make_nodes(choose = 1, a, b, n)
    if(choose == 1)
      res = make_nodes_1 (a, b, n);
    else
      res = make_nodes_2 (a, b, n);
    endif
endfunction

function [res] = make_nodes_1 (a, b, n)
  res = [a];
  h = abs((b-a)/n);
  for i = 0:n-1
    a = a+h;
    res = [res, a];
  endfor
endfunction

function [res] = make_nodes_2 (a, b, n)
  res = [];
  for k = 0:n
    res = [res, (a+b)/2 + ((b-a)/2)*cos((2*k+1)/(2*(n+1))*pi)];
  endfor
  res = flip(res);
endfunction