function [res] = newton(v_x,v_y)
  n = length(v_x);
  D = zeros(n,n);
  D(:,1) = v_y;
  for k = 2:n #columns
    for j = 1:n-k+1 #rows
      D(j,k) = (D(j+1,k-1)-D(j,k-1))/(v_x(j+k-1)-v_x(j));
    endfor
  endfor
  M = zeros(n,n);
  D(1,:);
  for i = 1:n
    p = 1;
    for j = 1:i-1
      p = conv(p, poly(v_x(j)));
    endfor
    M(i,:) = [zeros(1,n-i),p]*D(1,i);
  endfor
  res = sum(M);
endfunction